#!/bin/sh
gnome-terminal -- /bin/bash -c 'catkin build; roscore'
gnome-terminal -- /bin/bash -c 'sleep 10; source devel/setup.bash; roslaunch assginment_sol week1_assignments_cpp.launch; exec bash'
