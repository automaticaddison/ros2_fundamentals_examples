/**
 * @file cpp_minimal_subscriber.cpp
 * @brief Demonstrates subscribing to string messages on a ROS 2 topic.
 *
 * Description: Demonstrates the basics of subscribing to messages within
 *   the ROS 2 framework. The core functionality of this subscriber is to
 *   display output to the terminal window when a message is received over
 *   a topic.
 *
 * -------
 * Subscription Topics:
 *   String message
 *   /cpp_example_topic - std_msgs/String
 * -------
 * Publishing Topics:
 *   None
 * -------
 * @author Addison Sears-Collins
 * @date November 5, 2024
 */

#include "rclcpp/rclcpp.hpp" // ROS 2 C++ client library
#include "std_msgs/msg/string.hpp" // Handle tring messages
using std::placeholders::_1; // Placeholder for callback function argument

/**
 * @class MinimalCppSubscriber
 * @brief Defines a minimal ROS 2 subscriber node.
 *
 * This class inherits from rclcpp::Node and
 * demonstrates creating a subscriber and
 * subscribing to messages.
 */
class MinimalCppSubscriber : public rclcpp::Node
{
public:
    /**
     * @brief Constructs a MinimalCppSubscriber node.
     *
     * Sets up a subscriber for 'std_msgs::msg::String' messages
	 * on the "/cpp_example_topic" topic.
     */
    MinimalCppSubscriber() : Node("minimal_cpp_subscriber")
    {
        // Create a subscriber object for listening to string messages on
        // with a queue size of 10.
        subscriber_ = create_subscription<std_msgs::msg::String>
        (
            "/cpp_example_topic",
            10,
            std::bind(
                &MinimalCppSubscriber::topicCallback,
                this,
                _1
            )
        );
    }

    /**
     * @brief This function runs every time a message is received on the topic.
     *
     * This is the callback function of the subscriber. It publishes a
	 * string message every time a message is received on the topic.
     *
     * @param msg The string message received on the topic
     * @return void
     */
    void topicCallback(const std_msgs::msg::String &msg) const
    {
        // Write a message every time a new message is received on the topic.
        RCLCPP_INFO_STREAM(get_logger(), "I heard: " << msg.data.c_str());

    }

private:
    // Member variables.
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

/**
 * @brief Main function.
 *
 * Initializes the ROS 2 system and runs the minimal_cpp_subscriber node.
 * It keeps the node alive until it is manually terminated.
 */
int main(int argc, char * argv[])
{

  // Initialize ROS 2.
  rclcpp::init(argc, argv);

  // Create an instance of the MinimalCppSubscriber node and keep it running.
  auto minimal_cpp_subscriber_node = std::make_shared<MinimalCppSubscriber>();
  rclcpp::spin(minimal_cpp_subscriber_node);

  // Shutdown ROS 2 upon node termination.
  rclcpp::shutdown();

  // End of program.
  return 0;
}