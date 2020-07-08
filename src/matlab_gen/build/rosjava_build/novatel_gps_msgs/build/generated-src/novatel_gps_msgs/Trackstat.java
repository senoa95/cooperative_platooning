package novatel_gps_msgs;

public interface Trackstat extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Trackstat";
  static final java.lang.String _DEFINITION = "# Channel tracking status information for each of the receiver parallel channels\n\nHeader header\n\nstring solution_status\nstring position_type\n\n# Tracking elevation cutff-off angle\nfloat32 cutoff\n\nTrackstatChannel[] channels";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  java.lang.String getSolutionStatus();
  void setSolutionStatus(java.lang.String value);
  java.lang.String getPositionType();
  void setPositionType(java.lang.String value);
  float getCutoff();
  void setCutoff(float value);
  java.util.List<novatel_gps_msgs.TrackstatChannel> getChannels();
  void setChannels(java.util.List<novatel_gps_msgs.TrackstatChannel> value);
}
