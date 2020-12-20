/*
 * estimate_lane_center_private.h
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

#ifndef RTW_HEADER_estimate_lane_center_private_h_
#define RTW_HEADER_estimate_lane_center_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "estimate_lane_center.h"

extern void estimate_lane_center_EnabledSubsystem_Init
  (B_EnabledSubsystem_estimate_lane_center_T *localB);
extern void estimate_lane_center_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_estimate_lane_center_path_follower_lane *rtu_In1,
  B_EnabledSubsystem_estimate_lane_center_T *localB);

#endif                          /* RTW_HEADER_estimate_lane_center_private_h_ */
