## Installation Instructions

### Download and Compile gRPC

First Install GRPC : https://grpc.io/docs/languages/cpp/quickstart/

### Colcon Build with gRPC

```bash
colcon build --symlink-install --cmake-args -DGRPC_FETCHCONTENT=OFF -DCMAKE_PREFIX_PATH=~/grpc_install
```

---

## Launching Packages

Make sure an instance of the `rero_server` is running, and that your launch files are correctly configured to point at the server.

### Audio Stream Publisher

Launch the node that streams audio data from the microphone array to ROS2:

```bash
ros2 launch rero_ros audio_stream.launch.xml
```

### Audio Stream Subscriber

Launch the node that subscribes to the audio stream and saves it to a `.wav` file:

```bash
ros2 launch rero_ros audio_subscriber.launch.xml
```

### Direction of Arrival (DOA)

Launch the node that estimates the angle of arrival of sound sources:

```bash
ros2 launch rero_ros doa.launch.xml
```

### Natural Language Understanding (NLU)

Launch the NLU node to process recognized speech into intents:

```bash
ros2 launch rero_ros nlu.launch.xml
```

### Speech Recognition

Launch the speech recognition node to convert audio to text:

```bash
ros2 launch rero_ros speech_recognition.launch.xml
```

### Text to Speech (TTS)

Launch the TTS node to convert text into spoken audio:

```bash
ros2 launch rero_ros text_to_speech.launch.xml
```

### Voice Activity Detection (VAD)

Launch the node that detects when speech is present in the audio stream:

```bash
ros2 launch rero_ros vad.launch.xml
```

---

## Testing NLU

First, in a new terminal, echo the NLU output topic (you will need to source your ROS workspace if it doesn’t automatically do this in your `.bashrc`):

```bash
ros2 topic echo /rero_ros/nlu_result
```

Then, publish a string to the speech recognition topic to test the pipeline:

```bash
ros2 topic pub /rero_ros/speech_recognition std_msgs/String "data: Please play the beatles"
```