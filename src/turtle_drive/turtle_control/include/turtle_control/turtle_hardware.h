/**
 *
 *  \file
 *  \brief      Class representing Jackal hardware
 *  \author     Mike Purvis <mpurvis@clearpathrobotics.com>
 *  \copyright  Copyright (c) 2013, Clearpath Robotics, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Clearpath Robotics, Inc. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL CLEARPATH ROBOTICS, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Please send comments, questions, or patches to code@clearpathrobotics.com
 *
 */

#ifndef TURTLE_BASE_TURTLE_HARDWARE_H
#define TURTLE_BASE_TURTLE_HARDWARE_H

#include "boost/thread.hpp"
#include "hardware_interface/joint_state_interface.h"
#include "hardware_interface/joint_command_interface.h"
#include "hardware_interface/robot_hw.h"
#include "ros/ros.h"
#include "sensor_msgs/JointState.h"
#include "roboteq_msgs/Feedback.h"
#include "roboteq_msgs/Command.h"
#include "tf/tf.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Point.h"
#include "sensor_msgs/Joy.h"
#include "math.h"

namespace turtle_control
{

class TurtleHardware : public hardware_interface::RobotHW
{
public:
  TurtleHardware();
  void copyJointsFromHardware();
  void publishDriveFromController();
  
private:
  void feedbackCallback_left(const roboteq_msgs::Feedback msg);
  void feedbackCallback_right(const roboteq_msgs::Feedback msg);
  void cmdvelCallback(const geometry_msgs::Twist msg);

  ros::NodeHandle nh_;
  ros::Subscriber left_feedback_sub_;
  ros::Publisher left_motor_pub;
  ros::Subscriber right_feedback_sub_;
  ros::Subscriber cmd_vel_sub_;
  ros::Publisher right_motor_pub;
  

  hardware_interface::JointStateInterface joint_state_interface_;
  hardware_interface::VelocityJointInterface velocity_joint_interface_;

  // These are mutated on the controls thread only.
  struct Joint
  {
    double position;
    double velocity;
    double effort;
    double velocity_command;

    Joint() : position(0), velocity(0), effort(0), velocity_command(0)
    {
    }
  }
  joints_[4];

  // This pointer is set from the ROS thread.
  roboteq_msgs::Feedback left_feedback_msg_;
  roboteq_msgs::Feedback right_feedback_msg_;
  boost::mutex left_feedback_msg_mutex_;
  boost::mutex right_feedback_msg_mutex_;

  struct VelocityCommand
  {
    float linearX;
    float linearY;
    float linearZ;
    float angularX;
    float angularY;
    float angularZ;

    VelocityCommand() : linearX(0), linearY(0), linearZ(0), angularX(0), angularY(), angularZ()
    {
    }
  }
  velocity_cmd_;
  geometry_msgs::Twist cmd_vel_msg_;
  boost::mutex cmd_vel_msg_mutex_;
};

}

#endif
