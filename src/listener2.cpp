/*
 * ROS2 listener.
 *
 * Refer to https://github.com/ros2/examples/blob/master/rclcpp/minimal_subscriber/member_function.cpp
 *
 */

#include"kfj_ros2_listener/kfj_listener2.hpp"

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<KfjListener2>());
    rclcpp::shutdown();

    return 0;
}
