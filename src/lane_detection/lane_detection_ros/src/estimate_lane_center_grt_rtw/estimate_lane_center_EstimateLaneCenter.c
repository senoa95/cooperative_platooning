/*
 * Code generation for system system '<S2>/Estimate Lane Center'
 *
 * Model                      : estimate_lane_center
 * Model version              : 1.778
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Jul  7 16:54:46 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "estimate_lane_center_EstimateLaneCenter.h"

/* Include model header file for global data */
#include "estimate_lane_center.h"
#include "estimate_lane_center_private.h"

/* System initialize for atomic system: '<S2>/Estimate Lane Center' */
void estimate_lane_center_EstimateLaneCenter_Init
  (B_EstimateLaneCenter_estimate_lane_center_T *localB,
   DW_EstimateLaneCenter_estimate_lane_center_T *localDW)
{
  /* InitializeConditions for Delay generated from: '<S4>/Delay' */
  localDW->Delay_4_DSTATE = 0.0F;

  /* InitializeConditions for Delay generated from: '<S4>/Delay' */
  localDW->Delay_3_DSTATE = 0.0F;

  /* InitializeConditions for Delay generated from: '<S4>/Delay' */
  localDW->Delay_2_DSTATE = 0.0F;

  /* InitializeConditions for Delay generated from: '<S4>/Delay' */
  localDW->Delay_1_DSTATE = 0.0F;

  /* SystemInitialize for Merge generated from: '<S4>/Merge' */
  localB->CurvatureDerivative_g = 0.0F;

  /* SystemInitialize for Merge generated from: '<S4>/Merge' */
  localB->Curvature_o = 0.0F;

  /* SystemInitialize for Merge generated from: '<S4>/Merge' */
  localB->HeadingAngle_j = 0.0F;

  /* SystemInitialize for Merge generated from: '<S4>/Merge' */
  localB->LateralOffset_b = 0.0F;
}

