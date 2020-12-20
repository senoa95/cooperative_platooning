/*
 * Code generation for system system '<S2>/Estimate Lane Center'
 * For more details, see corresponding source file estimate_lane_center_EstimateLaneCenter.c
 *
 */

#ifndef RTW_HEADER_estimate_lane_center_EstimateLaneCenter_h_
#define RTW_HEADER_estimate_lane_center_EstimateLaneCenter_h_
#ifndef estimate_lane_center_COMMON_INCLUDES_
# define estimate_lane_center_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                               /* estimate_lane_center_COMMON_INCLUDES_ */

#include "estimate_lane_center_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Block signals for system '<S2>/Estimate Lane Center' */
typedef struct {
  real_T Sum[3];                       /* '<S13>/Sum' */
  real32_T CurvatureDerivative_g;      /* '<S4>/Merge' */
  real32_T Curvature_o;                /* '<S4>/Merge' */
  real32_T HeadingAngle_j;             /* '<S4>/Merge' */
  real32_T LateralOffset_b;            /* '<S4>/Merge' */
} B_EstimateLaneCenter_estimate_lane_center_T;

/* Block states (default storage) for system '<S2>/Estimate Lane Center' */
typedef struct {
  real32_T Delay_4_DSTATE;             /* '<S4>/Delay' */
  real32_T Delay_3_DSTATE;             /* '<S4>/Delay' */
  real32_T Delay_2_DSTATE;             /* '<S4>/Delay' */
  real32_T Delay_1_DSTATE;             /* '<S4>/Delay' */
} DW_EstimateLaneCenter_estimate_lane_center_T;

extern void estimate_lane_center_EstimateLaneCenter_Init
  (B_EstimateLaneCenter_estimate_lane_center_T *localB,
   DW_EstimateLaneCenter_estimate_lane_center_T *localDW);
extern void estimate_lane_center_EstimateLaneCenter_Update
  (B_EstimateLaneCenter_estimate_lane_center_T *localB,
   DW_EstimateLaneCenter_estimate_lane_center_T *localDW);
extern void estimate_lane_center_EstimateLaneCenter(real_T
  rtu_LongitudinalVelocity, real32_T rtu_left_strength, real32_T
  rtu_right_strength, real32_T rtu_left_curvature_rate, real32_T
  rtu_left_curvature, real32_T rtu_left_relative_yaw_heading, real32_T
  rtu_left_lateral_offset, real32_T rtu_right_curvature_rate, real32_T
  rtu_right_curvature, real32_T rtu_right_relative_yaw_heading, real32_T
  rtu_right_lateral_offset, B_EstimateLaneCenter_estimate_lane_center_T *localB,
  DW_EstimateLaneCenter_estimate_lane_center_T *localDW);

#endif               /* RTW_HEADER_estimate_lane_center_EstimateLaneCenter_h_ */
