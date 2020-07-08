package novatel_gps_msgs;

public interface Gphdt extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Gphdt";
  static final java.lang.String _DEFINITION = "# Message from GPHDT NMEA String\nHeader header\n\nstring message_id\n\n# Heading in degrees (clockwise)\nfloat64 heading\n\n# T: Indicates heading relative to True North\nstring t";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  java.lang.String getMessageId();
  void setMessageId(java.lang.String value);
  double getHeading();
  void setHeading(double value);
  java.lang.String getT();
  void setT(java.lang.String value);
}
