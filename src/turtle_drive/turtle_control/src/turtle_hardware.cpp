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

#include <boost/assign.hpp>
#include "turtle_control/turtle_hardware.h"
#include <iostream>

namespace turtle_control
{

TurtleHardware::TurtleHardware()
{
  ros::V_string joint_names = boost::assign::list_of("front_left_wheel")
      ("front_right_wheel")("rear_left_wheel")("rear_right_wheel");

  for (unsigned int i = 0; i < joint_names.size(); i++) {
    hardware_interface::JointStateHandle joint_state_handle(joint_names[i],
        &joints_[i].position, &joints_[i].velocity, &joints_[i].effort);
    joint_state_interface_.registerHandle(joint_state_handle);

    hardware_interface::JointHandle joint_handle(
        joint_state_handle, &joints_[i].velocity_command);
    velocity_joint_interface_.registerHandle(joint_handle);
  }
  registerInterface(&joint_state_interface_);
  registerInterface(&velocity_joint_interface_);

  left_feedback_sub_ = nh_.subscribe("left/feedback", 1, &TurtleHardware::feedbackCallback_left, this);
  right_feedback_sub_ = nh_.subscribe("right/feedback", 1, &TurtleHardware::feedbackCallback_right, this);
  
  cmd_vel_sub_ = nh_.subscribe("/turtle_velocity_controller/cmd_vel", 1, &TurtleHardware::cmdvelCallback, this);
  left_motor_pub = nh_.advertise<roboteq_msgs::Command>("/left/cmd", 1000);
  right_motor_pub = nh_.advertise<roboteq_msgs::Command>("/right/cmd", 1000);
}

/**
 * Populates the internal joint state struct from the most recent Feedback message
 * received from the MCU.
 *
 * Called from the controller thread.
 */
void TurtleHardware::copyJointsFromHardware()
{
  boost::mutex::scoped_lock left_feedback_msg_lock(left_feedback_msg_mutex_, boost::try_to_lock);
      joints_[0].position = -(left_feedback_msg_.measured_position/20);
      joints_[0].velocity = -(left_feedback_msg_.measured_velocity/20);
      joints_[0].effort = 0;  // TODO(mikepurvis): determine this from amperage data.
      joints_[2].position = -(left_feedback_msg_.measured_position/20);
      joints_[2].velocity = -(left_feedback_msg_.measured_velocity/20);
      joints_[2].effort = 0;  // TODO(mikepurvis): determine this from amperage data
  boost::mutex::scoped_lock right_feedback_msg_lock(right_feedback_msg_mutex_, boost::try_to_lock);
      joints_[1].position = right_feedback_msg_.measured_position/20;
      joints_[1].velocity = right_feedback_msg_.measured_velocity/20;
      joints_[1].effort = 0;  // TODO(mikepurvis): determine this from amperage data.
      joints_[3].position = right_feedback_msg_.measured_position/20;
      joints_[3].velocity = right_feedback_msg_.measured_velocity/20;
      joints_[3].effort = 0;  // TODO(mikepurvis): determine this from amperage data.
  }

/**
 * Populates and publishes Drive message based on the controller outputs.
 *
 * Called from the controller thread.
 */
void TurtleHardware::publishDriveFromController()
{
	roboteq_msgs::Command left_msg;
  roboteq_msgs::Command right_msg;

  double L = 0.7; //0.7 meters wheel separation
  double R = 0.41; //0.41 meter diameter

  left_msg.mode=0;
  right_msg.mode=0;

  left_msg.setpoint = (2*cmd_vel_msg_.linear.x - L*cmd_vel_msg_.angular.z)/2;
  right_msg.setpoint = (2*cmd_vel_msg_.linear.x + L*cmd_vel_msg_.angular.z)/2;

	// left_msg.setpoint=(-joints_[0].velocity_command)*.9091*20;
	// right_msg.setpoint=(joints_[3].velocity_command)*.9091*20;
  left_motor_pub.publish(left_msg);
  right_motor_pub.publish(right_msg);
}

void TurtleHardware::feedbackCallback_left(const roboteq_msgs::Feedback msg)
{
  // Update the feedback message pointer to point to the current message. Block
  // until the control thread is not using the lock.
  boost::mutex::scoped_lock left_lock(left_feedback_msg_mutex_);
  left_feedback_msg_ = msg;

}

void TurtleHardware::feedbackCallback_right(const roboteq_msgs::Feedback msg)
{
  // Update the feedback message pointer to point to the current message. Block
  // until the control thread is not using the lock.
  boost::mutex::scoped_lock right_lock(right_feedback_msg_mutex_);
  right_feedback_msg_ = msg;
}

void TurtleHardware::cmdvelCallback(const geometry_msgs::Twist msg)
{

  boost::mutex::scoped_lock cmdvel_lock(cmd_vel_msg_mutex_);
  cmd_vel_msg_ = msg;
}
}
