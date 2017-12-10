#include<rclcpp/rclcpp.hpp>
#include<std_msgs/msg/string.hpp>

class KfjListener2 : public rclcpp::Node
{
public:
    KfjListener2();

private:
    void handle_msg(const std_msgs::msg::String::SharedPtr msg_);

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr m_subscriber;

    int m_count;
};

