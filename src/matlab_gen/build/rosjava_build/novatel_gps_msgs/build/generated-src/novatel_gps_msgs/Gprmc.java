package novatel_gps_msgs;

public interface Gprmc extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Gprmc";
  static final java.lang.String _DEFINITION = "# Message from GPRMC NMEA String\nHeader header\n\nstring message_id\n\nfloat64 utc_seconds\nstring position_status\n\nfloat64 lat\nfloat64 lon\n\nstring lat_dir\nstring lon_dir\n\nfloat32 speed\nfloat32 track\nstring date\nfloat32 mag_var\nstring mag_var_direction\nstring mode_indicator";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  java.lang.String getMessageId();
  void setMessageId(java.lang.String value);
  double getUtcSeconds();
  void setUtcSeconds(double value);
  java.lang.String getPositionStatus();
  void setPositionStatus(java.lang.String value);
  double getLat();
  void setLat(double value);
  double getLon();
  void setLon(double value);
  java.lang.String getLatDir();
  void setLatDir(java.lang.String value);
  java.lang.String getLonDir();
  void setLonDir(java.lang.String value);
  float getSpeed();
  void setSpeed(float value);
  float getTrack();
  void setTrack(float value);
  java.lang.String getDate();
  void setDate(java.lang.String value);
  float getMagVar();
  void setMagVar(float value);
  java.lang.String getMagVarDirection();
  void setMagVarDirection(java.lang.String value);
  java.lang.String getModeIndicator();
  void setModeIndicator(java.lang.String value);
}
