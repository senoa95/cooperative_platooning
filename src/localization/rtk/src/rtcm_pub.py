#!/usr/bin/env python

import rospy
import serial
import socket
from socket import error as socket_error
from std_msgs.msg import String as type

def rtcm_broadcast():
    ###Define publisher
    pub = rospy.Publisher('rtcm', type, queue_size=10)
    rospy.init_node('rtcm_broadcast', anonymous='True')
    rate = rospy.Rate(10) 

    ###Trimble TCP Connection Initialization
    TCP_IP = '192.168.1.4'

    TCP_PORT = 5017 #this is the port number inside the trimble configuration

    BUFFER_SIZE = 4096

    # Open TCP Socket
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
    s.connect((TCP_IP, TCP_PORT))

    while not rospy.is_shutdown():
        #Recieve RTCM and write RTCM data to serial
        RTCM = s.recv(BUFFER_SIZE)
        pub.publish(RTCM)
        rate.sleep()

if __name__ == '__main__':
    try:
        rtcm_broadcast()
    except rospy.ROSInterruptException:
        pass


