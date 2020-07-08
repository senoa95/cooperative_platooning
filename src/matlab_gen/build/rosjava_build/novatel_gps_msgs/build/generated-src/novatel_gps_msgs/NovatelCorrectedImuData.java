package novatel_gps_msgs;

public interface NovatelCorrectedImuData extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/NovatelCorrectedImuData";
  static final java.lang.String _DEFINITION = "# Parsed corrected IMU data from Novatel OEM6 receiver\nHeader header\n\nNovatelMessageHeader novatel_msg_header\n\nuint32 gps_week_num\nfloat64 gps_seconds\n\n# All measurements in this message are instantaneous values;\n# attitude rate is in radians\nfloat64 pitch_rate\nfloat64 roll_rate\nfloat64 yaw_rate\n\n# accelerations are in m/s\nfloat64 lateral_acceleration\nfloat64 longitudinal_acceleration\nfloat64 vertical_acceleration\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  novatel_gps_msgs.NovatelMessageHeader getNovatelMsgHeader();
  void setNovatelMsgHeader(novatel_gps_msgs.NovatelMessageHeader value);
  int getGpsWeekNum();
  void setGpsWeekNum(int value);
  double getGpsSeconds();
  void setGpsSeconds(double value);
  double getPitchRate();
  void setPitchRate(double value);
  double getRollRate();
  void setRollRate(double value);
  double getYawRate();
  void setYawRate(double value);
  double getLateralAcceleration();
  void setLateralAcceleration(double value);
  double getLongitudinalAcceleration();
  void setLongitudinalAcceleration(double value);
  double getVerticalAcceleration();
  void setVerticalAcceleration(double value);
}
