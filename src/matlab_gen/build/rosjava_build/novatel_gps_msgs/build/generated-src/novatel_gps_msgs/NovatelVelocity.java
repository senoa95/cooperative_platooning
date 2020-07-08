package novatel_gps_msgs;

public interface NovatelVelocity extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/NovatelVelocity";
  static final java.lang.String _DEFINITION = "# Parsed Best Position or Omnistar XP or HP pos data from Novatel OEM6 receiver\nHeader header\n\nNovatelMessageHeader novatel_msg_header\n\nstring solution_status\nstring velocity_type\n\n# A measure of the latency in the velocity time tag in seconds.\nfloat32 latency\n\n# Differential age in seconds\nfloat32 age\n\n# Horizontal speed over ground, meters/second\nfloat64 horizontal_speed\n\n# Direction of motion over ground with respect to true North, degrees\nfloat64 track_ground\n\n# Vertical speed, where positive values correspond to increasing altitude, meters/second\nfloat64 vertical_speed";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  novatel_gps_msgs.NovatelMessageHeader getNovatelMsgHeader();
  void setNovatelMsgHeader(novatel_gps_msgs.NovatelMessageHeader value);
  java.lang.String getSolutionStatus();
  void setSolutionStatus(java.lang.String value);
  java.lang.String getVelocityType();
  void setVelocityType(java.lang.String value);
  float getLatency();
  void setLatency(float value);
  float getAge();
  void setAge(float value);
  double getHorizontalSpeed();
  void setHorizontalSpeed(double value);
  double getTrackGround();
  void setTrackGround(double value);
  double getVerticalSpeed();
  void setVerticalSpeed(double value);
}
