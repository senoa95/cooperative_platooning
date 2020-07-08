package novatel_gps_msgs;

public interface NovatelSignalMask extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/NovatelSignalMask";
  static final java.lang.String _DEFINITION = "# Bit    Mask      Description\n#  0     0x01      GPS L1 used in Solution\n#  1     0x02      GPS L2 used in Solution\n#  2     0x04      GPS L5 used in Solution\n#  3     0x08      <Reserved>\n#  4     0x10      GLONASS L1 used in Solution\n#  5     0x20      GLONASS L2 used in Solution\n# 6-7  0x40-0x80   <Reserved>\nuint32 original_mask\nbool gps_L1_used_in_solution\nbool gps_L2_used_in_solution\nbool gps_L3_used_in_solution\nbool glonass_L1_used_in_solution\nbool glonass_L2_used_in_solution";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getOriginalMask();
  void setOriginalMask(int value);
  boolean getGpsL1UsedInSolution();
  void setGpsL1UsedInSolution(boolean value);
  boolean getGpsL2UsedInSolution();
  void setGpsL2UsedInSolution(boolean value);
  boolean getGpsL3UsedInSolution();
  void setGpsL3UsedInSolution(boolean value);
  boolean getGlonassL1UsedInSolution();
  void setGlonassL1UsedInSolution(boolean value);
  boolean getGlonassL2UsedInSolution();
  void setGlonassL2UsedInSolution(boolean value);
}
