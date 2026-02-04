#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include "std_msgs/msg/float32_multi_array.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/int32.hpp"

#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <string>

class ScanningBeamformer : public rclcpp::Node {
public:
  ScanningBeamformer() : Node("scanning_beamformer") {
    // Parameters
    declare_parameter<std::string>("audio_topic", "/rero_ros/audio_stream");
    declare_parameter<int>("sample_rate", 48000);
    declare_parameter<int>("num_channels", 4);
    declare_parameter<int>("bytes_per_sample", 2);
    declare_parameter<double>("frame_duration", 0.05); // 50 ms
    declare_parameter<double>("speed_of_sound", 343.0);
    declare_parameter<double>("ns_distance_m", 0.195); // N-S spacing (m)
    declare_parameter<double>("ew_distance_m", 0.197); // E-W spacing (m)

    audio_topic_ = get_parameter("audio_topic").as_string();
    fs_          = get_parameter("sample_rate").as_int();
    ch_          = get_parameter("num_channels").as_int();
    bps_         = get_parameter("bytes_per_sample").as_int();
    frame_dur_   = get_parameter("frame_duration").as_double();
    c_           = get_parameter("speed_of_sound").as_double();
    ns_dist_     = get_parameter("ns_distance_m").as_double();
    ew_dist_     = get_parameter("ew_distance_m").as_double();

    frame_size_ = std::max(256, (int)std::round(fs_ * frame_dur_));

    // 8 scan angles (deg), 2 around each cardinal (±15°)
    angles_deg_ = {345, 15, 75, 105, 165, 195, 255, 285};

    // Mic coordinates in robot plane: +Y = North, +X = East
    // Order must match channel order of audio_stream: N, S, E, W
    mic_pos_ = {
      std::array<double,2>{ 0.0,         +ns_dist_/2.0 }, // N
      std::array<double,2>{ 0.0,         -ns_dist_/2.0 }, // S
      std::array<double,2>{ +ew_dist_/2.0, 0.0          }, // E
      std::array<double,2>{ -ew_dist_/2.0, 0.0          }  // W
    };

    auto qos = rclcpp::QoS(rclcpp::KeepLast(10)).reliable();

    sub_ = create_subscription<std_msgs::msg::ByteMultiArray>(
      audio_topic_, qos,
      std::bind(&ScanningBeamformer::audioCb, this, std::placeholders::_1));

    pub_powers_ = create_publisher<std_msgs::msg::Float32MultiArray>("/scan/beam_powers", qos);
    pub_best_   = create_publisher<std_msgs::msg::Int32>("/scan/best_angle", qos);

    // Per-beam publishers: /scan/beam_1 ... /scan/beam_8
    for (size_t i = 0; i < angles_deg_.size(); ++i) {
      std::string topic = "/scan/beam_" + std::to_string(i + 1);
      auto p = create_publisher<std_msgs::msg::Float32>(topic, qos);
      beam_pubs_.push_back(p);
    }

    RCLCPP_INFO(get_logger(),
                "ScanningBeamformer started: fs=%d Hz, frame=%d, 8 beams around NESW",
                fs_, frame_size_);
  }

private:
  // Linear fractional-delay read: y[n] = x[n - d]
  inline double readDelayLinear(const std::vector<double>& x, double n_minus_d) {
    if (n_minus_d <= 1.0) return x[1];
    if (n_minus_d >= (double)x.size() - 2.0) return x[x.size() - 2];

    int i = (int)std::floor(n_minus_d);
    double frac = n_minus_d - i;
    double y0 = x[i];
    double y1 = x[i + 1];
    return (1.0 - frac) * y0 + frac * y1;
  }

  // Per-mic delays (in samples) for a steering angle (deg)
  std::array<double,4> delaysSamplesForAngle(double angle_deg) {
    double theta = angle_deg * M_PI / 180.0;
    // Beam look direction: +Y=North, +X=East → unit vector (ux, uy)
    double ux = std::sin(theta);
    double uy = std::cos(theta);

    std::array<double,4> d_samp{};
    for (int i = 0; i < 4; ++i) {
      double proj = mic_pos_[i][0] * ux + mic_pos_[i][1] * uy; // meters
      double tau  = proj / c_;                                  // seconds
      d_samp[i]   = tau * fs_;                                  // samples
    }
    return d_samp;
  }

  void audioCb(const std_msgs::msg::ByteMultiArray::SharedPtr msg) {
    // Interleaved int16: [N,S,E,W,N,S,E,W,...]
    const size_t total_samples = msg->data.size() / bps_;
    if (total_samples % ch_ != 0) return;

    const size_t N = total_samples / ch_;
    if ((int)N < frame_size_) return; // need at least one full frame

    // Extract last frame_size_ samples per channel, normalize to [-1,1]
    std::vector<std::vector<double>> X(ch_, std::vector<double>(frame_size_));
    const int16_t* raw = reinterpret_cast<const int16_t*>(msg->data.data());
    const size_t start = (N - frame_size_) * ch_;

    for (int n = 0; n < frame_size_; ++n) {
      for (int k = 0; k < ch_; ++k) {
        int16_t s = raw[start + n * ch_ + k];
        X[k][n] = (double)s / 32768.0;
      }
    }

    // Simple DC removal (light high-pass)
    for (int k = 0; k < ch_; ++k) {
      double mean = 0.0;
      for (double v : X[k]) mean += v;
      mean /= (double)frame_size_;
      for (double &v : X[k]) v -= mean;
    }

    // For each beam: delay-and-sum → RMS power
    std::vector<float> powers(angles_deg_.size(), 0.0f);

    for (size_t b = 0; b < angles_deg_.size(); ++b) {
      auto dSamp = delaysSamplesForAngle(angles_deg_[b]);

      double acc_pow = 0.0;
      for (int n = 1; n < frame_size_ - 1; ++n) {
        double y = 0.0;
        for (int k = 0; k < ch_; ++k) {
          double tap_index = (double)n - dSamp[k];
          y += readDelayLinear(X[k], tap_index);
        }
        y /= (double)ch_;
        acc_pow += y * y;
      }
      double rms = std::sqrt(acc_pow / (double)(frame_size_ - 2));
      powers[b] = (float)rms;
    }

    // Publish combined array
    std_msgs::msg::Float32MultiArray pmsg;
    pmsg.data = powers;
    pub_powers_->publish(pmsg);

    // Publish each beam separately
    for (size_t i = 0; i < powers.size() && i < beam_pubs_.size(); ++i) {
      std_msgs::msg::Float32 msg_f;
      msg_f.data = powers[i];
      beam_pubs_[i]->publish(msg_f);
    }

    // Pick and publish best angle
    size_t best_idx = std::distance(powers.begin(),
                        std::max_element(powers.begin(), powers.end()));
    int best_angle = (int)std::round(angles_deg_[best_idx]);

    std_msgs::msg::Int32 amsg;
    amsg.data = best_angle;
    pub_best_->publish(amsg);
  }

  // Params / state
  std::string audio_topic_;
  int fs_{48000}, ch_{4}, bps_{2}, frame_size_{0};
  double frame_dur_{0.05}, c_{343.0}, ns_dist_{0.195}, ew_dist_{0.197};

  // Beams + mic geometry
  std::array<int,8> angles_deg_;
  std::array<std::array<double,2>,4> mic_pos_;

  // ROS I/O
  rclcpp::Subscription<std_msgs::msg::ByteMultiArray>::SharedPtr sub_;
  rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr pub_powers_;
  rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr pub_best_;
  std::vector<rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr> beam_pubs_;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ScanningBeamformer>());
  rclcpp::shutdown();
  return 0;
}
