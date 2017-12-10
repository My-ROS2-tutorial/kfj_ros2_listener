/*
 * ROS2 listener.
 *
 * Refer to https://github.com/ros2/examples/blob/master/rclcpp/minimal_subscriber/not_composable.cpp
 *
 * This style is not recommended anymore.
 */

#include<stdio.h>
#include<rclcpp/rclcpp.hpp>
#include<std_msgs/msg/string.hpp>

std::string g_node_name = "listener1";
std::string g_topic_name = "chatter";

int g_count = 0;
void callback(const std_msgs::msg::String::SharedPtr msg_)
{
    printf("Node %s: I heard: '%s'\n", g_node_name.c_str(), msg_->data.c_str());
    g_count++;
    if (g_count > 5)
    {
        rclcpp::shutdown();
    }
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared(g_node_name);
    auto listener = node->create_subscription<std_msgs::msg::String>(g_topic_name, callback);
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
