/*
 * estimate_lane_center.h
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "estimate_lane_center".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C++ source code generated on : Tue Oct  8 22:25:50 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_estimate_lane_center_h_
#define RTW_HEADER_estimate_lane_center_h_
#ifndef estimate_lane_center_COMMON_INCLUDES_
# define estimate_lane_center_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                               /* estimate_lane_center_COMMON_INCLUDES_ */

#include "estimate_lane_center_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "estimate_lan_EstimateLaneCenter.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_estimate_lane_center_T {
  const char_T *errorStatus;
};

/* Class declaration for model estimate_lane_center */
class estimate_lane_centerModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  estimate_lane_centerModelClass();

  /* Destructor */
  ~estimate_lane_centerModelClass();

  /* Real-Time Model get method */
  RT_MODEL_estimate_lane_center_T * getRTM();

  /* private data and function members */
 private:
  /* Real-Time Model */
  RT_MODEL_estimate_lane_center_T estimate_lane_center_M;
};

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
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
 * '<S1>'   : 'estimate_lane_center/Estimate Lane Center'
 * '<S2>'   : 'estimate_lane_center/Estimate Lane Center/Center from Left'
 * '<S3>'   : 'estimate_lane_center/Estimate Lane Center/Center from Left and Right'
 * '<S4>'   : 'estimate_lane_center/Estimate Lane Center/Center from None'
 * '<S5>'   : 'estimate_lane_center/Estimate Lane Center/Center from Right'
 * '<S6>'   : 'estimate_lane_center/Estimate Lane Center/ISO 8855 to SAE J670E'
 * '<S7>'   : 'estimate_lane_center/Estimate Lane Center/MATLAB Function'
 * '<S8>'   : 'estimate_lane_center/Estimate Lane Center/Preview curvature'
 */
#endif                                 /* RTW_HEADER_estimate_lane_center_h_ */
