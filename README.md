# Hello (Real) World with ROS – Robot Operating System (Assignment Solutions)

This repository contains my solutions for Hello (Real) World with ROS – Robot Operating System Edx Course, implemented in ros c++/python.
# Folder Structure

```
├── week1_ws
|   ├── src
|   ├── test_scripts.sh # bash script to test rospy scripts
|   ├── test_execs.sh   # bash script to test ros c++ files
|   └── README.md
├── week2_ws
|   ├── src
|   ├── run_assignment1.sh   # bash script to run assignment 1 simulation
|   ├── run_assignment2.sh   # bash script to run assignment 2 simulation
|   ├── run_assignment3.sh   # bash script to run assignment 3 simulation
|   └── README.md
|
└── README.md
```

# Dependencies
1. Ubuntu 18 LTS 
2. Python 2   
run these commands to install on ubuntu 18 LTS  
    ```bash
    sudo apt update 
    sudo apt upgrade
    sudo apt install python2.7
    ```
3. ROS Melodic from [HERE](http://wiki.ros.org/melodic/Installation/Ubuntu)

# Run
`NOTE: Please make sure you followed the Environment setup section in ROS Melodic installation guide.`
## Python Scripts
1. Open up a terminal
2. run `git clone https://github.com/CU-Eco-Racing-Team/AutonomousLearningPhase2022.git`
3. run `cd AutonomousLearningPhase2022`
4. cd to the week folder you want using cd, e.g. `cd week1_ws`.
5. drag & drop **test_scripts.sh** in the terminal OR run `./test_scripts.sh`
## C++
1. Open up a terminal
2. run `git clone https://github.com/CU-Eco-Racing-Team/AutonomousLearningPhase2022.git`
3. run `cd AutonomousLearningPhase2022`
4. cd to the week folder you want using cd, e.g. `cd week1_ws`.
5. drag & drop **test_execs.sh** in the terminal OR run `./test_execs.sh`
## Simulation Assignment
1. Open up a terminal
2. run `git clone https://github.com/CU-Eco-Racing-Team/AutonomousLearningPhase2022.git`
3. run `cd AutonomousLearningPhase2022`
4. cd to the week folder you want using cd, e.g. `cd week2_ws`.
5. drag & drop **<bashScript_file_name>.sh** in the terminal OR run `./<bashScript_file_name>.sh` [Please change the file name].
