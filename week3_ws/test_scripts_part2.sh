#!/bin/bash

catkin build
gnome-terminal -- /bin/bash -c 'roscore'
sleep 2
gnome-terminal -- /bin/bash -c 'source devel/setup.bash; roslaunch assignment_sol hrwros_turtlebot_navigation.launch'
sleep 4
gnome-terminal -- /bin/bash -c 'source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=`rospack find assignment_sol`/config/map_factory_v1.yaml initial_pose_x:=-4.000538 initial_pose_y:=-0.200409'
sleep 4
gnome-terminal -- /bin/bash -c 'source devel/setup.bash; roslaunch assignment_sol hrwros_view_navigation.launch'
sleep 4
gnome-terminal -- /bin/bash -c 'source devel/setup.bash; roslaunch assignment_sol week3_assignment3_part2.launch; exec bash'
