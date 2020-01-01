#include <boost/thread.hpp>
#include <boost/chrono.hpp>

#include "controller_manager/controller_manager.h"
#include "imu_extractor_node/imu_extractor_node_helper.h"
#include "ros/ros.h"
#include <iostream>

typedef boost::chrono::steady_clock time_source;

void controlThread(ros::Rate rate, imu_extractor_node_helper::TurtleHardware* robot, controller_manager::ControllerManager* cm)
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

    cm->update(ros::Time::now(), elapsed);
    robot->subscribeToImu();
    rate.sleep();
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