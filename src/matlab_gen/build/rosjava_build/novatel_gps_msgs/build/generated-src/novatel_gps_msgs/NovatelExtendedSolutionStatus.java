package novatel_gps_msgs;

public interface NovatelExtendedSolutionStatus extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "novatel_gps_msgs/NovatelExtendedSolutionStatus";
  static final java.lang.String _DEFINITION = "# Bit    Mask      Description\n#  0     0x01      Advance RTK verified (0 = not verified, 1 = verified)\n# 1-3    0x0E      Pseudorange Ionosphere Correction\n#                    0 = unknown\n#                    1 = Klobuchar Broadcast\n#                    2 = SBAS Broadcast\n#                    3 = Multi-frequency Computed\n#                    4 = PSRDiff Correction\n#                    5 = NovaTel Blended Ionosphere Value\n# 4-7  0xF0        <Reserved>\nuint32 original_mask\nbool advance_rtk_verified\nstring psuedorange_iono_correction\n";
  static final boolean _IS_SERVICE = false;
  static final boolean _IS_ACTION = false;
  int getOriginalMask();
  void setOriginalMask(int value);
  boolean getAdvanceRtkVerified();
  void setAdvanceRtkVerified(boolean value);
  java.lang.String getPsuedorangeIonoCorrection();
  void setPsuedorangeIonoCorrection(java.lang.String value);
}
