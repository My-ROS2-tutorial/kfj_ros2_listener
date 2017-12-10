## Introduction

The listener receives  "Hello ROS2 number" sent by the talker.

## Usage

```.sh
ament build --only-packages kfj_ros2_listener
. install/local_setup.sh
run kfj_ros2_listener listener1
```

```
$ ros2 run kfj_ros2_listener listener1
Node listener1: I heard: 'Hello ROS2 1'
Node listener1: I heard: 'Hello ROS2 2'
Node listener1: I heard: 'Hello ROS2 3'
Node listener1: I heard: 'Hello ROS2 4'
Node listener1: I heard: 'Hello ROS2 5'
Node listener1: I heard: 'Hello ROS2 6'
```
