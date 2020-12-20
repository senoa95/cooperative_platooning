/*
 * estimate_lane_center.h
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

#ifndef RTW_HEADER_estimate_lane_center_h_
#define RTW_HEADER_estimate_lane_center_h_
#include <stddef.h>
#include <string.h>
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

/* Child system includes */
#include "estimate_lane_center_EstimateLaneCenter.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S5>/Enabled Subsystem' */
typedef struct {
  SL_Bus_estimate_lane_center_path_follower_lane In1;/* '<S14>/In1' */
} B_EnabledSubsystem_estimate_lane_center_T;

/* Block signals (default storage) */
typedef struct {
  real32_T Y;
  real32_T Phi;
  boolean_T SourceBlock_o1;            /* '<S6>/SourceBlock' */
  boolean_T SourceBlock_o1_a;          /* '<S5>/SourceBlock' */
  B_EnabledSubsystem_estimate_lane_center_T EnabledSubsystem_l;/* '<S6>/Enabled Subsystem' */
  B_EnabledSubsystem_estimate_lane_center_T EnabledSubsystem;/* '<S5>/Enabled Subsystem' */
  B_EstimateLaneCenter_estimate_lane_center_T EstimateLaneCenter;/* '<S2>/Estimate Lane Center' */
} B_estimate_lane_center_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_estimate_lane_center_T obj;/* '<S2>/Moving Average' */
  dsp_private_SlidingWindowAverageCG_estimate_lane_center_T gobj_0;/* '<S2>/Moving Average' */
  dsp_private_SlidingWindowAverageCG_estimate_lane_center_T gobj_1;/* '<S2>/Moving Average' */
  ros_slros_internal_block_Subscriber_estimate_lane_center_T obj_h;/* '<S6>/SourceBlock' */
  ros_slros_internal_block_Subscriber_estimate_lane_center_T obj_k;/* '<S5>/SourceBlock' */
  boolean_T objisempty;                /* '<S6>/SourceBlock' */
  boolean_T objisempty_j;              /* '<S5>/SourceBlock' */
  boolean_T objisempty_d;              /* '<S2>/Moving Average' */
  DW_EstimateLaneCenter_estimate_lane_center_T EstimateLaneCenter;/* '<S2>/Estimate Lane Center' */
} DW_estimate_lane_center_T;

/* Real-time Model Data Structure */
struct tag_RTM_estimate_lane_center_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_estimate_lane_center_T estimate_lane_center_B;

/* Block states (default storage) */
extern DW_estimate_lane_center_T estimate_lane_center_DW;

/* External data declarations for dependent source files */
extern const SL_Bus_estimate_lane_center_path_follower_lane
  estimate_lane_center_rtZSL_Bus_estimate_lane_center_path_follower_lane;
                     /* SL_Bus_estimate_lane_center_path_follower_lane ground */

/* Model entry point functions */
extern void estimate_lane_center_initialize(void);
extern void estimate_lane_center_output(void);
extern void estimate_lane_center_update(void);
extern void estimate_lane_center_terminate(void);

/* Real-time Model object */
extern RT_MODEL_estimate_lane_center_T *const estimate_lane_center_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Add' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S2>/Divide' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S2>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'estimate_lane_center'
 * '<S1>'   : 'estimate_lane_center/Follow Center Compute'
 * '<S2>'   : 'estimate_lane_center/Lead Center Compute'
 * '<S3>'   : 'estimate_lane_center/Lead Center Compute/Blank Message'
 * '<S4>'   : 'estimate_lane_center/Lead Center Compute/Estimate Lane Center'
 * '<S5>'   : 'estimate_lane_center/Lead Center Compute/Subscribe'
 * '<S6>'   : 'estimate_lane_center/Lead Center Compute/Subscribe1'
 * '<S7>'   : 'estimate_lane_center/Lead Center Compute/Estimate Lane Center/Center from Left'
 * '<S8>'   : 'estimate_lane_center/Lead Center Compute/Estimate Lane Center/Center from Left and Right'
 * '<S9>'   : 'estimate_lane_center/Lead Center Compute/Estimate Lane Center/Center from None'
 * '<S10>'  : 'estimate_lane_center/Lead Center Compute/Estimate Lane Center/Center from Right'
 * '<S11>'  : 'estimate_lane_center/Lead Center Compute/Estimate Lane Center/ISO 8855 to SAE J670E'
 * '<S12>'  : 'estimate_lane_center/Lead Center Compute/Estimate Lane Center/MATLAB Function'
 * '<S13>'  : 'estimate_lane_center/Lead Center Compute/Estimate Lane Center/Preview curvature'
 * '<S14>'  : 'estimate_lane_center/Lead Center Compute/Subscribe/Enabled Subsystem'
 * '<S15>'  : 'estimate_lane_center/Lead Center Compute/Subscribe1/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_estimate_lane_center_h_ */
