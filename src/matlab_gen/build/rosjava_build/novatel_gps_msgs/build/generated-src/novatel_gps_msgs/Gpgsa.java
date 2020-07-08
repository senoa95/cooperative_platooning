package novatel_gps_msgs;

public interface Gpgsa extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Gpgsa";
  static final java.lang.String _DEFINITION = "# Message from GPGSA NMEA String\nHeader header\n\nstring message_id\n\nstring auto_manual_mode\nuint8 fix_mode\n\nuint8[] sv_ids\n\nfloat32 pdop\nfloat32 hdop\nfloat32 vdop";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  java.lang.String getMessageId();
  void setMessageId(java.lang.String value);
  java.lang.String getAutoManualMode();
  void setAutoManualMode(java.lang.String value);
  byte getFixMode();
  void setFixMode(byte value);
  org.jboss.netty.buffer.ChannelBuffer getSvIds();
  void setSvIds(org.jboss.netty.buffer.ChannelBuffer value);
  float getPdop();
  void setPdop(float value);
  float getHdop();
  void setHdop(float value);
  float getVdop();
  void setVdop(float value);
}
