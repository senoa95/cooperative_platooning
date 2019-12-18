#!/usr/bin/env python

# Import libraries:
import rospy
import math
from std_msgs.msg import Bool
from geometry_msgs.msg import Point32,Pose
from agbot_nav.msg import lane
from utilities import Point, AckermannVehicle , PPController, DiffDriveVehicle
import transforms3d
import tf
import numpy
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
global simStart

wpList = []
currentPos = Point()
laneParams = lane()
moreLane = True

laneParams.rhoDot = 0
laneParams.rho = 0
laneParams.phi = 0
laneParams.y = 0
trial = 0
simStart = False

wpList.append(Point(currentPos.x, currentPos.y))
wpList.append(Point(currentPos.x, currentPos.y))
wpList.append(Point(currentPos.x, currentPos.y))
wpList.append(Point(currentPos.x, currentPos.y))
file_name = "waypoints_normalized_0.txt"


def ros_init():
    global pub_goal_debug
    global pub_goal_debug1

     # Setup the ROS publishers and subscribers:
    rospy.Subscriber("laneParams", lane, lane_callback)
    rospy.Subscriber("/pr2/local/Pose", Pose, pose_callback)
    rospy.Subscriber("/pr2/start", Bool, sim_start_callback)
    rospy.init_node('ppcontroller', anonymous=True)
    pub_goal_debug = rospy.Publisher('/current_goalpoint',Point32,queue_size=10)
    pub_goal_debug1 = rospy.Publisher('/current_goalpoint_one',Point32,queue_size=10)

def sim_start_callback(data):
    global simStart

    simStart = data.data

# Callback function for subscriber to Position and orientation topic:
def pose_callback(data):

    global currentPos
    
    euler = tf.transformations.euler_from_quaternion([data.orientation.x,data.orientation.y, data.orientation.z, data.orientation.w])

    currentPos.x = data.position.x
    currentPos.y = data.position.y
    currentPos.heading = euler[2]  # currentPos
    
def lane_callback(data):

    global currentPos
    global laneParams

    laneParams.rhoDot = data.rhoDot
    laneParams.rho = data.rho
    laneParams.phi = data.phi
    laneParams.y = data.y

def compute_waypoints_from_laneparams(update, currentGoalPoint):

    global laneParams
    global wpList
    global currentPos
    global pub_goal_debug
    global pub_goal_debug1

    step = 0.5
    numPoint = 20
    dist = 0
    wpList = []  

    if update:
        zero_x = currentGoalPoint.x
        zero_y = currentGoalPoint.y
    else:
        zero_x = currentPos.x
        zero_y = currentPos.y


    # compute lane points ahead of the vehicle
    for distIdx in range(0,numPoint):
        wpYorigin = 0.16667*laneParams.rhoDot*numpy.power(dist,3) + 0.5*laneParams.rho*numpy.power(dist,2) + laneParams.phi*dist + laneParams.y
        currPoint = numpy.array([dist, wpYorigin])
        heading = currentPos.heading
            

        rotationMtrx = numpy.array([[numpy.cos(heading), -numpy.sin(heading)], [numpy.sin(heading), numpy.cos(heading)]])
        # rotated_point_ = numpy.dot(currPoint, rotationMtrx)
        rotated_point = numpy.matmul(rotationMtrx,currPoint)
        # print('rotated b', rotated_point_b)    

        wpX = -rotated_point[0] + zero_x
        wpY = -rotated_point[1] + zero_y
        wpList.append(Point(wpX, wpY))

        print('original Points', dist, wpYorigin)
        print('rotated point', rotated_point)    
        print('current pose', currentPos.x, currentPos.y, heading)
        print('goalPoint', wpX, wpY)
        print('getting new list')
        dist = dist + step
    print('rotation matrix', rotationMtrx)
    current_goalPoint = Point32(wpList[5].x, wpList[5].y, 0)
    current_goalPoint1 = Point32(wpList[10].x, wpList[10].y, 0)
    pub_goal_debug.publish(current_goalPoint)
    pub_goal_debug1.publish(current_goalPoint1)
    
    # raw_input()
    return(wpList)

# 1. Initialize function definition:
def initialize():

    global file_name
    mule = DiffDriveVehicle(0.455,0.0,0.195,3)
    cntrl = PPController(0,mule.length,mule.minTurningRadius,mule.maximumVelocity)

    return cntrl


