package novatel_gps_msgs;

public interface Satellite extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/Satellite";
  static final java.lang.String _DEFINITION = "# Satellite data structure used in GPGSV messages\n\n# PRN number of the satellite\n# GPS = 1..32\n# SBAS = 33..64\n# GLO = 65..96\nuint8 prn\n\n# Elevation, degrees. Maximum 90\nuint8 elevation\n\n# Azimuth, True North degrees. [0, 359]\nuint16 azimuth\n\n# Signal to noise ratio, 0-99 dB. -1 when null in NMEA sentence (not tracking)\nint8 snr";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  byte getPrn();
  void setPrn(byte value);
  byte getElevation();
  void setElevation(byte value);
  short getAzimuth();
  void setAzimuth(short value);
  byte getSnr();
  void setSnr(byte value);
}
