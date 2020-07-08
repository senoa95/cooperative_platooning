package novatel_gps_msgs;

public interface Inscov extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Inscov";
  static final java.lang.String _DEFINITION = "# INS Covariance Matrices\n\nHeader header\n\nNovatelMessageHeader novatel_msg_header\n\nuint32 week\nfloat64 seconds\nfloat64[9] position_covariance\nfloat64[9] attitude_covariance\nfloat64[9] velocity_covariance\n";
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
  double[] getPositionCovariance();
  void setPositionCovariance(double[] value);
  double[] getAttitudeCovariance();
  void setAttitudeCovariance(double[] value);
  double[] getVelocityCovariance();
  void setVelocityCovariance(double[] value);
}