# 2. Execute function definition:
def execute(cntrl):

    global currentPos

    rate = rospy.Rate(10)


    # Initialize:
    # cntrl = initialize()

    # 1. Parameters:
    threshold = 0.5
    euclideanError = 0
    pub_rpy = rospy.Publisher('/pr2/rpy', Point32, queue_size=10)
    pub_goal = rospy.Publisher('/current_goalpoint',Point32,queue_size=10)
    pub_goal_one = rospy.Publisher('/current_goalpoint_one',Point32,queue_size=10)
    pub_goal_two = rospy.Publisher('/current_goalpoint_two',Point32,queue_size=10)
    pub_goal_three = rospy.Publisher('/current_goalpoint_three',Point32,queue_size=10)
    pub_goal_four = rospy.Publisher('/current_goalpoint_four',Point32,queue_size=10)
    pub_cmd = rospy.Publisher('/pr2/cmd_vel', Point32, queue_size =10)

    firstPoint = True
    shortGoal = 0
    count = 0
    prevDeltaEuclideanError = 0

    # Loop through as long as the node is not shutdown:
    while not rospy.is_shutdown():   

        if firstPoint:
            #find first waypoint
            prevEuclideanError = 10000000000000
            cntrl.currWpIdx = 0
            wpList = compute_waypoints_from_laneparams(False, 0)
            cntrl.initialize(wpList)
            goalPoint = cntrl.wpList[cntrl.currWpIdx]
            firstPoint = False
            getNextPoints = False


        pub_rpy.publish(Point32(0,0,currentPos.heading))
        euclideanError = math.sqrt((math.pow((goalPoint.x-currentPos.x),2) + math.pow((goalPoint.y-currentPos.y),2)))
   
        # Case #1:Vehicle is in the vicinity of current goal point (waypoint):
        if (euclideanError > threshold):

            # Compute steering and velocity commands according to Dr L controller
            vel, delta = cntrl.compute_steering_vel_cmds(currentPos)

            command = Point32()
            command.x = vel
            command.y = delta
            
            # Publish the computed command:
            pub_cmd.publish(command)

            # Recompute the Euclidean error to see if its reducing:
            euclideanError = math.sqrt((math.pow((goalPoint.x-currentPos.x),2) + math.pow((goalPoint.y-currentPos.y),2)))
            
            deltaEuclideanError = euclideanError - prevDeltaEuclideanError + deltaEuclideanError
            print('delta euclidean error', deltaEuclideanError)

            if numpy.absolute(deltaEuclideanError) > 1:
                print('Warning, off course')
                if numpy.absolute(deltaEuclideanError) > 2.5:
                    print('Vehicle off track, please reset')
                    # # Stationary Command
                    command = Point32()
                    stationaryCommand = Point32()

                    stationaryCommand.x = 0
                    stationaryCommand.y = 0
                    pub_cmd.publish(stationaryCommand)
                    quit()

            prevDeltaEuclideanError = deltaEuclideanError

            # print('abs previous euclidean error', numpy.absolute(prevEuclideanError))
            # print('abs euclidean error', numpy.absolute(euclideanError))

            # print('previous euclidean error', prevEuclideanError)
            # prevEuclideanError = euclideanError
            # print('euclidean error', euclideanError)
            


            # print('euclidean error', euclideanError)
            # print('current pose', currentPos.x, currentPos.y)
            # print('goalPoint',goalPoint.x, goalPoint.y)
        
        elif euclideanError < threshold:
            count = 0
            deltaEuclideanError = 0
            
            if shortGoal < 5 and moreLane == True:

                cntrl.currWpIdx +=1
                

                goalPoint = cntrl.wpList[cntrl.currWpIdx]

                index = cntrl.currWpIdx
                shortGoal +=1
                print (" Reached Waypoint # ", cntrl.currWpIdx +1)
                print('regular loop')

            else: 
                
                print('update goal')
                # # Update goal Point to next point in the waypoint list:
                # Compute a new list of waypoints
                wpList = compute_waypoints_from_laneparams(True, cntrl.wpList[cntrl.currWpIdx + 2])
                cntrl.initialize(wpList)
                
                cntrl.currWpIdx = 0
                goalPoint = cntrl.wpList[cntrl.currWpIdx]
                current_goalPoint = Point32(goalPoint.x,goalPoint.y,0)
                shortGoal = 0

            # if shortGoal == 20 and moreLane == True:

            #     # cntrl.currWpIdx = 0                
            #     # print('clearing wp of size', len(wpList))
            #     # time.sleep(10)
            #     # wpList = []
            #     print('more points :()')
            #     wpList = compute_waypoints_from_laneparams(False)
                
                
            #     # Make the AckermannVehicle stop where it is
            #     # wpList = compute_waypoints_from_laneparams(firstPoint, goalPoint)
            #     # cntrl.initialize(wpList)
                
            #     print (" New goal is: ")
            #     getNextPoints = True


            # elif moreLane == False:

            #     pub_cmd.publish(stationaryCommand)
            #     print (" --- All Waypoints have been conquered! Mission Accomplished Mr Hunt !!! --- ")
            #     break


        #initialize the new waypoints
        # cntrl.initialize(wpList)

        # find the waypoints
        # cntrl.currWpIdx = 0


        current_goalPoint = Point32(goalPoint.x,goalPoint.y,0)
        pub_goal.publish(current_goalPoint)

        goalPointOne = cntrl.wpList[cntrl.currWpIdx + 1]
        current_goalPoint_one = Point32(goalPointOne.x,goalPointOne.y,0)
        pub_goal_one.publish(current_goalPoint_one)
        
        goalPointTwo = cntrl.wpList[cntrl.currWpIdx + 2]
        current_goalPoint_two = Point32(goalPointTwo.x,goalPointTwo.y,0)
        pub_goal_two.publish(current_goalPoint_two)
        
        goalPointThree = cntrl.wpList[cntrl.currWpIdx + 3]
        current_goalPoint_three = Point32(goalPointThree.x,goalPointThree.y,0)
        pub_goal_three.publish(current_goalPoint_three)
        
        goalPointFour = cntrl.wpList[cntrl.currWpIdx + 4]
        current_goalPoint_four = Point32(goalPointFour.x,goalPointFour.y,0)
        pub_goal_four.publish(current_goalPoint_four)
        
        rate.sleep()

    rospy.spin()

if __name__ == '__main__':

    #Step 1: initialize ros
    while simStart == False:
        ros_init()
        print('Start VREP simulation')
        trial +=1
        time.sleep(1)
        if trial == 5:
            print('Quiting. Try again after starting VREP simulation')
            quit()

    # Step 1: Initialize the Controller by reading in the list of waypoints:
    cntrl = initialize()

    # Step 2: Execute the controller in a closed loop manner
    execute(cntrl)
