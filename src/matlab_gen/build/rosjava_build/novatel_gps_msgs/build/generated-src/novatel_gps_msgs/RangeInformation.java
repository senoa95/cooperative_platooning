package novatel_gps_msgs;

public interface RangeInformation extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/RangeInformation";
  static final java.lang.String _DEFINITION = "#Satellite Range information structure used in range messages\n\n#Satelite PRN number of range measurement\nuint16 prn_number\n\n#GLONASS Frequency\nuint16 glofreq\n\n#Pseudorange measurement(m)\nfloat64 psr\n\n#Pseudorange measurement standard deviation(m)\nfloat32 psr_std\n\n#Carrier phase, in cycles\nfloat64 adr\n\n#Estimated carrier phase standard deviation(cycles)\nfloat32 adr_std\n\n#Instantaneous carrier Doppler frequency(Hz)\nfloat32 dopp\n\n#Carrier to noise density ratio\nfloat32 noise_density_ratio\n\n## of seconds of continous tracking\nfloat32 locktime\n\n#Tracking status\nuint32 tracking_status\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  short getPrnNumber();
  void setPrnNumber(short value);
  short getGlofreq();
  void setGlofreq(short value);
  double getPsr();
  void setPsr(double value);
  float getPsrStd();
  void setPsrStd(float value);
  double getAdr();
  void setAdr(double value);
  float getAdrStd();
  void setAdrStd(float value);
  float getDopp();
  void setDopp(float value);
  float getNoiseDensityRatio();
  void setNoiseDensityRatio(float value);
  float getLocktime();
  void setLocktime(float value);
  int getTrackingStatus();
  void setTrackingStatus(int value);
}
