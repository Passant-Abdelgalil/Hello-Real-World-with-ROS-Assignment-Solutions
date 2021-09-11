#!/usr/bin/env python
# Software License Agreement (BSD License)
#
# Copyright (c) 2008, Willow Garage, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above
#    copyright notice, this list of conditions and the following
#    disclaimer in the documentation and/or other materials provided
#    with the distribution.
#  * Neither the name of Willow Garage, Inc. nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Revision $Id$

# Node to publish to a string topic.


import rospy
import random
from week1ws_msgs.msg import SensorInformation

# util function to generate values for range field in sensor data


def getSensorData(sensor_type, min_range, max_range):
    if (sensor_type != 0):
        print('Sensor type not supported!')
        return -1
    if(random.uniform(0.0, 1.0) < 0.95):
        return max_range
    else:
        return random.uniform(min_range, max_range)


# main function to publish the generated sensor data
def sensor_info_publisher():
    # Instantiate a publisher
    SI_publisher = rospy.Publisher(
        'sensor_info', SensorInformation, queue_size=10)
    # create publisher node
    rospy.init_node('sensor_information_publisher', anonymous=False)
    # set the rate of publishing
    rate = rospy.Rate(10)

    # create a new SensorInformation object and fill in its content
    sensor_info = SensorInformation()

    # Fill in the header information.
    sensor_info.sensor_data.header.stamp = rospy.Time.now()
    sensor_info.sensor_data.header.frame_id = 'distance_sensor_frame'

    # Fill in the sensor data information
    sensor_info.sensor_data.radiation_type = sensor_info.sensor_data.ULTRASOUND
    sensor_info.sensor_data.field_of_view = 0.5  # Field of view in sensor in rad
    # Minimum distance range of the sensor in m
    sensor_info.sensor_data.min_range = 0.02
    # Maximum distance range of the sensor in m
    sensor_info.sensor_data.max_range = 2.0

    # Fill in the manufacturer name and part number.
    sensor_info.maker_name = 'The Ultrasound Company'
    sensor_info.part_number = 123456

    # Main loop
    while not rospy.is_shutdown():
        # Read the sensor data from a simulated sensor
        sensor_info.sensor_data.range = getSensorData(sensor_info.sensor_data.radiation_type,
                                                      sensor_info.sensor_data.min_range, sensor_info.sensor_data.max_range)

        # Publish the sensor information on the /sensor_info topic
        SI_publisher.publish(sensor_info)

        # Print log message if all went well
        rospy.loginfo('All went well. Publishing topic')
        # Ensure the publishing is done with the specified rate
        rate.sleep()


if __name__ == '__main__':
    try:
        sensor_info_publisher()
    except rospy.ROSInterruptException:
        pass
