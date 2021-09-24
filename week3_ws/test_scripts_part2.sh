#!/bin/bash

catkin b
gnome-terminal -- /bin/bash -c 'sleep 13; source devel/setup.bash; roslaunch assignment_sol hrwros_turtlebot_navigation.launch'
gnome-terminal -- /bin/bash -c 'sleep 13; source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=`rospack find assignment_sol`/config/map_factory_v1.yaml initial_pose_x:=-4.000538 initial_pose_y:=-0.200409'
gnome-terminal -- /bin/bash -c 'sleep 13; source devel/setup.bash; roslaunch assignment_sol hrwros_view_navigation.launch'
gnome-terminal -- /bin/bash -c 'sleep 13; source devel/setup.bash; roslaunch assignment_sol week3_assignment3_part2.launch; exec bash'
