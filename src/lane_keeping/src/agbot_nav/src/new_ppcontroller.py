#!/usr/bin/env python

# Import libraries:
import rospy
import math
from geometry_msgs.msg import Point32,Pose
from agbot_nav.msg import lane
from utilities import Point, AckermannVehicle , PPController, DiffDriveVehicle
import transforms3d as tf
import numpy as np
import os
import rospkg
import time

rospack = rospkg.RosPack()


### Define constants:

# Define global variables:
global currentPos
global file_name
global laneParams
global wpList

wpList = []
currentPos = Point()
laneParams = lane()

laneParams.rhoDot = 0
laneParams.rho = 0
laneParams.phi = 0
laneParams.y = 0


wpList.append(Point(currentPos.x, currentPos.y))
wpList.append(Point(currentPos.x, currentPos.y))
wpList.append(Point(currentPos.x, currentPos.y))
wpList.append(Point(currentPos.x, currentPos.y))
file_name = "waypoints_normalized_0.txt"

# Callback function for subscriber to Position and orientation topic:
def pose_callback(data):

    global currentPos

    currentPos.x = data.position.x
    currentPos.y = data.position.y

    euler = tf.euler.quat2euler([data.orientation.x,data.orientation.y,data.orientation.z,data.orientation.w])
    currentPos.heading = euler[0]
    
def lane_callback(data):

    global currentPos
    global laneParams

    laneParams.rhoDot = data.rhoDot
    laneParams.rho = data.rho
    laneParams.phi = data.phi
    laneParams.y = data.y

def compute_waypoints_from_laneparams():

    global laneParams

    minDist = 1    
    step = 1
    maxDist = 200
    numPoint = int(maxDist / step)
    dist = 0
    wpList = []

    # compute lane points ahead of the vehicle
    for distIdx in range(minDist,numPoint):
        print( dist)
        dist = dist + step
        wpList.append(Point(dist + currentPos.x , 0.16667*laneParams.rhoDot*np.power(dist,3) + 0.5*laneParams.rho*np.power(dist,2) + laneParams.phi*dist + laneParams.y + currentPos.y))

    return(wpList)

def get_waypoints_from_file(file_name):
    
    global currentPos
    global wpList
    
    fileLoc = os.path.join(rospack.get_path("agbot_nav"),"src",file_name)
    wpFile = open(fileLoc, 'r')
    wPts = wpFile.readlines()

    for wp in wPts:

        spLine = wp.split( ',')
        wpList.append(Point(float(spLine[0]), float(spLine[1])))

    return wpList

# 1. Initialize function definition:
def initialize():

    global file_name
    # Create objects for AckermannVehicle and Pure Pursuit controller:
    # wpList = get_waypoints_from_file(file_name)
    wpList = compute_waypoints_from_laneparams()
    mule = DiffDriveVehicle(0.455,0.0,0.195,3)
    cntrl = PPController(0,mule.length,mule.minTurningRadius,mule.maximumVelocity)
    cntrl.initialize(wpList)

    return cntrl


# 2. Execute function definition:
def execute(cntrl):

    global currentPos

    # Setup the ROS publishers and subscribers:
    rospy.Subscriber("laneParams", lane, lane_callback)
    rospy.Subscriber("/pr2/local/Pose", Pose, pose_callback)
    pub = rospy.Publisher('/pr2/cmd_vel', Point32, queue_size =10)
    pub_goal = rospy.Publisher('/current_goalpoint',Point32,queue_size=10)
    rospy.init_node('ppcontroller', anonymous=True)

    rate = rospy.Rate(10)

    # Initialize:
    cntrl = initialize()

    # 1. Parameters:
    threshold = 1
    euclideanError = 0

    # 2. Points:
    goalPoint = cntrl.wpList[cntrl.currWpIdx]

    # 3. Commands:
    command = Point32()
    stationaryCommand = Point32()

    stationaryCommand.x = 0
    stationaryCommand.y = 0

    # Loop through as long as the node is not shutdown:
    while not rospy.is_shutdown():

        #Compute a new list of waypoints
        wpList = compute_waypoints_from_laneparams()

        #initialize the new waypoints
        cntrl.initialize(wpList)

        #find first waypoint
        cntrl.currWpIdx = 0
        goalPoint = cntrl.wpList[cntrl.currWpIdx]

        # Compute the new Euclidean error:
        current_goalPoint = Point32(goalPoint.x,goalPoint.y,0)
        # current_goalPoint = [str(goalPoint.x),str(goalPoint.y),'0']
        pub_goal.publish(current_goalPoint)

        euclideanError = math.sqrt((math.pow((goalPoint.x-currentPos.x),2) + math.pow((goalPoint.y-currentPos.y),2)))
   
        # Case #1:Vehicle is in the vicinity of current goal point (waypoint):
        if (euclideanError < threshold):

            # Make the AckermannVehicle stop where it is
            pub.publish(stationaryCommand)

            print (" Reached Waypoint # ", cntrl.currWpIdx +1)
            # Update goal Point to next point in the waypoint list:
            cntrl.currWpIdx +=1
            print(cntrl.currWpIdx)
            print(cntrl.nPts)
            if cntrl.currWpIdx < cntrl.nPts:
                goalPoint = cntrl.wpList[cntrl.currWpIdx + 1]

            else:

                print (" --- All Waypoints have been conquered! Mission Accomplished Mr Hunt !!! --- ")
                break


            print (" New goal is: ")
            print (goalPoint.x)
            print (goalPoint.y)
        # print (" Euclidean Error = ", euclideanError , " meters")
        

        # Case #2:
        if (euclideanError > threshold):

            # Compute steering and velocity commands according to Dr L controller
            vel, delta = cntrl.compute_steering_vel_cmds(currentPos)

            command = Point32()
            command.x = vel
            command.y = delta
            
            # Publish the computed command:
            pub.publish(command)

            # Recompute the Euclidean error to see if its reducing:
            euclideanError = math.sqrt((math.pow((goalPoint.x-currentPos.x),2) + math.pow((goalPoint.y-currentPos.y),2)))


        rate.sleep()

    rospy.spin()

if __name__ == '__main__':

    # Step 1: Initialize the Controller by reading in the list of waypoints:
    cntrl = initialize()

    # Step 2: Execute the controller in a closed loop manner
    execute(cntrl)
