package novatel_gps_msgs;

public interface Range extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Range";
  static final java.lang.String _DEFINITION = "#Satellite Range information from Novatel OEM6 receiver\n\nHeader header\n\nNovatelMessageHeader novatel_msg_header\n\n#number of observations\nint32 numb_of_observ\n\n#range information for the observed \nRangeInformation[] info\n\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  novatel_gps_msgs.NovatelMessageHeader getNovatelMsgHeader();
  void setNovatelMsgHeader(novatel_gps_msgs.NovatelMessageHeader value);
  int getNumbOfObserv();
  void setNumbOfObserv(int value);
  java.util.List<novatel_gps_msgs.RangeInformation> getInfo();
  void setInfo(java.util.List<novatel_gps_msgs.RangeInformation> value);
}
