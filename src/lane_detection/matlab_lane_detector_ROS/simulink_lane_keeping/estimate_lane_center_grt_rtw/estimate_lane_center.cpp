/*
 * estimate_lane_center.cpp
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

#include "estimate_lane_center.h"
#include "estimate_lane_center_private.h"

/* Model step function */
void estimate_lane_centerModelClass::step()
{
  /* (no output/update code required) */
}

/* Model initialize function */
void estimate_lane_centerModelClass::initialize()
{
  /* (no initialization code required) */
}

/* Model terminate function */
void estimate_lane_centerModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
estimate_lane_centerModelClass::estimate_lane_centerModelClass() :
  estimate_lane_center_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
estimate_lane_centerModelClass::~estimate_lane_centerModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_estimate_lane_center_T * estimate_lane_centerModelClass::getRTM()
{
  return (&estimate_lane_center_M);
}
