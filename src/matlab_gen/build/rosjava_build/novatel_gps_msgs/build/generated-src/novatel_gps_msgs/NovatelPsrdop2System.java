package novatel_gps_msgs;

public interface NovatelPsrdop2System extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/NovatelPsrdop2System";
  static final java.lang.String _DEFINITION = "# GNSS System information provided by PSRDOP2 logs\nstring system\nfloat32 tdop\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  java.lang.String getSystem();
  void setSystem(java.lang.String value);
  float getTdop();
  void setTdop(float value);
}
