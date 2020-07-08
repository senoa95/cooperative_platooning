/*
 * estimate_lane_center.c
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

#include "estimate_lane_center.h"
#include "estimate_lane_center_private.h"

const SL_Bus_estimate_lane_center_path_follower_lane
  estimate_lane_center_rtZSL_Bus_estimate_lane_center_path_follower_lane = {
  0.0F,                                /* Strength */
  0.0F,                                /* RhoDot */
  0.0F,                                /* Rho */
  0.0F,                                /* Phi */
  0.0F                                 /* Y */
} ;                  /* SL_Bus_estimate_lane_center_path_follower_lane ground */

/* Block signals (default storage) */
B_estimate_lane_center_T estimate_lane_center_B;

/* Block states (default storage) */
DW_estimate_lane_center_T estimate_lane_center_DW;

/* Real-time model */
RT_MODEL_estimate_lane_center_T estimate_lane_center_M_;
RT_MODEL_estimate_lane_center_T *const estimate_lane_center_M =
  &estimate_lane_center_M_;

/* Forward declaration for local functions */
static void estimate_lane_center_matlabCodegenHandle_matlabCodegenDestructor_k
  (ros_slros_internal_block_Subscriber_estimate_lane_center_T *obj);
static void estimate_lane_center_SystemCore_release
  (dsp_simulink_MovingAverage_estimate_lane_center_T *obj);
static void estimate_lane_center_SystemCore_delete
  (dsp_simulink_MovingAverage_estimate_lane_center_T *obj);
static void estimate_lane_center_matlabCodegenHandle_matlabCodegenDestructor
  (dsp_simulink_MovingAverage_estimate_lane_center_T *obj);

/*
 * System initialize for enable system:
 *    '<S5>/Enabled Subsystem'
 *    '<S6>/Enabled Subsystem'
 */
void estimate_lane_center_EnabledSubsystem_Init
  (B_EnabledSubsystem_estimate_lane_center_T *localB)
{
  /* SystemInitialize for Outport: '<S14>/Out1' */
  localB->In1 =
    estimate_lane_center_rtZSL_Bus_estimate_lane_center_path_follower_lane;
}

/*
 * Output and update for enable system:
 *    '<S5>/Enabled Subsystem'
 *    '<S6>/Enabled Subsystem'
 */
void estimate_lane_center_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_estimate_lane_center_path_follower_lane *rtu_In1,
  B_EnabledSubsystem_estimate_lane_center_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (rtu_Enable) {
    /* Inport: '<S14>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */
}

