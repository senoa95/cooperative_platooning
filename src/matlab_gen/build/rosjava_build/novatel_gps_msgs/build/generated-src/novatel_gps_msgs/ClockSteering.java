package novatel_gps_msgs;

public interface ClockSteering extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/ClockSteering";
  static final java.lang.String _DEFINITION = "# The CLOCKSTEERING log is used to monitor the current state of the clock steering process.\n\nint8 INTERNAL_SOURCE=0\nint8 EXTERNAL_SOURCE=1\n\nint8 FIRST_ORDER_STEERING_STATE=0\nint8 SECOND_ORDER_STEERING_STATE=1\nint8 CALIBRATE_HIGH_STEERING_STATE=2\nint8 CALIBRATE_LOW_STEERING_STATE=3\nint8 CALIBRATE_CENTER_STEERING_STATE=4\n\n# Clock source\nstring source\n\n# Steering state\nstring steering_state\n\n# Period of the FREQUENCYOUT signal used to control the oscillator\nuint32 period\n\n# Current pulse width of the FREQUENCYOUT signal. \nfloat64 pulse_width\n\n# The current band width of the clock steering tracking loop in Hz.\nfloat64 bandwidth\n\n# The current clock drift change in m/s/bit for a 1 LSB pulse width. \nfloat32 slope\n\n# The last valid receiver clock offset computed (m).\nfloat64 offset\n\n# The last valid receiver clock drift rate received (m/s).\nfloat64 drift_rate\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  static final byte INTERNAL_SOURCE = 0;
  static final byte EXTERNAL_SOURCE = 1;
  static final byte FIRST_ORDER_STEERING_STATE = 0;
  static final byte SECOND_ORDER_STEERING_STATE = 1;
  static final byte CALIBRATE_HIGH_STEERING_STATE = 2;
  static final byte CALIBRATE_LOW_STEERING_STATE = 3;
  static final byte CALIBRATE_CENTER_STEERING_STATE = 4;
  java.lang.String getSource();
  void setSource(java.lang.String value);
  java.lang.String getSteeringState();
  void setSteeringState(java.lang.String value);
  int getPeriod();
  void setPeriod(int value);
  double getPulseWidth();
  void setPulseWidth(double value);
  double getBandwidth();
  void setBandwidth(double value);
  float getSlope();
  void setSlope(float value);
  double getOffset();
  void setOffset(double value);
  double getDriftRate();
  void setDriftRate(double value);
}
