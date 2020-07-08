package novatel_gps_msgs;

public interface NovatelPsrdop2 extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/NovatelPsrdop2";
  static final java.lang.String _DEFINITION = "# PSR Dilution of Precision (DOP) values\nstd_msgs/Header header\n\nNovatelMessageHeader novatel_msg_header\n\n# Geometry dilution of precision\nfloat32 gdop\n# Position dilution of precision\nfloat32 pdop\n# Horizontal dilution of precision\nfloat32 hdop\n# Vertical dilution of precision\nfloat32 vdop\n\n# Time dilution of precision for each GNSS system\nNovatelPsrdop2System[] systems\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  novatel_gps_msgs.NovatelMessageHeader getNovatelMsgHeader();
  void setNovatelMsgHeader(novatel_gps_msgs.NovatelMessageHeader value);
  float getGdop();
  void setGdop(float value);
  float getPdop();
  void setPdop(float value);
  float getHdop();
  void setHdop(float value);
  float getVdop();
  void setVdop(float value);
  java.util.List<novatel_gps_msgs.NovatelPsrdop2System> getSystems();
  void setSystems(java.util.List<novatel_gps_msgs.NovatelPsrdop2System> value);
}
