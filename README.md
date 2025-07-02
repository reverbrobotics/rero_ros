## Installation instructions


### Download and compile gRPC
First clone gRPC in your home directory.
```git clone --recurse-submodules -b v1.73.0 https://github.com/grpc/grpc```

Next, make build dir and compile gRPC

```cd grpc```
```mkdir build && cd build```
```cmake .. -DgRPC_INSTALL=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/grpc_install```
```make -j($nproc) install```



### Colcon build with gRPC

```colcon build --symlink-install --cmake-args -DGRPC_FETCHCONTENT=OFF -DCMAKE_PREFIX_PATH=~/grpc_install```

## Launching Package
Make sure an instance of the rero_server is running, and that the launch file is correctly configured to point at the server. ReRo packages can then be launched using their corresponding launch files. For example, to launch the nlu:

```ros2 launch rero_ros nlu.launch.xml```

### Testing the NLU

First, in a new terminal, echo the nlu output topic as follows (you will need to source your ROS workspace if it doesn't automatically do this in your .bashrc):

```ros2 topic echo /rero_ros/nlu_result```

Next, publish a string to the topic to test the service: 

```ros2 topic pub /rero_ros/speech_recognition std_msgs/String "data: Please play the beatles"```

(This example is using the default NLU model for recognizing music app commands and a custom nlu model should be used for your specific robotics task when using the package in production)