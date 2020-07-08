package novatel_gps_msgs;

public interface Gpgsv extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Gpgsv";
  static final java.lang.String _DEFINITION = "# Total number of satellites in view and data about satellites\n# Because the NMEA sentence is limited to 4 satellites per message, several\n# of these messages may need to be synthesized to get data about all visible\n# satellites.\n\nHeader header\n\nstring message_id\n\n# Number of messages in this sequence\nuint8 n_msgs\n# This messages number in its sequence. The first message is number 1.\nuint8 msg_number\n\n# Number of satellites currently visible\nuint8 n_satellites\n\n# Up to 4 satellites are described in each message\nSatellite[] satellites";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  java.lang.String getMessageId();
  void setMessageId(java.lang.String value);
  byte getNMsgs();
  void setNMsgs(byte value);
  byte getMsgNumber();
  void setMsgNumber(byte value);
  byte getNSatellites();
  void setNSatellites(byte value);
  java.util.List<novatel_gps_msgs.Satellite> getSatellites();
  void setSatellites(java.util.List<novatel_gps_msgs.Satellite> value);
}
