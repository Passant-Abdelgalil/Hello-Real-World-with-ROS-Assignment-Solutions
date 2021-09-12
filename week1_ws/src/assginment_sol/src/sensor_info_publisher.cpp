#include <random>
#include "ros/ros.h"
#include "week1ws_msgs/SensorInformation.h"

using namespace ros;
using namespace std;

// util function to generate data for range field in sensor data
double getSensorData(int sensor_type, double min_range, double max_range)
{
    if (sensor_type != 0)
    {
        cout << "Sensor type not supported!\n";
        return -1;
    }
    random_device rd;
    default_random_engine generator(rd());
    uniform_real_distribution<double> dist1(0.0, 1.0);

    if (dist1(generator) < 0.95)
        return max_range;

    uniform_real_distribution<double> dist2(min_range, max_range);
    dist2.reset();
    return dist2(generator);
}

// main function to publish generated sensor data
void sensor_info_publisher()
{
    // Instantiate a publisher
    NodeHandle node;
    Publisher pub = node.advertise<week1ws_msgs::SensorInformation>("sensor_info", 10);

    // set the rate of publishing
    Rate rate(10);

    // create a new SensorInformation object and fill in its content
    week1ws_msgs::SensorInformation sensor_info;

    // Fill in the header information
    sensor_info.sensor_data.header.stamp = Time::now();
    sensor_info.sensor_data.header.frame_id = "distance_sensor_frame";

    // Fill in the sensor data information
    sensor_info.sensor_data.radiation_type = sensor_info.sensor_data.ULTRASOUND;
    sensor_info.sensor_data.field_of_view = 0.5; // Field of view in sensor in rad
    sensor_info.sensor_data.min_range = 0.02;    // Minimum distance range of the sensor in m
    sensor_info.sensor_data.max_range = 2.0;     // Maximum distance range of the sensor in m

    // Fill in the manufacturer name and part number.
    sensor_info.maker_name = "The Ultrasound Company";
    sensor_info.part_number = 123456;

    // Main Loop
    while (ok())
    {
        // Read the sensor data from a simulated sensor
        sensor_info.sensor_data.range = getSensorData(sensor_info.sensor_data.radiation_type,
                                                      sensor_info.sensor_data.min_range, sensor_info.sensor_data.max_range);

        // Publish the sensor information on the /sensor_info topic
        pub.publish(sensor_info);

        // Print log message if all went well
        //ROS_INFO("All went well. Publishing topic ");

        spinOnce();
        rate.sleep();
    }
}

int main(int argc, char **argv)
{

    init(argc, argv, "sensor_info_publisher");
    try
    {
        sensor_info_publisher();
    }
    catch (Exception &e)
    {
    }

    return 0;
}