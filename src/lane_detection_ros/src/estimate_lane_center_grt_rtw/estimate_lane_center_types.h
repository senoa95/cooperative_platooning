/*
 * estimate_lane_center_types.h
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "estimate_lane_center".
 *
 * Model version              : 1.778
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Jul  7 16:54:46 2020
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_estimate_lane_center_types_h_
#define RTW_HEADER_estimate_lane_center_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_estimate_lane_center_path_follower_lane_
#define DEFINED_TYPEDEF_FOR_SL_Bus_estimate_lane_center_path_follower_lane_

typedef struct {
  real32_T Strength;
  real32_T RhoDot;
  real32_T Rho;
  real32_T Phi;
  real32_T Y;
} SL_Bus_estimate_lane_center_path_follower_lane;

#endif

#ifndef typedef_dsp_private_SlidingWindowAverageCG_estimate_lane_center_T
#define typedef_dsp_private_SlidingWindowAverageCG_estimate_lane_center_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[3];
  real_T pCumRevIndex;
} dsp_private_SlidingWindowAverageCG_estimate_lane_center_T;

#endif     /*typedef_dsp_private_SlidingWindowAverageCG_estimate_lane_center_T*/

#ifndef typedef_ros_slros_internal_block_Subscriber_estimate_lane_center_T
#define typedef_ros_slros_internal_block_Subscriber_estimate_lane_center_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} ros_slros_internal_block_Subscriber_estimate_lane_center_T;

#endif    /*typedef_ros_slros_internal_block_Subscriber_estimate_lane_center_T*/

#ifndef typedef_c_cell_wrap_estimate_lane_center_T
#define typedef_c_cell_wrap_estimate_lane_center_T

typedef struct {
  uint32_T f1[8];
} c_cell_wrap_estimate_lane_center_T;

#endif                            /*typedef_c_cell_wrap_estimate_lane_center_T*/

#ifndef typedef_dsp_simulink_MovingAverage_estimate_lane_center_T
#define typedef_dsp_simulink_MovingAverage_estimate_lane_center_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  c_cell_wrap_estimate_lane_center_T inputVarSize;
  dsp_private_SlidingWindowAverageCG_estimate_lane_center_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage_estimate_lane_center_T;

#endif             /*typedef_dsp_simulink_MovingAverage_estimate_lane_center_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_estimate_lane_center_T RT_MODEL_estimate_lane_center_T;

#endif                            /* RTW_HEADER_estimate_lane_center_types_h_ */
