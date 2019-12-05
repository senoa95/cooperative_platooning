/**
 *
 *  \file
 *  \brief      Main entry point for jackal base.
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

#include <boost/thread.hpp>
#include <boost/chrono.hpp>

#include "controller_manager/controller_manager.h"
#include "turtle_control/turtle_hardware.h"
#include "ros/ros.h"
#include <iostream>

typedef boost::chrono::steady_clock time_source;

void controlThread(ros::Rate rate, turtle_control::TurtleHardware* robot, controller_manager::ControllerManager* cm)
{
  time_source::time_point last_time = time_source::now();
  std::string odom_type;

  while (1)
  {
    // Calculate monotonic time elapsed
    time_source::time_point this_time = time_source::now();
    boost::chrono::duration<double> elapsed_duration = this_time - last_time;
    ros::Duration elapsed(elapsed_duration.count());
    last_time = this_time;
    ros::param::set(odom_type, "imu");

    robot->copyJointsFromHardware();
    cm->update(ros::Time::now(), elapsed);
    robot->subscribeToImu();
    rate.sleep();

    // if (ros::param::get("encoders", odom_type))
    // {
      robot->publishDriveFromController();
    // }
    // else if (ros::param::get("imu", odom_type))
    // {
      // robot->publishDriveFromMath();
    // }
  }
}

int main(int argc, char* argv[])
{
  // Initialize ROS node.
  ros::init(argc, argv, "turtle_control");
  turtle_control::TurtleHardware leonardo;

   // Background thread for the controls callback.
  ros::NodeHandle controller_nh("");
  controller_manager::ControllerManager cm(&leonardo, controller_nh);
  boost::thread(boost::bind(controlThread, ros::Rate(50), &leonardo, &cm));

  // Foreground ROS spinner for ROS callbacks, including rosserial, diagnostics
  ros::spin();

  return 0;
}
