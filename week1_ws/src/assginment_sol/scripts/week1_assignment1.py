#! /usr/bin/env python

# Assignment 1 for Week1: In this assignment you will subscribe to the topic that
# publishes sensor information. Then, you will transform the sensor reading from
# the reference frame of the sensor to compute the height of a box based on the
# illustration shown in the assignment document. Then, you will publish the box height
# on a new message type ONLY if the height of the box is more than 10cm.

# All necessary python imports go here.

import rospy
from week1ws_msgs.msg import SensorInformation, BoxHeightInformation

def sensor_info_callback(data, bhi_pub):

    # extract the distance value from the sensor data
    height_box = data.sensor_data.range

    # Compute the height of the box.
    # Boxes that are detected to be shorter than 10cm are due to sensor noise.
    # Do not publish information about them.
    if data.sensor_data.max_range - height_box < 0.1:
        pass
    else:
        # declare a message object for publishing the box height information
        box_height_info = BoxHeightInformation()
        # update the box_height field with the computed height
        box_height_info.box_height = 2.0 - height_box
        # publish the box height
        bhi_pub.publish(box_height_info)



# Main loop
if __name__ == '__main__':

    # Intialize a ROS node
    rospy.init_node('compute_box_height', anonymous=False)

    # Wait for the topic that published sensor inforamtion to become available
    rospy.loginfo('Waiting for topic %s to be published ...', 'sensor_info')
    rospy.wait_for_message('sensor_info', SensorInformation)
    rospy.loginfo('%s is now available', 'sensor_info')

    # Create publisher object 
    bhi_publisher = rospy.Publisher('box_height_info', BoxHeightInformation, queue_size=10)
    # Note here that an ADDITIONAL ARGUMENT (bhi_publisher) is passed to the subscriber. This is a way to pass
    # ONE additional argument to the subscriber callback. If you want to pass multiple arguments,
    # you can use a python dictionary. And if you don't want to use multiple arguments to the
    # subscriber callback then you can also consider using a Class Implementation like we saw in
    # the action server code illustration.

    # create the subscriber
    rospy.Subscriber('sensor_info', SensorInformation, sensor_info_callback, bhi_publisher)
    
    # Prevent this code from exiting until Ctrl+C is pressed.
    rospy.spin()