#include "novatel_gps_msgs/NovatelCorrectedImuData.h"
#include "novatel_gps_msgs/Inspva.h"
#include "novatel_gps_msgs/Insstdev.h"

corrimudata_sub_ = nh_.subscribe("/corrimudata", 1, &TurtleHardware::corrimudataCallback, this);
inspva_sub_ = nh_.subscribe("/inspva", 1, &TurtleHardware::inspvaCallback, this);
insstdev_sub_ = nh_.subscribe("/insstdev", 1, &TurtleHardware::insstdevCallback, this);
compiled_imu_pub = nh_.advertise<sensor_msgs::Imu>("/compiled_imu", 1000);

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

void TurtleHardware::subscribeToImu()
{
  boost::mutex::scoped_lock corrimudata_msg_lock(corrimudata_msg_mutex_, boost::try_to_lock);
  sensor_msgs::Imu imu_msg;
  int imu_rate_ = 20;
  float deg2rad = M_PI / 180;
  corrimudata_.pitch_rate = corrimudata_msg_.pitch_rate * imu_rate_;
  corrimudata_.roll_rate = corrimudata_msg_.roll_rate * imu_rate_;
  corrimudata_.yaw_rate = corrimudata_msg_.yaw_rate * imu_rate_;
  corrimudata_.lateral_acceleration = corrimudata_msg_.lateral_acceleration;
  corrimudata_.longitudinal_acceleration = corrimudata_msg_.longitudinal_acceleration;
  corrimudata_.vertical_acceleration = corrimudata_msg_.vertical_acceleration;
  boost::mutex::scoped_lock inspva_data_msg_lock(inspva_data_msg_mutex_, boost::try_to_lock);
  inspva_data_.pitch = inspva_data_msg_.pitch;
  inspva_data_.roll = inspva_data_msg_.roll;
  inspva_data_.azimuth = inspva_data_msg_.azimuth;
  inspva_data_.x_vel = inspva_data_msg_.north_velocity;
  inspva_data_.y_vel = inspva_data_msg_.east_velocity;
  inspva_data_.z_vel = inspva_data_msg_.up_velocity;

  imu_msg.header.stamp = ros::Time::now();
  imu_msg.header.frame_id = "base_link";
  imu_msg.orientation = tf::createQuaternionMsgFromRollPitchYaw(inspva_data_.roll * deg2rad,
                                                -(inspva_data_.pitch) * deg2rad,
                                                -(inspva_data_.azimuth) * deg2rad);
  imu_msg.orientation_covariance[0] = pow(insstdev_data_.pitch_dev, 2);
  imu_msg.orientation_covariance[4] =pow(insstdev_data_.roll_dev, 2);
  imu_msg.orientation_covariance[8] = pow(insstdev_data_.azimuth_dev, 2);
  imu_msg.angular_velocity.x = corrimudata_.roll_rate;
  imu_msg.angular_velocity.y = corrimudata_.pitch_rate;
  imu_msg.angular_velocity.z = corrimudata_.yaw_rate;
  imu_msg.angular_velocity_covariance[0] =
  imu_msg.angular_velocity_covariance[4] =
  imu_msg.angular_velocity_covariance[8] = 1e-3;
  imu_msg.linear_acceleration.x = corrimudata_.lateral_acceleration;
  imu_msg.linear_acceleration.y = corrimudata_.longitudinal_acceleration;
  imu_msg.linear_acceleration.z = corrimudata_.vertical_acceleration;
  imu_msg.linear_acceleration_covariance[0] =
  imu_msg.linear_acceleration_covariance[4] =
  imu_msg.linear_acceleration_covariance[8] = 1e-3;
  compiled_imu_pub.publish(imu_msg);
}
