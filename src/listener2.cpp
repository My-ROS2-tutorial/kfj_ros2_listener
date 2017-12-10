/*
 * ROS2 listener.
 *
 * Refer to https://github.com/ros2/examples/blob/master/rclcpp/minimal_subscriber/member_function.cpp
 *
 */

#include<stdio.h>
#include<rclcpp/rclcpp.hpp>
#include<std_msgs/msg/string.hpp>

using std::placeholders::_1;

class KfjListener2 : public rclcpp::Node
{
public:
    KfjListener2()
        : Node("listener2"),
          m_count(0)
    {
        m_subscriber = create_subscription<std_msgs::msg::String>("chatter",
                                                                  std::bind(&KfjListener2::callback, this, _1));
    }

private:
    void callback(const std_msgs::msg::String::SharedPtr msg_)
    {
        printf("Node %s: I heard: '%s'\n", "listener2", msg_->data.c_str());
        m_count++;
        if (m_count > 5)
        {
            rclcpp::shutdown();
        }
    }
private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr m_subscriber;

    int m_count;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<KfjListener2>());
    rclcpp::shutdown();

    return 0;
}
