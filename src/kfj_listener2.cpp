#include<stdio.h>

#include"kfj_ros2_listener/kfj_listener2.hpp"

KfjListener2::KfjListener2()
    : Node("listener2"),
      m_count(0)
{
    using std::placeholders::_1;
    m_subscriber = create_subscription<std_msgs::msg::String>("chatter",
            std::bind(&KfjListener2::handle_msg, this, _1));
}

void KfjListener2::handle_msg(const std_msgs::msg::String::SharedPtr msg_)
{
    printf("Node %s: I heard: '%s'\n", "listener2", msg_->data.c_str());
    m_count++;
    if (m_count > 5)
    {
        rclcpp::shutdown();
    }
}

