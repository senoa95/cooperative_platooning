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
#include "sensor_msgs/Imu.h"
#include "roboteq_msgs/Feedback.h"
#include "roboteq_msgs/Command.h"
#include "novatel_gps_msgs/NovatelCorrectedImuData.h"
#include "novatel_gps_msgs/Inspva.h"
#include "novatel_gps_msgs/Insstdev.h"
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
  void subscribeToImu();
  void publishDriveFromMath();


private:
  void feedbackCallback_left(const roboteq_msgs::Feedback msg);
  void feedbackCallback_right(const roboteq_msgs::Feedback msg);
  void corrimudataCallback(const novatel_gps_msgs::NovatelCorrectedImuData msg);
  void inspvaCallback(const novatel_gps_msgs::Inspva msg);
  void insstdevCallback(const novatel_gps_msgs::Insstdev msg);
  void cmdvelCallback(const geometry_msgs::Twist msg);

  ros::NodeHandle nh_;
  ros::Subscriber left_feedback_sub_;
  ros::Publisher left_motor_pub;
  ros::Subscriber right_feedback_sub_;
  ros::Publisher right_motor_pub;
  ros::Subscriber corrimudata_sub_;
  ros::Subscriber inspva_sub_;
  ros::Subscriber insstdev_sub_;
  ros::Publisher compiled_imu_pub;
  ros::Subscriber cmd_vel_sub_;

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

  struct InspvaData
  {
    float pitch;
    float roll;
    float azimuth;
    float x_vel;
    float y_vel;
    float z_vel;

    InspvaData() : pitch(0), roll(0), azimuth(0), x_vel(0), y_vel(0), z_vel(0)
    {
    }
  }
  inspva_data_;
  novatel_gps_msgs::Inspva inspva_data_msg_;
  boost::mutex inspva_data_msg_mutex_;

  struct Insstdev
  {
    float roll_dev;
    float pitch_dev;
    float azimuth_dev;

    Insstdev() : roll_dev(0), pitch_dev(0), azimuth_dev(0)
    {
    }
  }
  insstdev_data_;
  novatel_gps_msgs::Insstdev insstdev_data_msg_;
  boost::mutex insstdev_data_msg_mutex_;


  struct Corrimudata
  {
    float pitch_rate;
    float roll_rate;
    float yaw_rate;
    float lateral_acceleration;
    float longitudinal_acceleration;
    float vertical_acceleration;

    Corrimudata() : pitch_rate(0), roll_rate(0), yaw_rate(0),
    lateral_acceleration(0), longitudinal_acceleration(0), vertical_acceleration(0)
    {
    }
  }
  corrimudata_;
  novatel_gps_msgs::NovatelCorrectedImuData corrimudata_msg_;
  boost::mutex corrimudata_msg_mutex_;

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
