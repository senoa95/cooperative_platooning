import numpy
import math
import utm

#class to define vehicle position on a coordinate system at a certain heading
class Point:

    def __init__(self,inputX = 0,inputY = 0,inputHeading = 0):
        self.x = inputX
        self.y = inputY
        self.heading = inputHeading


# class to define vehicle parameters
class AckermannVehicle:
    def __init__(self,inputLength = 2.065,inputMinTurningRadius = 4.6,inputMaximumVelocity = 0.5):
        self.length = inputLength
        self.maximumVelocity = inputMaximumVelocity
        # self.minTurningRadius = self.length / math.tan(self.maximumSteeringAngle)
        self.minTurningRadius = inputMinTurningRadius

class DiffDriveVehicle:
    def __init__(self, inputLength=1,inputMinTurningRadius = 0.0,inputTireDiameter=1,inputMaximumVelocity=3):
        self.length = inputLength
        self.minTurningRadius = inputMinTurningRadius
        self.tireDiameter = inputTireDiameter
        self.maximumVelocity = inputMaximumVelocity


# class to define Pure pursuit controller parameters
class PPController:

    # Constructor:
    def __init__(self,inputLeadDistance,inputLength = 2.065, inputMinTurningRadius = 4.6, inputMaximumVelocity = 0.5):
        self.leadDistance = inputLeadDistance
        self.length = inputLength #set the length for ppcontroller as the length of maximumSteeringAngle
        self.turningRadius = inputMinTurningRadius
        self.maximumVelocity = inputMaximumVelocity
        self.prevHeadingErr = 0

        # List of waypoints: From start to end:
        self.wpList = []

        # Current target waypoint index:
        self.currWpIdx = 0

        # List of desired heading values:
        self.tgtHeading = []

        # List of normal vectors to segments joining the waypoints:
        self.segNormVecList = None

        # Number of waypoints:
        self.nPts = 0

        # Tuning gains:
        self.k_theta = 2.5

        self.k_delta_p = 1.0
        self.k_delta_i = 0.1
        self.k_delta_d = 1.5

        self.k_vel = 0.1

    # Initialize the controller from a text file containing the waypoints:
    def initialize(self, wpList):
      
        self.wpList = wpList
        self.nPts = len(wpList)
        self.segNormVecList = numpy.zeros((2,self.nPts))

        self.tgtHeading.append(0)

        # Loop to compute the target heading values:
        for idx in range(0, len(self.wpList)-1):

            self.tgtHeading.append( numpy.arctan2( self.wpList[idx + 1].y - self.wpList[idx].y , self.wpList[idx+1].x - self.wpList[idx].x))

            normX = self.wpList[idx].y - self.wpList[idx + 1].y
            normY = self.wpList[idx + 1].x - self.wpList[idx].x     #bug might live here

            # Calculate the norm:
            nVecMag = numpy.sqrt( normX**2 + normY**2)

            self.segNormVecList[0,idx+1] = normX/nVecMag
            self.segNormVecList[1,idx+1] = normY/nVecMag

        self.tgtHeading[0] = self.tgtHeading[1]
        self.segNormVecList[:,0] = self.segNormVecList[:,1]

    # Function to compute steering angle and forward velocity commands:
    def compute_steering_vel_cmds(self,current, maxVel):

        # Compute vector from current position to current waypoint:
        vecRobot2Wp = numpy.zeros((2,1))
        vecRobot2Wp[0,0] =  self.wpList[self.currWpIdx].x - current.x
        vecRobot2Wp[1,0] =  self.wpList[self.currWpIdx].y - current.y

        # Compute the minimum distance from the current segment:
        minDist = numpy.dot(vecRobot2Wp.T, self.segNormVecList[:,self.currWpIdx])
        a = self.segNormVecList[:,:]
        b = self.currWpIdx
        theta_gain = self.k_theta * minDist
        if theta_gain > math.pi/2:
            theta_gain = math.pi/2
        if theta_gain < -math.pi/2:
            theta_gain = -math.pi/2

        currentGoal_x = self.wpList[self.currWpIdx].x
        currentGoal_y = self.wpList[self.currWpIdx].y

        # Compute the desired heading angle based of target heading and the min dist:
        theta_des = self.tgtHeading[self.currWpIdx] + theta_gain
        heading_err = theta_des - current.heading
        if heading_err > math.pi:
            heading_err = heading_err - 2*math.pi
        elif heading_err < -math.pi:
            heading_err = heading_err + 2*math.pi

        deltaHeadingErr = heading_err - self.prevHeadingErr


        delta_p = self.k_delta_p*heading_err
        delta_i = self.k_delta_i*(heading_err + self.prevHeadingErr)
        delta_d = self.k_delta_d*(heading_err - self.prevHeadingErr)

        self.prevHeadingErr = heading_err

        delta = delta_p + delta_i + delta_d

        vel = maxVel
                
        # Debugging section:
        # print('delta =', delta)
        # print('previous heading error', self.prevHeadingErr)
        # print('heading error', heading_err)
        # print (" Minimum Dist = ", minDist)
        # print(" Target heading = ", self.tgtHeading[self.currWpIdx] )
        # print (" Current heading = " , current.heading)
        # print (" Desired Theta = ", theta_des)
        # print("theta gain = ", theta_gain)
        # print("minDist = ", minDist)
        # print("vecRobot2Wp = ", vecRobot2Wp)
        return vel,delta

    # compute the steering radius of ackerman vehicle of given parameters
    def compute_turning_radius(self, current = Point(0,0,0) , goal = Point(0,0,0)):

        current = inputCurrent
        goal = inputGoal
        beta = math.atan2((goal.y - current.y),(goal.x-current.y)) # angle between line joining start-end and x axis
        temp = ((current.heading +  3.14))
        temp = (math.fmod(temp , 2*3.14)) - 3.14
        self.alpha = temp - beta #angle between current heading and the line joining start-end
        L_a = math.sqrt(math.pow((goal.x - current.x),2) + math.pow((goal.y-current.y),2))
        self.turningRadius = L_a / (2*math.sin(alpha)) #this outputs the turning radius

# compute the steering angle of ackermann vehicle of given paramters
    def compute_steering_angle(self):

        # Steering angle command from Pure pursuit paper:
        steeringAngle = math.atan(self.length / self.turningRadius)
        omega = self.alpha
        return omega
