#include "ros/ros.h"
#include "week1ws_msgs/ConvertMetresToFeet.h"
#include "week1ws_msgs/BoxHeightInformation.h"

using namespace ros;

void bos_height_info_callback(week1ws_msgs::BoxHeightInformation data)
{
    try
    {        // create object of service message type and fill in its request data
        week1ws_msgs::ConvertMetresToFeet service_msg;
        service_msg.request.measurement_meters = data.box_height;

        // call the service
        if (service::call("metres_to_feet", service_msg))
            ROS_INFO("%4.2f(m) = %4.2f feet", service_msg.request.measurement_meters, service_msg.response.measurement_feet);
        else
            ROS_INFO("Service call failed");
    }
    catch (Exception &e)
    {
        ROS_INFO("Service call failed: %s", e.what());
    }
}

int main(int argc, char **argv)
{

    init(argc, argv, "box_height_in_feet");

    // Wait for the topic that published sensor inforamtion to become available
    ROS_INFO("Waiting for service...");
    service::waitForService("metres_to_feet", -1);
    ROS_INFO("Service %s is now available", "metres_to_feet");

    // Create a subscriber to the box height topic
    NodeHandle snode;
    Subscriber sub = snode.subscribe<week1ws_msgs::BoxHeightInformation>(
        "box_height_info", 10, &bos_height_info_callback);
    // exit when Ctrl-C is pressed, or the node is shutdown by the master node
    spin();
    return 0;
}
