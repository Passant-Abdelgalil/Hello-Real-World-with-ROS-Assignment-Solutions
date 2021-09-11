#include "ros/ros.h"
#include "week1ws_msgs/ConvertMetresToFeet.h"

#define _CONVERSION_FACTOR_METRES_TO_FEET 3.28 // Metres -> Feet conversion factor.
using namespace ros;

bool process_service_request(week1ws_msgs::ConvertMetresToFeetRequest &req, week1ws_msgs::ConvertMetresToFeetResponse &res)
{

    // Perform sanity check.Allow only positive real numbers.
    // Compose the response message accordingly.
    if (req.measurement_meters < 0)
    {
        res.success = false;
        res.measurement_feet = -1;
    }
    else
    {
        res.success = true;
        res.success = req.measurement_meters * _CONVERSION_FACTOR_METRES_TO_FEET;
    }

    return res.success;
}

int main(int argc, char **argv)
{
    // initialize ROS node.
    init(argc, argv, "metres_to_feet_server");

    // Create & Advertise service.
    NodeHandle servNode;
    ServiceServer server = servNode.advertiseService("metres_to_feet", process_service_request);

    // Log message about service availability.
    ROS_INFO("Convert metres to feet service is now available.");

    spin();
    return 0;
}
