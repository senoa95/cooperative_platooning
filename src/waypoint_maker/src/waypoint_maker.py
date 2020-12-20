#!/usr/bin/env python

# Import libraries:
import rospy
from geometry_msgs.msg import Point32,Pose,Point
from sensor_msgs.msg import NavSatFix
import csv
import math
import utm
import time
import os

global previous_x
global previous_y
global current_x
global current_y

previous_x = 0
previous_y = 0
current_x = 0
current_y = 0

i = 0

while os.path.exists("/home/senoa95/agbot_nav_ws/src/agbot_nav/src/waypoints_%s.txt" % i):
    i += 1
    print(i)

waypoint_file =  open(os.path.join("/home/senoa95/agbot_nav_ws/src/agbot_nav/src/","waypoints_%s.txt" % i),"w")

def pose_callback(data):

    global previous_x
    global previous_y
    global current_x
    global current_y

    # rospy.loginfo(rospy.get_caller_id(), data.data)
    x = data.latitude
    y = data.longitude
    iniY,iniX, zoneNum , char = utm.from_latlon(x,y)
    current_x = iniX
    current_y = iniY

def heading_callback(heading_data):
    rospy.loginfo(rospy.get_caller_id(), heading_data.heading_data)
    yaw = heading_data.z

def waypoint_maker():

    global previous_x
    global previous_y
    global current_x
    global current_y

    rospy.init_node('waypoint_maker',anonymous=True)
    rospy.Subscriber("/fix", NavSatFix, pose_callback)
    # rospy.Subscriber("/imu", Pose, heading_callback)

    while not rospy.is_shutdown():

        euclideanDistance = math.sqrt((math.pow((current_x-previous_x),2) + math.pow((current_y-previous_y),2)))

        if euclideanDistance > 0.5:
            print("distance = ", euclideanDistance)

            waypoint_file.write(str(current_x)+","+str(current_y)+"\r\n")
            # value = [current_x,current_y]
            # waypoint_file.write(value)
            previous_x = current_x
            previous_y = current_y

if __name__ == '__main__':
    waypoint_maker()
    # heading_callback()