/* Outputs for atomic system: '<S2>/Estimate Lane Center' */
void estimate_lane_center_EstimateLaneCenter(real_T rtu_LongitudinalVelocity,
  real32_T rtu_left_strength, real32_T rtu_right_strength, real32_T
  rtu_left_curvature_rate, real32_T rtu_left_curvature, real32_T
  rtu_left_relative_yaw_heading, real32_T rtu_left_lateral_offset, real32_T
  rtu_right_curvature_rate, real32_T rtu_right_curvature, real32_T
  rtu_right_relative_yaw_heading, real32_T rtu_right_lateral_offset,
  B_EstimateLaneCenter_estimate_lane_center_T *localB,
  DW_EstimateLaneCenter_estimate_lane_center_T *localDW)
{
  real_T rtb_Product;
  real32_T rtb_Product1;

  /* MATLAB Function: '<S4>/MATLAB Function' */
  if ((rtu_left_strength > 0.0F) && (rtu_right_strength > 0.0F)) {
    /* Outputs for Function Call SubSystem: '<S4>/Center from Left and Right' */
    /* Gain: '<S8>/Gain' incorporates:
     *  Sum: '<S8>/Add'
     */
    localB->Curvature_o = (rtu_left_curvature + rtu_right_curvature) * 0.5F;

    /* Gain: '<S8>/Gain1' incorporates:
     *  Sum: '<S8>/Add1'
     */
    localB->CurvatureDerivative_g = (rtu_left_curvature_rate +
      rtu_right_curvature_rate) * 0.5F;

    /* Gain: '<S8>/Gain2' incorporates:
     *  Sum: '<S8>/Add2'
     */
    localB->HeadingAngle_j = (rtu_left_relative_yaw_heading +
      rtu_right_relative_yaw_heading) * 0.5F;

    /* Gain: '<S8>/Gain3' incorporates:
     *  Sum: '<S8>/Add3'
     */
    localB->LateralOffset_b = (rtu_left_lateral_offset +
      rtu_right_lateral_offset) * 0.5F;

    /* End of Outputs for SubSystem: '<S4>/Center from Left and Right' */
  } else if (rtu_left_strength > 0.0F) {
    /* Outputs for Function Call SubSystem: '<S4>/Center from Left' */
    /* Sum: '<S7>/Subtract' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Half Lane Width Estimate'
     *  Product: '<S7>/Product'
     */
    rtb_Product1 = 1.0F - rtu_left_curvature * 1.8F;

    /* Product: '<S7>/Divide' */
    localB->Curvature_o = rtu_left_curvature / rtb_Product1;

    /* Product: '<S7>/Product1' */
    rtb_Product1 *= rtb_Product1;

    /* Product: '<S7>/Divide1' */
    localB->CurvatureDerivative_g = rtu_left_curvature_rate / rtb_Product1;

    /* Sum: '<S7>/Subtract1' incorporates:
     *  Constant: '<S7>/Half Lane Width Estimate1'
     */
    localB->LateralOffset_b = rtu_left_lateral_offset - 1.8F;

    /* SignalConversion generated from: '<S7>/Center' */
    localB->HeadingAngle_j = rtu_left_relative_yaw_heading;

    /* End of Outputs for SubSystem: '<S4>/Center from Left' */
  } else if (rtu_right_strength > 0.0F) {
    /* Outputs for Function Call SubSystem: '<S4>/Center from Right' */
    /* Sum: '<S10>/Subtract' incorporates:
     *  Constant: '<S10>/Constant'
     *  Constant: '<S10>/Half Lane Width Estimate'
     *  Product: '<S10>/Product'
     */
    rtb_Product1 = rtu_right_curvature * 1.8F + 1.0F;

    /* Product: '<S10>/Divide' */
    localB->Curvature_o = rtu_right_curvature / rtb_Product1;

    /* Product: '<S10>/Product1' */
    rtb_Product1 *= rtb_Product1;

    /* Product: '<S10>/Divide1' */
    localB->CurvatureDerivative_g = rtu_right_curvature_rate / rtb_Product1;

    /* Sum: '<S10>/Subtract1' incorporates:
     *  Constant: '<S10>/Half Lane Width Estimate1'
     */
    localB->LateralOffset_b = rtu_right_lateral_offset + 1.8F;

    /* SignalConversion generated from: '<S10>/Center' */
    localB->HeadingAngle_j = rtu_right_relative_yaw_heading;

    /* End of Outputs for SubSystem: '<S4>/Center from Right' */
  } else {
    /* Outputs for Function Call SubSystem: '<S4>/Center from None' */
    /* SignalConversion generated from: '<S9>/Out1' incorporates:
     *  Delay generated from: '<S4>/Delay'
     */
    localB->Curvature_o = localDW->Delay_1_DSTATE;

    /* SignalConversion generated from: '<S9>/Out1' incorporates:
     *  Delay generated from: '<S4>/Delay'
     */
    localB->CurvatureDerivative_g = localDW->Delay_2_DSTATE;

    /* SignalConversion generated from: '<S9>/Out1' incorporates:
     *  Delay generated from: '<S4>/Delay'
     */
    localB->HeadingAngle_j = localDW->Delay_3_DSTATE;

    /* SignalConversion generated from: '<S9>/Out1' incorporates:
     *  Delay generated from: '<S4>/Delay'
     */
    localB->LateralOffset_b = localDW->Delay_4_DSTATE;

    /* End of Outputs for SubSystem: '<S4>/Center from None' */
  }

  /* End of MATLAB Function: '<S4>/MATLAB Function' */

  /* Saturate: '<S4>/Saturation3' incorporates:
   *  UnaryMinus: '<S11>/Unary Minus1'
   */
  if (-localB->CurvatureDerivative_g > 0.06F) {
    rtb_Product1 = 0.06F;
  } else if (-localB->CurvatureDerivative_g < -0.06F) {
    rtb_Product1 = -0.06F;
  } else {
    rtb_Product1 = -localB->CurvatureDerivative_g;
  }

  /* End of Saturate: '<S4>/Saturation3' */

  /* Product: '<S13>/Product' */
  rtb_Product = rtb_Product1 * rtu_LongitudinalVelocity;

  /* Saturate: '<S4>/Saturation2' incorporates:
   *  UnaryMinus: '<S11>/Unary Minus'
   */
  if (-localB->Curvature_o > 0.15F) {
    rtb_Product1 = 0.15F;
  } else if (-localB->Curvature_o < -0.15F) {
    rtb_Product1 = -0.15F;
  } else {
    rtb_Product1 = -localB->Curvature_o;
  }

  /* End of Saturate: '<S4>/Saturation2' */

  /* Sum: '<S13>/Sum' incorporates:
   *  Gain: '<S13>/Gain'
   */
  localB->Sum[0] = 0.0 * rtb_Product + rtb_Product1;
  localB->Sum[1] = 0.1 * rtb_Product + rtb_Product1;
  localB->Sum[2] = 0.2 * rtb_Product + rtb_Product1;
}

/* Update for atomic system: '<S2>/Estimate Lane Center' */
void estimate_lane_center_EstimateLaneCenter_Update
  (B_EstimateLaneCenter_estimate_lane_center_T *localB,
   DW_EstimateLaneCenter_estimate_lane_center_T *localDW)
{
  /* Update for Delay generated from: '<S4>/Delay' */
  localDW->Delay_4_DSTATE = localB->LateralOffset_b;

  /* Update for Delay generated from: '<S4>/Delay' */
  localDW->Delay_3_DSTATE = localB->HeadingAngle_j;

  /* Update for Delay generated from: '<S4>/Delay' */
  localDW->Delay_2_DSTATE = localB->CurvatureDerivative_g;

  /* Update for Delay generated from: '<S4>/Delay' */
  localDW->Delay_1_DSTATE = localB->Curvature_o;
}
