#!/usr/bin/env python
import rospy
import utm
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import Pose


# Counter to keep track of the number of callbacks:
#global cBackCounter = 0

# Boolean variable to indicate whether the initial co-ordinates have been set:
global iniSet
from utilities import Point, AckermannVehicle , PPController
import transforms3d as tf
import numpy as np

# Variables for xyz coordinates:
global x
global y
global z

global iniX
global iniY


iniX = 0
iniY = 0

x=0
y=0
z=0

iniSet = False

def conv_callback(data):

    global iniX , iniY , iniSet , x, y, z

    if not iniSet:

        iniY,iniX, zoneNum , char = utm.from_latlon(data.latitude, data.longitude)

        z = data.altitude

        iniSet = True

    else:

        yUTM,xUTM, zoneNum , char = utm.from_latlon(data.latitude, data.longitude)

        x = xUTM - iniX
        y=  yUTM - iniY

        z = data.altitude


def gps_xyz_conv():

    global  iniSet , x, y, z

    rospy.init_node("gps_to_xyz_conv", anonymous = True)

    # Create a subscriber to the GPS topic:
    rospy.Subscriber("/fix", NavSatFix, conv_callback)

    # Create a publisher to publish the XYZ co-ordinates:
    pubXYZ = rospy.Publisher('/agBOT/Local/Pose', Pose, queue_size = 10)

    agBOT_pose = Pose()

    rate = rospy.Rate(10) # 10hz


    while not rospy.is_shutdown():

        if iniSet:

            # Assign the Pose values:
            agBOT_pose.position.x = x
            agBOT_pose.position.y = y
            agBOT_pose.position.z = z


            pubXYZ.publish(agBOT_pose)

            rate.sleep()



# Run the main function:
if __name__ == '__main__':
    gps_xyz_conv()
