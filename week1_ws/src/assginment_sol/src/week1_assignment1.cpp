#include "ros/ros.h"
#include "week1ws_msgs/BoxHeightInformation.h"
#include <week1ws_msgs/SensorInformation.h>

using namespace ros;
Publisher bhi_publisher;
void sensor_info_callback(const week1ws_msgs::SensorInformation::ConstPtr &data, Publisher *pub)
{
    // extract the distance from the sensor data
    double height_box = data->sensor_data.range;

    /* Compute the height of the box.
    # Boxes that are detected to be shorter than 10cm are due to sensor noise.
    # Do not publish information about them.*/
    if (data->sensor_data.max_range - height_box < 0.1)
        return;

    // declare a message object for publishing the box height information
    week1ws_msgs::BoxHeightInformation box_height_info;

    // update the box_height field with the computed height
    box_height_info.box_height = 2.0 - height_box;

    // publish the box height
    pub->publish(box_height_info);
}

int main(int argc, char **argv)
{

    init(argc, argv, "compute_box_height");

    // Wait for the topic that published sensor inforamtion to become available
    NodeHandle n;
    ROS_INFO("Waiting for topic sensor_info to be published...");
    topic::waitForMessage<week1ws_msgs::SensorInformation>("sensor_info", n);
    ROS_INFO("sensor_info is now available!");

    // create publisher node
    NodeHandle pnode;
    bhi_publisher = pnode.advertise<week1ws_msgs::BoxHeightInformation>(
        "box_height_info", 10);

    /*
    # Note here that an ADDITIONAL ARGUMENT (bhi_publisher) is passed to the subscriber. This is a way to pass
    # ONE additional argument to the subscriber callback.*/

    // create a subscriber
    NodeHandle snode;
    Subscriber sub = snode.subscribe<week1ws_msgs::SensorInformation>(
        "sensor_info", 10, boost::bind(&sensor_info_callback, _1, &bhi_publisher));
    // exit when Ctrl-C is pressed, or the node is shutdown by the master node
    spin();
    return 0;
}