static void estimate_lane_center_matlabCodegenHandle_matlabCodegenDestructor_k
  (ros_slros_internal_block_Subscriber_estimate_lane_center_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void estimate_lane_center_SystemCore_release
  (dsp_simulink_MovingAverage_estimate_lane_center_T *obj)
{
  dsp_private_SlidingWindowAverageCG_estimate_lane_center_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void estimate_lane_center_SystemCore_delete
  (dsp_simulink_MovingAverage_estimate_lane_center_T *obj)
{
  estimate_lane_center_SystemCore_release(obj);
}

static void estimate_lane_center_matlabCodegenHandle_matlabCodegenDestructor
  (dsp_simulink_MovingAverage_estimate_lane_center_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    estimate_lane_center_SystemCore_delete(obj);
  }
}

/* Model output function */
void estimate_lane_center_output(void)
{
  real_T cumRevIndex;
  real_T csum;
  real_T csumrev[3];
  int32_T c_index;
  SL_Bus_estimate_lane_center_path_follower_lane b_varargout_2;

  /* Outputs for Atomic SubSystem: '<S2>/Subscribe' */
  /* MATLABSystem: '<S5>/SourceBlock' */
  estimate_lane_center_B.SourceBlock_o1_a =
    Sub_estimate_lane_center_1131.getLatestMessage(&b_varargout_2);

  /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  estimate_lane_center_EnabledSubsystem(estimate_lane_center_B.SourceBlock_o1_a,
    &b_varargout_2, &estimate_lane_center_B.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<S2>/Subscribe' */

  /* SignalConversion generated from: '<S2>/Bus Selector' */
  estimate_lane_center_B.Y = estimate_lane_center_B.EnabledSubsystem.In1.Y;

  /* Outputs for Atomic SubSystem: '<S2>/Subscribe1' */
  /* MATLABSystem: '<S6>/SourceBlock' */
  estimate_lane_center_B.SourceBlock_o1 =
    Sub_estimate_lane_center_1134.getLatestMessage(&b_varargout_2);

  /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  estimate_lane_center_EnabledSubsystem(estimate_lane_center_B.SourceBlock_o1,
    &b_varargout_2, &estimate_lane_center_B.EnabledSubsystem_l);

  /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<S2>/Subscribe1' */

  /* SignalConversion generated from: '<S2>/Bus Selector1' */
  estimate_lane_center_B.Phi = estimate_lane_center_B.EnabledSubsystem_l.In1.Phi;

  /* Outputs for Atomic SubSystem: '<S2>/Estimate Lane Center' */
  /* Constant: '<Root>/Velocity' */
  estimate_lane_center_EstimateLaneCenter(3.0,
    estimate_lane_center_B.EnabledSubsystem.In1.Strength,
    estimate_lane_center_B.EnabledSubsystem.In1.RhoDot,
    estimate_lane_center_B.EnabledSubsystem.In1.Rho,
    estimate_lane_center_B.EnabledSubsystem.In1.Phi, estimate_lane_center_B.Y,
    estimate_lane_center_B.EnabledSubsystem_l.In1.Strength,
    estimate_lane_center_B.EnabledSubsystem_l.In1.RhoDot,
    estimate_lane_center_B.EnabledSubsystem_l.In1.Rho,
    estimate_lane_center_B.Phi, estimate_lane_center_B.EnabledSubsystem_l.In1.Y,
    &estimate_lane_center_B.EstimateLaneCenter,
    &estimate_lane_center_DW.EstimateLaneCenter);

  /* End of Outputs for SubSystem: '<S2>/Estimate Lane Center' */

  /* MATLABSystem: '<S2>/Moving Average' */
  if (estimate_lane_center_DW.obj.TunablePropsChanged) {
    estimate_lane_center_DW.obj.TunablePropsChanged = false;
  }

  if (estimate_lane_center_DW.obj.pStatistic->isInitialized != 1) {
    estimate_lane_center_DW.obj.pStatistic->isSetupComplete = false;
    estimate_lane_center_DW.obj.pStatistic->isInitialized = 1;
    estimate_lane_center_DW.obj.pStatistic->pCumSum = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumRevIndex = 1.0;
    estimate_lane_center_DW.obj.pStatistic->isSetupComplete = true;
    estimate_lane_center_DW.obj.pStatistic->pCumSum = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumRevIndex = 1.0;
  }

  cumRevIndex = estimate_lane_center_DW.obj.pStatistic->pCumRevIndex;
  csum = estimate_lane_center_DW.obj.pStatistic->pCumSum;
  csumrev[0] = estimate_lane_center_DW.obj.pStatistic->pCumSumRev[0];
  csumrev[1] = estimate_lane_center_DW.obj.pStatistic->pCumSumRev[1];
  csumrev[2] = estimate_lane_center_DW.obj.pStatistic->pCumSumRev[2];
  for (c_index = 0; c_index < 3; c_index++) {
    csum += estimate_lane_center_B.EstimateLaneCenter.Sum[c_index];
    csumrev[(int32_T)cumRevIndex - 1] =
      estimate_lane_center_B.EstimateLaneCenter.Sum[c_index];
    if (cumRevIndex != 3.0) {
      cumRevIndex++;
    } else {
      cumRevIndex = 1.0;
      csum = 0.0;
      csumrev[1] += csumrev[2];
      csumrev[0] += csumrev[1];
    }
  }

  estimate_lane_center_DW.obj.pStatistic->pCumSum = csum;
  estimate_lane_center_DW.obj.pStatistic->pCumSumRev[0] = csumrev[0];
  estimate_lane_center_DW.obj.pStatistic->pCumSumRev[1] = csumrev[1];
  estimate_lane_center_DW.obj.pStatistic->pCumSumRev[2] = csumrev[2];
  estimate_lane_center_DW.obj.pStatistic->pCumRevIndex = cumRevIndex;

  /* End of MATLABSystem: '<S2>/Moving Average' */
}

/* Model update function */
void estimate_lane_center_update(void)
{
  /* Update for Atomic SubSystem: '<S2>/Estimate Lane Center' */
  estimate_lane_center_EstimateLaneCenter_Update
    (&estimate_lane_center_B.EstimateLaneCenter,
     &estimate_lane_center_DW.EstimateLaneCenter);

  /* End of Update for SubSystem: '<S2>/Estimate Lane Center' */
}

/* Model initialize function */
void estimate_lane_center_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(estimate_lane_center_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &estimate_lane_center_B), 0,
                sizeof(B_estimate_lane_center_T));

  /* states (dwork) */
  (void) memset((void *)&estimate_lane_center_DW, 0,
                sizeof(DW_estimate_lane_center_T));

  {
    char_T tmp[17];
    int32_T i;
    static const char_T tmp_0[16] = { '/', 't', 'r', 'e', 'x', '2', '/', 'l',
      'e', 'f', 't', '_', 'l', 'a', 'n', 'e' };

    /* Start for Atomic SubSystem: '<S2>/Subscribe' */
    /* Start for MATLABSystem: '<S5>/SourceBlock' */
    estimate_lane_center_DW.obj_k.matlabCodegenIsDeleted = false;
    estimate_lane_center_DW.objisempty_j = true;
    estimate_lane_center_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      tmp[i] = tmp_0[i];
    }

    tmp[16] = '\x00';
    Sub_estimate_lane_center_1131.createSubscriber(tmp, 1);
    estimate_lane_center_DW.obj_k.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SourceBlock' */
    /* End of Start for SubSystem: '<S2>/Subscribe' */

    /* Start for Atomic SubSystem: '<S2>/Subscribe1' */
    /* Start for MATLABSystem: '<S6>/SourceBlock' */
    estimate_lane_center_DW.obj_h.matlabCodegenIsDeleted = false;
    estimate_lane_center_DW.objisempty = true;
    estimate_lane_center_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      tmp[i] = tmp_0[i];
    }

    tmp[16] = '\x00';
    Sub_estimate_lane_center_1134.createSubscriber(tmp, 1);
    estimate_lane_center_DW.obj_h.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S6>/SourceBlock' */
    /* End of Start for SubSystem: '<S2>/Subscribe1' */

    /* Start for MATLABSystem: '<S2>/Moving Average' */
    estimate_lane_center_DW.obj.matlabCodegenIsDeleted = false;
    estimate_lane_center_DW.objisempty_d = true;
    estimate_lane_center_DW.obj.isInitialized = 1;
    estimate_lane_center_DW.obj.NumChannels = 1;
    estimate_lane_center_DW.gobj_0.isInitialized = 0;
    estimate_lane_center_DW.obj.pStatistic = &estimate_lane_center_DW.gobj_0;
    estimate_lane_center_DW.obj.isSetupComplete = true;
    estimate_lane_center_DW.obj.TunablePropsChanged = false;
  }

  /* SystemInitialize for Atomic SubSystem: '<S2>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  estimate_lane_center_EnabledSubsystem_Init
    (&estimate_lane_center_B.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S2>/Subscribe' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/Subscribe1' */
  /* SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  estimate_lane_center_EnabledSubsystem_Init
    (&estimate_lane_center_B.EnabledSubsystem_l);

  /* End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S2>/Subscribe1' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/Estimate Lane Center' */
  estimate_lane_center_EstimateLaneCenter_Init
    (&estimate_lane_center_B.EstimateLaneCenter,
     &estimate_lane_center_DW.EstimateLaneCenter);

  /* End of SystemInitialize for SubSystem: '<S2>/Estimate Lane Center' */

  /* InitializeConditions for MATLABSystem: '<S2>/Moving Average' */
  if (estimate_lane_center_DW.obj.pStatistic->isInitialized == 1) {
    estimate_lane_center_DW.obj.pStatistic->pCumSum = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    estimate_lane_center_DW.obj.pStatistic->pCumRevIndex = 1.0;
  }

  /* End of InitializeConditions for MATLABSystem: '<S2>/Moving Average' */
}

/* Model terminate function */
void estimate_lane_center_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<S2>/Subscribe' */
  /* Terminate for MATLABSystem: '<S5>/SourceBlock' */
  estimate_lane_center_matlabCodegenHandle_matlabCodegenDestructor_k
    (&estimate_lane_center_DW.obj_k);

  /* End of Terminate for SubSystem: '<S2>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<S2>/Subscribe1' */
  /* Terminate for MATLABSystem: '<S6>/SourceBlock' */
  estimate_lane_center_matlabCodegenHandle_matlabCodegenDestructor_k
    (&estimate_lane_center_DW.obj_h);

  /* End of Terminate for SubSystem: '<S2>/Subscribe1' */

  /* Terminate for MATLABSystem: '<S2>/Moving Average' */
  estimate_lane_center_matlabCodegenHandle_matlabCodegenDestructor
    (&estimate_lane_center_DW.obj);
}
