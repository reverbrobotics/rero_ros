#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include <fstream>
#include <cstdint>

struct WavHeader {
    char chunkId[4] = {'R', 'I', 'F', 'F'};
    uint32_t chunkSize;
    char format[4] = {'W', 'A', 'V', 'E'};
    char subchunk1Id[4] = {'f', 'm', 't', ' '};
    uint32_t subchunk1Size = 16;
    uint16_t audioFormat = 1;
    uint16_t numChannels = 4; // Match launch file
    uint32_t sampleRate = 16000;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample = 16;
    char subchunk2Id[4] = {'d', 'a', 't', 'a'};
    uint32_t subchunk2Size;
};

class AudioSubscriberNode : public rclcpp::Node
{
public:
    AudioSubscriberNode() : Node("audio_subscriber")
    {

        out_file_.open("received_audio.wav", std::ios::binary);
        if (!out_file_.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to open output file");
            rclcpp::shutdown();
            return;
        }

        WavHeader header;
        header.blockAlign = header.numChannels * (header.bitsPerSample / 8);
        header.byteRate = header.sampleRate * header.blockAlign;
        header.subchunk2Size = 0; // Updated later
        header.chunkSize = 36 + header.subchunk2Size;
        writeWavHeader(header);

        auto qos = rclcpp::QoS(rclcpp::KeepLast(10)).reliable();
        subscription_ = this->create_subscription<std_msgs::msg::ByteMultiArray>(
            "/rero_ros/audio_stream", qos,
            std::bind(&AudioSubscriberNode::audioCallback, this, std::placeholders::_1));

        RCLCPP_INFO(this->get_logger(), "Subscribed to /rero_ros/audio_stream");
    }

    ~AudioSubscriberNode()
    {

        if (out_file_.is_open()) {
            WavHeader header;
            header.blockAlign = header.numChannels * (header.bitsPerSample / 8);
            header.byteRate = header.sampleRate * header.blockAlign;
            header.subchunk2Size = total_bytes_;
            header.chunkSize = 36 + header.subchunk2Size;
            out_file_.seekp(0);
            writeWavHeader(header);
            out_file_.close();
            RCLCPP_INFO(this->get_logger(), "Saved received audio to received_audio.wav");
        }
    }

private:
    void writeWavHeader(const WavHeader& header)
    {
        out_file_.write(header.chunkId, 4);
        out_file_.write(reinterpret_cast<const char*>(&header.chunkSize), 4);
        out_file_.write(header.format, 4);
        out_file_.write(header.subchunk1Id, 4);
        out_file_.write(reinterpret_cast<const char*>(&header.subchunk1Size), 4);
        out_file_.write(reinterpret_cast<const char*>(&header.audioFormat), 2);
        out_file_.write(reinterpret_cast<const char*>(&header.numChannels), 2);
        out_file_.write(reinterpret_cast<const char*>(&header.sampleRate), 4);
        out_file_.write(reinterpret_cast<const char*>(&header.byteRate), 4);
        out_file_.write(reinterpret_cast<const char*>(&header.blockAlign), 2);
        out_file_.write(reinterpret_cast<const char*>(&header.bitsPerSample), 2);
        out_file_.write(header.subchunk2Id, 4);
        out_file_.write(reinterpret_cast<const char*>(&header.subchunk2Size), 4);
    }

    void audioCallback(const std_msgs::msg::ByteMultiArray::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Received audio frame with %zu bytes", msg->data.size());
        out_file_.write(reinterpret_cast<const char*>(msg->data.data()), msg->data.size());
        total_bytes_ += msg->data.size();
    }

    std::ofstream out_file_;
    uint32_t total_bytes_ = 0;
    rclcpp::Subscription<std_msgs::msg::ByteMultiArray>::SharedPtr subscription_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AudioSubscriberNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}