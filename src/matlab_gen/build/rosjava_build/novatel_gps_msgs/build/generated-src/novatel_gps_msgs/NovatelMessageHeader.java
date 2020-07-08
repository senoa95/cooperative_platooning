package novatel_gps_msgs;

public interface NovatelMessageHeader extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/NovatelMessageHeader";
  static final java.lang.String _DEFINITION = "# Novatel Message Header\n\nstring message_name\nstring port\nuint32 sequence_num\nfloat32 percent_idle_time\nstring gps_time_status\nuint32 gps_week_num\nfloat64 gps_seconds\n\n# Bit       Mask      Description\n#  0     0x00000001   Error flag (Bit = 0: No Error, Bit = 1: Error)\n#  1     0x00000002   Temperature Status (0: Within Spec, 1: Warning)\n#  2     0x00000004   Voltage Supply Status (0: OK, 1: Warning)\n#  3     0x00000008   Antenna Power Status (0: Powered, 1: Not Powered)\n#  4     0x00000010   <Reserved>\n#  5     0x00000020   Antenna open flag (0: OK, 1: Open)\n#  6     0x00000040   Antenna shorted flag (0: OK, 1: Shorted)\n#  7     0x00000080   CPU overload flag\n#  8     0x00000100   COM1 buffer overrun flag (0: No overrun, 1: Overrun)\n#  9     0x00000200   COM2 buffer overrun flag (0: No overrun, 1: Overrun)\n#  10    0x00000400   COM3 buffer overrun flag (0: No overrun, 1: Overrun)\n#  11    0x00000800   USB buffer overrun flag (0: No overrun, 1: Overrun)\n#  12    0x00001000   <Reserved>\n#  13    0x00002000   <Reserved>\n#  14    0x00004000   <Reserved>\n#  15    0x00008000   RF1 AGC Status (0: OK, 1: Bad)\n#  16    0x00010000   <Reserverd>\n#  17    0x00020000   RF2 AGC status (0: OK, 1: Bad)\n#  18    0x00040000   Almanac flag/UTC known (0: Valid, 1: Invalid)\n#  19    0x00080000   Position solution flag (0: Valid, 1: Invalid)\n#  20    0x00100000   Position fixed flag (0: Not fixed, 1: Fixed)\n#  21    0x00200000   Clock steering status (0: Enabled, 1: Disabled)\n#  22    0x00400000   Clock model flag (0: Valid, 1: Invalid)\n#  23    0x00800000   OEMV external oscillator flag (0: Disabled, 1: Enabled)\n#  24    0x01000000   Software resource (0: OK, 1: Warning)\n#  25    0x02000000   <Reserved>\n#  26    0x04000000   <Reserved>\n#  27    0x08000000   <Reserved>\n#  28    0x10000000   <Reserved>\n#  29    0x20000000   Auxiliary 3 status event flag (0: No event, 1: Event)\n#  30    0x40000000   Auxiliary 2 status event flag (0: No event, 1: Event)\n#  31    0x80000000   Auxiliary 1 status event flag (0: No event, 1: Event)\nNovatelReceiverStatus receiver_status\n\n# Receiver build number (0-65535)\nuint32 receiver_software_version";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  java.lang.String getMessageName();
  void setMessageName(java.lang.String value);
  java.lang.String getPort();
  void setPort(java.lang.String value);
  int getSequenceNum();
  void setSequenceNum(int value);
  float getPercentIdleTime();
  void setPercentIdleTime(float value);
  java.lang.String getGpsTimeStatus();
  void setGpsTimeStatus(java.lang.String value);
  int getGpsWeekNum();
  void setGpsWeekNum(int value);
  double getGpsSeconds();
  void setGpsSeconds(double value);
  novatel_gps_msgs.NovatelReceiverStatus getReceiverStatus();
  void setReceiverStatus(novatel_gps_msgs.NovatelReceiverStatus value);
  int getReceiverSoftwareVersion();
  void setReceiverSoftwareVersion(int value);
}
