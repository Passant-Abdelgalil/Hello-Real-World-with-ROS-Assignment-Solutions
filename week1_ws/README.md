# Week 1 ROS Essentials Assignments

This folder contains my solutions for Week1 (ROS Essentials) Assignments, implemented in ros c++/python.
# Folder Structure

```
├── week1_ws
|   ├── src
|   |   ├── assignment_sol
|   |   |   ├── scripts    # python scripts for ros application
|   |   |   |   ├── meters_to_feet_server.py  # script to advertise the metres_to_feet service
|   |   |   |   ├── sensor_info_publisher.py # script to publish generated sensor data
|   |   |   |   ├── week1_assignment1.py    # script to calculate box height in metres
|   |   |   |   └── week1_assignment2.py    # script to convert height in metres to feet
|   |   |   |
|   |   |   ├── src
|   |   |   |   ├── meters_to_feet_server.cpp # cpp file to advertise the metres_to_feet service
|   |   |   |   ├── sensor_info_publisher.cpp # cpp file to publish generated sensor data
|   |   |   |   ├── week1_assignment1.cpp   # cpp file to calculate box height in metres
|   |   |   |   └── week1_assignment2.cpp   # cpp file to convert height in metres to feet
|   |   |   |
|   |   |   └── include
|   |   |   
|   |   └── week1ws_msgs    # ROS package for this project messages
|   |       ├── msg     # custome message types definition files
|   |       |   ├── BoxHeightInformation.msg
|   |       |   └── SensorInformation.msg
|   |       |   
|   |       ├── srv     # services definition files
|   |       |   └── ConvertMetersToFeet.srv
|   |       |
|   |       ├── CMakeLists.txt
|   |       └── package.xml
|   |   
|   ├── test_execs.sh   # bash script to test ros c++ files
|   └── test_scripts.sh # bash script to test rospy scripts
|
└── README.md
```