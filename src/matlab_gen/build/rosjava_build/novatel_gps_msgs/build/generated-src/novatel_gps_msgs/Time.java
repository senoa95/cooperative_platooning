package novatel_gps_msgs;

public interface Time extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Time";
  static final java.lang.String _DEFINITION = "# Parsed Best Position or Omnistar XP or HP pos data from Novatel OEM6 receiver\nHeader header\n\n# Clock model status\n# see Table 65 on pg 322 of the OEM6 Family Firmware Reference Manual, Rev3\nstring clock_status\n\n# Receiver clock offset, in seconds, from GPS reference time. A positive offset\n# implies that the receiver clock is ahead of GPS reference time. To derive\n# GPS reference time, use the following formula:\n# GPS reference time = receiver time - offset\nfloat64 offset\n\n# Standard deviation of the offset\nfloat64 offset_std\n\n# The offset of the GPS reference time from UTC time, computed using almanac\n# parameters. UTC time is GPS reference time plus the current UTC offset plus\n# the receiver clock offset:\n# UTC time = GPS reference time + offset + UTC offset\nfloat64 utc_offset\n\nuint32 utc_year\nuint8 utc_month\nuint8 utc_day\nuint8 utc_hour\nuint8 utc_minute\nuint32 utc_millisecond\n\nstring utc_status";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  java.lang.String getClockStatus();
  void setClockStatus(java.lang.String value);
  double getOffset();
  void setOffset(double value);
  double getOffsetStd();
  void setOffsetStd(double value);
  double getUtcOffset();
  void setUtcOffset(double value);
  int getUtcYear();
  void setUtcYear(int value);
  byte getUtcMonth();
  void setUtcMonth(byte value);
  byte getUtcDay();
  void setUtcDay(byte value);
  byte getUtcHour();
  void setUtcHour(byte value);
  byte getUtcMinute();
  void setUtcMinute(byte value);
  int getUtcMillisecond();
  void setUtcMillisecond(int value);
  java.lang.String getUtcStatus();
  void setUtcStatus(java.lang.String value);
}
