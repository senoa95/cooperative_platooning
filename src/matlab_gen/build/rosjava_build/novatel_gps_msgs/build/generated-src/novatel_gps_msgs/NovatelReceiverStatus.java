package novatel_gps_msgs;

public interface NovatelReceiverStatus extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/NovatelReceiverStatus";
  static final java.lang.String _DEFINITION = "# From the original Novatel receiver status message bitfield\n#  0     0x00000001   Error flag (Bit = 0: No Error, Bit = 1: Error)\n#  1     0x00000002   Temperature Status (0: Within Spec, 1: Warning)\n#  2     0x00000004   Voltage Supply Status (0: OK, 1: Warning)\n#  3     0x00000008   Antenna Power Status (0: Powered, 1: Not Powered)\n#  4     0x00000010   <Reserved>\n#  5     0x00000020   Antenna open flag (0: OK, 1: Open)\n#  6     0x00000040   Antenna shorted flag (0: OK, 1: Shorted)\n#  7     0x00000080   CPU overload flag\n#  8     0x00000100   COM1 buffer overrun flag (0: No overrun, 1: Overrun)\n#  9     0x00000200   COM2 buffer overrun flag (0: No overrun, 1: Overrun)\n#  10    0x00000400   COM3 buffer overrun flag (0: No overrun, 1: Overrun)\n#  11    0x00000800   USB buffer overrun flag (0: No overrun, 1: Overrun)\n#  12    0x00001000   <Reserved>\n#  13    0x00002000   <Reserved>\n#  14    0x00004000   <Reserved>\n#  15    0x00008000   RF1 AGC Status (0: OK, 1: Bad)\n#  16    0x00010000   <Reserverd>\n#  17    0x00020000   RF2 AGC status (0: OK, 1: Bad)\n#  18    0x00040000   Almanac flag/UTC known (0: Valid, 1: Invalid)\n#  19    0x00080000   Position solution flag (0: Valid, 1: Invalid)\n#  20    0x00100000   Position fixed flag (0: Not fixed, 1: Fixed)\n#  21    0x00200000   Clock steering status (0: Enabled, 1: Disabled)\n#  22    0x00400000   Clock model flag (0: Valid, 1: Invalid)\n#  23    0x00800000   OEMV external oscillator flag (0: Disabled, 1: Enabled)\n#  24    0x01000000   Software resource (0: OK, 1: Warning)\n#  25    0x02000000   <Reserved>\n#  26    0x04000000   <Reserved>\n#  27    0x08000000   <Reserved>\n#  28    0x10000000   <Reserved>\n#  29    0x20000000   Auxiliary 3 status event flag (0: No event, 1: Event)\n#  30    0x40000000   Auxiliary 2 status event flag (0: No event, 1: Event)\n#  31    0x80000000   Auxiliary 1 status event flag (0: No event, 1: Event)\nuint32 original_status_code\nbool error_flag\nbool temperature_flag\nbool voltage_supply_flag\nbool antenna_powered\nbool antenna_is_open\nbool antenna_is_shorted\nbool cpu_overload_flag\nbool com1_buffer_overrun\nbool com2_buffer_overrun\nbool com3_buffer_overrun\nbool usb_buffer_overrun\nbool rf1_agc_flag\nbool rf2_agc_flag\nbool almanac_flag\nbool position_solution_flag\nbool position_fixed_flag\nbool clock_steering_status_enabled\nbool clock_model_flag\nbool oemv_external_oscillator_flag\nbool software_resource_flag\nbool aux1_status_event_flag\nbool aux2_status_event_flag\nbool aux3_status_event_flag\n\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getOriginalStatusCode();
  void setOriginalStatusCode(int value);
  boolean getErrorFlag();
  void setErrorFlag(boolean value);
  boolean getTemperatureFlag();
  void setTemperatureFlag(boolean value);
  boolean getVoltageSupplyFlag();
  void setVoltageSupplyFlag(boolean value);
  boolean getAntennaPowered();
  void setAntennaPowered(boolean value);
  boolean getAntennaIsOpen();
  void setAntennaIsOpen(boolean value);
  boolean getAntennaIsShorted();
  void setAntennaIsShorted(boolean value);
  boolean getCpuOverloadFlag();
  void setCpuOverloadFlag(boolean value);
  boolean getCom1BufferOverrun();
  void setCom1BufferOverrun(boolean value);
  boolean getCom2BufferOverrun();
  void setCom2BufferOverrun(boolean value);
  boolean getCom3BufferOverrun();
  void setCom3BufferOverrun(boolean value);
  boolean getUsbBufferOverrun();
  void setUsbBufferOverrun(boolean value);
  boolean getRf1AgcFlag();
  void setRf1AgcFlag(boolean value);
  boolean getRf2AgcFlag();
  void setRf2AgcFlag(boolean value);
  boolean getAlmanacFlag();
  void setAlmanacFlag(boolean value);
  boolean getPositionSolutionFlag();
  void setPositionSolutionFlag(boolean value);
  boolean getPositionFixedFlag();
  void setPositionFixedFlag(boolean value);
  boolean getClockSteeringStatusEnabled();
  void setClockSteeringStatusEnabled(boolean value);
  boolean getClockModelFlag();
  void setClockModelFlag(boolean value);
  boolean getOemvExternalOscillatorFlag();
  void setOemvExternalOscillatorFlag(boolean value);
  boolean getSoftwareResourceFlag();
  void setSoftwareResourceFlag(boolean value);
  boolean getAux1StatusEventFlag();
  void setAux1StatusEventFlag(boolean value);
  boolean getAux2StatusEventFlag();
  void setAux2StatusEventFlag(boolean value);
  boolean getAux3StatusEventFlag();
  void setAux3StatusEventFlag(boolean value);
}
