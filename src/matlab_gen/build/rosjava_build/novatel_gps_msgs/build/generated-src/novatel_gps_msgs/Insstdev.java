package novatel_gps_msgs;

public interface Insstdev extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Insstdev";
  static final java.lang.String _DEFINITION = "# INS PVA standard deviations\n\nHeader header\n\nNovatelMessageHeader novatel_msg_header\n\nfloat32 latitude_dev\nfloat32 longitude_dev\nfloat32 height_dev\nfloat32 north_velocity_dev\nfloat32 east_velocity_dev\nfloat32 up_velocity_dev\nfloat32 roll_dev\nfloat32 pitch_dev\nfloat32 azimuth_dev\nNovatelExtendedSolutionStatus extended_solution_status\nuint16 time_since_update\n\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  novatel_gps_msgs.NovatelMessageHeader getNovatelMsgHeader();
  void setNovatelMsgHeader(novatel_gps_msgs.NovatelMessageHeader value);
  float getLatitudeDev();
  void setLatitudeDev(float value);
  float getLongitudeDev();
  void setLongitudeDev(float value);
  float getHeightDev();
  void setHeightDev(float value);
  float getNorthVelocityDev();
  void setNorthVelocityDev(float value);
  float getEastVelocityDev();
  void setEastVelocityDev(float value);
  float getUpVelocityDev();
  void setUpVelocityDev(float value);
  float getRollDev();
  void setRollDev(float value);
  float getPitchDev();
  void setPitchDev(float value);
  float getAzimuthDev();
  void setAzimuthDev(float value);
  novatel_gps_msgs.NovatelExtendedSolutionStatus getExtendedSolutionStatus();
  void setExtendedSolutionStatus(novatel_gps_msgs.NovatelExtendedSolutionStatus value);
  short getTimeSinceUpdate();
  void setTimeSinceUpdate(short value);
}
