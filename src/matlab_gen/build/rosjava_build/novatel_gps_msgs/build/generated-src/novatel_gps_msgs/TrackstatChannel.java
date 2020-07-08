package novatel_gps_msgs;

public interface TrackstatChannel extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/TrackstatChannel";
  static final java.lang.String _DEFINITION = "# A submessage of Trackstat that contains all of the data about a single hardware channel\n\n# Satellite PRN number\nint16 prn\n\n# GLONASS Frequency +7\nint16 glofreq\n\n# Channel tracking status\nuint32 ch_tr_status\n\n# Pseudorange (m)\nfloat64 psr\n\n# Doppler frequency (Hz)\nfloat32 doppler\n\n# Carrier to noise density ratio (dB-Hz)\nfloat32 c_no\n\n# Number of seconds of continuous tracking (no cycle slips)\nfloat32 locktime\n\n# Pseudorange residual from pseudorange filter (m)\nfloat32 psr_res\n\n# Range reject code from pseudorange filter\nstring reject\n\n# Pseudorange filter weighting\nfloat32 psr_weight";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  short getPrn();
  void setPrn(short value);
  short getGlofreq();
  void setGlofreq(short value);
  int getChTrStatus();
  void setChTrStatus(int value);
  double getPsr();
  void setPsr(double value);
  float getDoppler();
  void setDoppler(float value);
  float getCNo();
  void setCNo(float value);
  float getLocktime();
  void setLocktime(float value);
  float getPsrRes();
  void setPsrRes(float value);
  java.lang.String getReject();
  void setReject(java.lang.String value);
  float getPsrWeight();
  void setPsrWeight(float value);
}
