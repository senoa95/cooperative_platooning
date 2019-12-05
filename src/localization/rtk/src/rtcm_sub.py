#!/usr/bin/env python

import rospy
import serial
import socket
from socket import error as socket_error
from std_msgs.msg import String as type

def callback(data):
    # rospy.loginfo(rospy.get_caller_id(), rtcm.data)
    global RTCM
    RTCM = data.data
    


def rtcm_subscriber():
    ###Define publisher
    global RTCM
    RTCM = ''
    rospy.init_node('rtcm_subscriber', anonymous='True')
    rospy.Subscriber("rtcm", type, callback)
    print('here')

    while not rospy.is_shutdown():
        rospy.sleep(0.05)

    # Open Serial connection
        ser = serial.Serial('/dev/ttyUSB1',115200,rtscts=True,dsrdtr=True)

    # SETTING UP Novatel to take RTCM correction
        ser.write('INTERFACEMODE USB2 RTCM NOVATEL ON\r\n')
        ser.write('INSCOMMAND ENABLE\r')
        ser.write('LOG USB1 INSPVA ONTIME \r\n')
        ser.write(RTCM)

    rospy.spin()

if __name__ == '__main__':
    rtcm_subscriber()
    
