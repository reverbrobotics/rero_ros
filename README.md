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