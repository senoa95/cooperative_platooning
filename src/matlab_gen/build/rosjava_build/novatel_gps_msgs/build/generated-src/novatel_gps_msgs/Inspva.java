package novatel_gps_msgs;

public interface Inspva extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Inspva";
  static final java.lang.String _DEFINITION = "# INS Position, Velocity, and Attitude\n\nHeader header\n\nNovatelMessageHeader novatel_msg_header\n\nuint32 week\nfloat64 seconds\nfloat64 latitude\nfloat64 longitude\nfloat64 height\nfloat64 north_velocity\nfloat64 east_velocity\nfloat64 up_velocity\nfloat64 roll\nfloat64 pitch\nfloat64 azimuth\nstring status\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  novatel_gps_msgs.NovatelMessageHeader getNovatelMsgHeader();
  void setNovatelMsgHeader(novatel_gps_msgs.NovatelMessageHeader value);
  int getWeek();
  void setWeek(int value);
  double getSeconds();
  void setSeconds(double value);
  double getLatitude();
  void setLatitude(double value);
  double getLongitude();
  void setLongitude(double value);
  double getHeight();
  void setHeight(double value);
  double getNorthVelocity();
  void setNorthVelocity(double value);
  double getEastVelocity();
  void setEastVelocity(double value);
  double getUpVelocity();
  void setUpVelocity(double value);
  double getRoll();
  void setRoll(double value);
  double getPitch();
  void setPitch(double value);
  double getAzimuth();
  void setAzimuth(double value);
  java.lang.String getStatus();
  void setStatus(java.lang.String value);
}
