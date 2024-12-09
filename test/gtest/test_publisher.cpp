/**
 * @file test_publisher.cpp
 * @brief Unit tests for the ROS 2 minimal publisher node.
 *
 * This file contains test cases to verify the functionality of our minimal publisher.
 * We test two main things:
 * 1. That the node is created correctly with the right name and topic
 * 2. That it publishes the expected "Hello World!" message
 *
 * Testing Framework:
 *   Google Test (gtest) for C++ unit testing
 *
 * Tests:
 *   TestNodeCreation: Verifies node name and publisher setup
 *   TestMessageContent: Verifies published message format
 *
 * @author Addison Sears-Collins
 * @date November 6, 2024
 */

// Include necessary header files for testing
#include <gtest/gtest.h>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

// Tell the compiler our node class exists without including full definition yet
class MinimalCppPublisher;

// This prevents the main() function in the implementation file from being included
// which would conflict with our test's main() function
#define TESTING_EXCLUDE_MAIN
#include "../../src/cpp_minimal_publisher.cpp"

/**
 * @class TestMinimalPublisher
 * @brief Test fixture for the MinimalCppPublisher tests
 *
 * This class sets up and tears down the testing environment for each test.
 * It initializes ROS 2 and creates our publisher node before each test,
 * and cleans up afterward.
 */
class TestMinimalPublisher : public ::testing::Test
{
protected:
    /**
     * @brief Set up the test fixture before each test
     *
     * Initializes ROS 2 and creates a new publisher node
     */
    void SetUp() override
    {
        rclcpp::init(0, nullptr);
        node = std::make_shared<MinimalCppPublisher>();
    }

    /**
     * @brief Clean up after each test completes
     *
     * Shuts down the node and ROS 2
     */
    void TearDown() override
    {
        node.reset();
        rclcpp::shutdown();
    }

    // The node we're testing
    std::shared_ptr<MinimalCppPublisher> node;
};

/**
 * @test TestNodeCreation
 * @brief Verify the publisher node is created correctly
 *
 * This test checks two things:
 * 1. The node has the correct name "minimal_cpp_publisher"
 * 2. The node has exactly one publisher on the topic "/cpp_example_topic"
 */
TEST_F(TestMinimalPublisher, TestNodeCreation)
{
    // Check if the node name matches what we expect
    EXPECT_EQ(std::string(node->get_name()), std::string("minimal_cpp_publisher"));

    // Get information about publishers on our topic and verify there's exactly one
    auto pub_endpoints = node->get_publishers_info_by_topic("/cpp_example_topic");
    EXPECT_EQ(pub_endpoints.size(), 1u);
}

/**
 * @test TestMessageContent
 * @brief Verify the published message has correct content
 *
 * This test:
 * 1. Creates a subscription to capture the published message
 * 2. Triggers the publisher to send a message
 * 3. Verifies the message starts with "Hello World!"
 */
TEST_F(TestMinimalPublisher, TestMessageContent)
{
    // Variable to store the received message
    std::shared_ptr<std_msgs::msg::String> received_msg;

    // Create a subscription to capture the published message
    auto subscription = node->create_subscription<std_msgs::msg::String>(
        "/cpp_example_topic", 10,
        [&received_msg](const std_msgs::msg::String::SharedPtr msg) {
            received_msg = std::make_shared<std_msgs::msg::String>(*msg);
        });

    // Trigger the publisher to send a message
    node->timerCallback();

    // Process any incoming messages
    rclcpp::spin_some(node);

    // Check if the message starts with "Hello World!"
    EXPECT_EQ(received_msg->data.substr(0, 12), "Hello World!");
}

/**
 * @brief Main function to run all tests
 *
 * This function initializes the Google Test framework and runs all tests
 */
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}