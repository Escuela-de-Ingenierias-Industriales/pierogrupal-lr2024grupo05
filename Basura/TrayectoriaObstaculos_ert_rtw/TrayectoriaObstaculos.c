/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TrayectoriaObstaculos.c
 *
 * Code generated for Simulink model 'TrayectoriaObstaculos'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec 12 11:25:16 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TrayectoriaObstaculos.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include <string.h>
#include "TrayectoriaObstaculos_private.h"
#include <math.h>
#include "rt_defines.h"

/* Named constants for Chart: '<Root>/Chart' */
#define TrayectoriaO_IN_ObstaculoFrente ((uint8_T)2U)
#define TrayectoriaObs_IN_SinObstaculos ((uint8_T)4U)
#define TrayectoriaObst_IN_ObstaculoDer ((uint8_T)1U)
#define TrayectoriaObst_IN_ObstaculoIzq ((uint8_T)3U)
#define TrayectoriaObstaculo_IN_entrada ((uint8_T)5U)

/* Block signals (default storage) */
B_TrayectoriaObstaculos_T TrayectoriaObstaculos_B;

/* Block states (default storage) */
DW_TrayectoriaObstaculos_T TrayectoriaObstaculos_DW;

/* Real-time model */
static RT_MODEL_TrayectoriaObstaculo_T TrayectoriaObstaculos_M_;
RT_MODEL_TrayectoriaObstaculo_T *const TrayectoriaObstaculos_M =
  &TrayectoriaObstaculos_M_;

/* Forward declaration for local functions */
static real_T TrayectoriaObstaculos_norm(const real_T x[2]);
static void TrayectoriaO_closestPointOnLine(const real_T pt1[2], const real_T
  pt2[2], const real_T refPt[2], real_T closestPoint[2], real_T *distance);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void TrayectoriaObstaculos_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(TrayectoriaObstaculos_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  TrayectoriaObstaculos_M->Timing.RateInteraction.TID0_1 =
    (TrayectoriaObstaculos_M->Timing.TaskCounters.TID[1] == 0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (TrayectoriaObstaculos_M->Timing.TaskCounters.TID[1])++;
  if ((TrayectoriaObstaculos_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.05s, 0.0s] */
    TrayectoriaObstaculos_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static real_T TrayectoriaObstaculos_norm(const real_T x[2])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;

  /* Start for MATLABSystem: '<Root>/Pure Pursuit' */
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  /* Start for MATLABSystem: '<Root>/Pure Pursuit' */
  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

static void TrayectoriaO_closestPointOnLine(const real_T pt1[2], const real_T
  pt2[2], const real_T refPt[2], real_T closestPoint[2], real_T *distance)
{
  int16_T b_k;
  boolean_T exitg1;
  boolean_T p;
  boolean_T p_0;
  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 2)) {
    if (!(pt1[b_k] == pt2[b_k])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (p) {
    closestPoint[0] = pt1[0];
    TrayectoriaObstaculos_B.refPt[0] = refPt[0] - pt1[0];
    closestPoint[1] = pt1[1];
    TrayectoriaObstaculos_B.refPt[1] = refPt[1] - pt1[1];
    *distance = TrayectoriaObstaculos_norm(TrayectoriaObstaculos_B.refPt);
  } else {
    TrayectoriaObstaculos_B.alpha = pt2[0] - pt1[0];

    /* Start for MATLABSystem: '<Root>/Pure Pursuit' */
    TrayectoriaObstaculos_B.v12 = (pt2[0] - refPt[0]) *
      TrayectoriaObstaculos_B.alpha;
    TrayectoriaObstaculos_B.v12_k = TrayectoriaObstaculos_B.alpha *
      TrayectoriaObstaculos_B.alpha;
    TrayectoriaObstaculos_B.alpha = pt2[1] - pt1[1];

    /* Start for MATLABSystem: '<Root>/Pure Pursuit' */
    TrayectoriaObstaculos_B.alpha = ((pt2[1] - refPt[1]) *
      TrayectoriaObstaculos_B.alpha + TrayectoriaObstaculos_B.v12) /
      (TrayectoriaObstaculos_B.alpha * TrayectoriaObstaculos_B.alpha +
       TrayectoriaObstaculos_B.v12_k);
    p = (TrayectoriaObstaculos_B.alpha > 1.0);
    p_0 = (TrayectoriaObstaculos_B.alpha < 0.0);
    if (p) {
      TrayectoriaObstaculos_B.v12 = pt1[0];
    } else if (p_0) {
      TrayectoriaObstaculos_B.v12 = pt2[0];
    } else {
      TrayectoriaObstaculos_B.v12 = (1.0 - TrayectoriaObstaculos_B.alpha) * pt2
        [0] + TrayectoriaObstaculos_B.alpha * pt1[0];
    }

    closestPoint[0] = TrayectoriaObstaculos_B.v12;
    TrayectoriaObstaculos_B.refPt[0] = refPt[0] - TrayectoriaObstaculos_B.v12;
    if (p) {
      TrayectoriaObstaculos_B.v12 = pt1[1];
    } else if (p_0) {
      TrayectoriaObstaculos_B.v12 = pt2[1];
    } else {
      TrayectoriaObstaculos_B.v12 = (1.0 - TrayectoriaObstaculos_B.alpha) * pt2
        [1] + TrayectoriaObstaculos_B.alpha * pt1[1];
    }

    closestPoint[1] = TrayectoriaObstaculos_B.v12;
    TrayectoriaObstaculos_B.refPt[1] = refPt[1] - TrayectoriaObstaculos_B.v12;
    *distance = TrayectoriaObstaculos_norm(TrayectoriaObstaculos_B.refPt);
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T tmp;
  int16_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function for TID0 */
void TrayectoriaObstaculos_step0(void) /* Sample time: [0.01s, 0.0s] */
{
  int32_T rtb_Encoder1_0;
  int32_T rtb_Encoder_0;
  int16_T b_k;
  int16_T i;
  int16_T i_0;
  int16_T partialTrueCount;
  int16_T tmp_size_idx_0;
  int8_T tmp_data[4];
  boolean_T tmp[4];
  boolean_T tmp_0[4];
  boolean_T exitg1;
  boolean_T p;
  boolean_T rEQ0;
  boolean_T searchFlag;
  boolean_T tmp_1;
  boolean_T tmp_2;

  {                                    /* Sample time: [0.01s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S158>/Encoder' */
  if (TrayectoriaObstaculos_DW.obj_k.SampleTime !=
      TrayectoriaObstaculos_P.Encoder_SampleTime) {
    TrayectoriaObstaculos_DW.obj_k.SampleTime =
      TrayectoriaObstaculos_P.Encoder_SampleTime;
  }

  if (TrayectoriaObstaculos_DW.obj_k.TunablePropsChanged) {
    TrayectoriaObstaculos_DW.obj_k.TunablePropsChanged = false;
  }

  MW_EncoderRead(TrayectoriaObstaculos_DW.obj_k.Index, &rtb_Encoder_0);

  /* MATLABSystem: '<S158>/Encoder1' */
  if (TrayectoriaObstaculos_DW.obj_h.SampleTime !=
      TrayectoriaObstaculos_P.Encoder1_SampleTime) {
    TrayectoriaObstaculos_DW.obj_h.SampleTime =
      TrayectoriaObstaculos_P.Encoder1_SampleTime;
  }

  if (TrayectoriaObstaculos_DW.obj_h.TunablePropsChanged) {
    TrayectoriaObstaculos_DW.obj_h.TunablePropsChanged = false;
  }

  MW_EncoderRead(TrayectoriaObstaculos_DW.obj_h.Index, &rtb_Encoder1_0);

  /* Gain: '<S158>/Gain' */
  TrayectoriaObstaculos_B.rtb_TSamp_idx_1 = (real_T)
    TrayectoriaObstaculos_P.Gain_Gain * 1.1368683772161603E-13;

  /* SampleTimeMath: '<S161>/TSamp' incorporates:
   *  Gain: '<S158>/Gain'
   *  MATLABSystem: '<S158>/Encoder'
   *  MATLABSystem: '<S158>/Encoder1'
   *
   * About '<S161>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  TrayectoriaObstaculos_B.rtb_TSamp_idx_0 =
    TrayectoriaObstaculos_B.rtb_TSamp_idx_1 * (real_T)rtb_Encoder_0 *
    TrayectoriaObstaculos_P.TSamp_WtEt;
  TrayectoriaObstaculos_B.rtb_TSamp_idx_1 =
    TrayectoriaObstaculos_B.rtb_TSamp_idx_1 * (real_T)rtb_Encoder1_0 *
    TrayectoriaObstaculos_P.TSamp_WtEt;

  /* Sum: '<S161>/Diff' incorporates:
   *  UnitDelay: '<S161>/UD'
   *
   * Block description for '<S161>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S161>/UD':
   *
   *  Store in Global RAM
   */
  TrayectoriaObstaculos_DW.UD_DSTATE[0] =
    TrayectoriaObstaculos_B.rtb_TSamp_idx_0 -
    TrayectoriaObstaculos_DW.UD_DSTATE[0];
  TrayectoriaObstaculos_DW.UD_DSTATE[1] =
    TrayectoriaObstaculos_B.rtb_TSamp_idx_1 -
    TrayectoriaObstaculos_DW.UD_DSTATE[1];

  /* Product: '<S4>/Matrix Multiply' incorporates:
   *  Constant: '<S4>/Jacobiano directo'
   */
  TrayectoriaObstaculos_B.rtb_MatrixMultiply_c =
    TrayectoriaObstaculos_P.Jacobianodirecto_Value[0] *
    TrayectoriaObstaculos_DW.UD_DSTATE[0] + TrayectoriaObstaculos_DW.UD_DSTATE[1]
    * TrayectoriaObstaculos_P.Jacobianodirecto_Value[2];

  /* RateTransition: '<S7>/Rate Transition' */
  if (TrayectoriaObstaculos_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition: '<S7>/Rate Transition' */
    TrayectoriaObstaculos_B.RateTransition[0] =
      TrayectoriaObstaculos_DW.RateTransition_Buffer0[0];
    TrayectoriaObstaculos_B.RateTransition[1] =
      TrayectoriaObstaculos_DW.RateTransition_Buffer0[1];
    TrayectoriaObstaculos_B.RateTransition[2] =
      TrayectoriaObstaculos_DW.RateTransition_Buffer0[2];
  }

  /* End of RateTransition: '<S7>/Rate Transition' */

  /* Chart: '<Root>/Chart' */
  if (TrayectoriaObstaculos_DW.temporalCounter_i1 < 255U) {
    TrayectoriaObstaculos_DW.temporalCounter_i1++;
  }

  if (TrayectoriaObstaculos_DW.is_active_c3_TrayectoriaObstacu == 0U) {
    TrayectoriaObstaculos_DW.is_active_c3_TrayectoriaObstacu = 1U;
    TrayectoriaObstaculos_DW.temporalCounter_i1 = 0U;
    TrayectoriaObstaculos_DW.is_c3_TrayectoriaObstaculos =
      TrayectoriaObstaculo_IN_entrada;
    TrayectoriaObstaculos_B.V = 0.0;
    TrayectoriaObstaculos_B.W = 0.0;
    TrayectoriaObstaculos_B.c = 1.0;
  } else {
    switch (TrayectoriaObstaculos_DW.is_c3_TrayectoriaObstaculos) {
     case TrayectoriaObst_IN_ObstaculoDer:
      if (TrayectoriaObstaculos_DW.temporalCounter_i1 >= 100U) {
        TrayectoriaObstaculos_DW.is_c3_TrayectoriaObstaculos =
          TrayectoriaObs_IN_SinObstaculos;
        TrayectoriaObstaculos_B.V = 0.0;
        TrayectoriaObstaculos_B.W = 0.0;
        TrayectoriaObstaculos_B.c = 0.0;
      } else if (TrayectoriaObstaculos_B.RateTransition[2] < 40.0) {
        TrayectoriaObstaculos_DW.temporalCounter_i1 = 0U;
        TrayectoriaObstaculos_DW.is_c3_TrayectoriaObstaculos =
          TrayectoriaO_IN_ObstaculoFrente;
        TrayectoriaObstaculos_B.V = 0.0;
        TrayectoriaObstaculos_B.W = 1.5707963267948966;
        TrayectoriaObstaculos_B.c = 1.0;
      }
      break;

     case TrayectoriaO_IN_ObstaculoFrente:
      if (TrayectoriaObstaculos_DW.temporalCounter_i1 >= 150U) {
        TrayectoriaObstaculos_DW.is_c3_TrayectoriaObstaculos =
          TrayectoriaObs_IN_SinObstaculos;
        TrayectoriaObstaculos_B.V = 0.0;
        TrayectoriaObstaculos_B.W = 0.0;
        TrayectoriaObstaculos_B.c = 0.0;
      }
      break;

     case TrayectoriaObst_IN_ObstaculoIzq:
      if (TrayectoriaObstaculos_B.RateTransition[0] < 40.0) {
        TrayectoriaObstaculos_DW.temporalCounter_i1 = 0U;
        TrayectoriaObstaculos_DW.is_c3_TrayectoriaObstaculos =
          TrayectoriaO_IN_ObstaculoFrente;
        TrayectoriaObstaculos_B.V = 0.0;
        TrayectoriaObstaculos_B.W = 1.5707963267948966;
        TrayectoriaObstaculos_B.c = 1.0;
      } else if (TrayectoriaObstaculos_DW.temporalCounter_i1 >= 100U) {
        TrayectoriaObstaculos_DW.is_c3_TrayectoriaObstaculos =
          TrayectoriaObs_IN_SinObstaculos;
        TrayectoriaObstaculos_B.V = 0.0;
        TrayectoriaObstaculos_B.W = 0.0;
        TrayectoriaObstaculos_B.c = 0.0;
      }
      break;

     case TrayectoriaObs_IN_SinObstaculos:
      if (TrayectoriaObstaculos_B.RateTransition[2] < 40.0) {
        TrayectoriaObstaculos_DW.temporalCounter_i1 = 0U;
        TrayectoriaObstaculos_DW.is_c3_TrayectoriaObstaculos =
          TrayectoriaObst_IN_ObstaculoIzq;
        TrayectoriaObstaculos_B.V = 0.1;
        TrayectoriaObstaculos_B.W = -0.78539816339744828;
        TrayectoriaObstaculos_B.c = 1.0;
      } else if (TrayectoriaObstaculos_B.RateTransition[0] < 40.0) {
        TrayectoriaObstaculos_DW.temporalCounter_i1 = 0U;
        TrayectoriaObstaculos_DW.is_c3_TrayectoriaObstaculos =
          TrayectoriaObst_IN_ObstaculoDer;
        TrayectoriaObstaculos_B.V = 0.1;
        TrayectoriaObstaculos_B.W = 0.78539816339744828;
        TrayectoriaObstaculos_B.c = 1.0;
      }
      break;

     default:
      /* case IN_entrada: */
      if (TrayectoriaObstaculos_DW.temporalCounter_i1 >= 200U) {
        TrayectoriaObstaculos_DW.is_c3_TrayectoriaObstaculos =
          TrayectoriaObs_IN_SinObstaculos;
        TrayectoriaObstaculos_B.V = 0.0;
        TrayectoriaObstaculos_B.W = 0.0;
        TrayectoriaObstaculos_B.c = 0.0;
      } else {
        TrayectoriaObstaculos_B.V = 0.0;
        TrayectoriaObstaculos_B.W = 0.0;
        TrayectoriaObstaculos_B.c = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* MATLABSystem: '<Root>/Pure Pursuit' incorporates:
   *  Constant: '<Root>/Constant'
   * */
  if (TrayectoriaObstaculos_DW.obj.DesiredLinearVelocity !=
      TrayectoriaObstaculos_P.PurePursuit_DesiredLinearVeloci) {
    TrayectoriaObstaculos_DW.obj.DesiredLinearVelocity =
      TrayectoriaObstaculos_P.PurePursuit_DesiredLinearVeloci;
  }

  if (TrayectoriaObstaculos_DW.obj.MaxAngularVelocity !=
      TrayectoriaObstaculos_P.PurePursuit_MaxAngularVelocity) {
    TrayectoriaObstaculos_DW.obj.MaxAngularVelocity =
      TrayectoriaObstaculos_P.PurePursuit_MaxAngularVelocity;
  }

  if (TrayectoriaObstaculos_DW.obj.LookaheadDistance !=
      TrayectoriaObstaculos_P.PurePursuit_LookaheadDistance) {
    TrayectoriaObstaculos_DW.obj.LookaheadDistance =
      TrayectoriaObstaculos_P.PurePursuit_LookaheadDistance;
  }

  rEQ0 = false;
  p = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 8)) {
    if ((TrayectoriaObstaculos_DW.obj.WaypointsInternal[b_k] ==
         TrayectoriaObstaculos_P.Constant_Value_c[b_k]) || (rtIsNaN
         (TrayectoriaObstaculos_DW.obj.WaypointsInternal[b_k]) && rtIsNaN
         (TrayectoriaObstaculos_P.Constant_Value_c[b_k]))) {
      b_k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (p) {
    rEQ0 = true;
  }

  if (!rEQ0) {
    memcpy(&TrayectoriaObstaculos_DW.obj.WaypointsInternal[0],
           &TrayectoriaObstaculos_P.Constant_Value_c[0], sizeof(real_T) << 3U);
    TrayectoriaObstaculos_DW.obj.ProjectionLineIndex = 0.0;
  }

  for (b_k = 0; b_k < 8; b_k++) {
    TrayectoriaObstaculos_B.b[b_k] = !rtIsNaN
      (TrayectoriaObstaculos_P.Constant_Value_c[b_k]);
  }

  /* Start for MATLABSystem: '<Root>/Pure Pursuit' */
  rEQ0 = (TrayectoriaObstaculos_B.b[0] && TrayectoriaObstaculos_B.b[4]);
  tmp[0] = rEQ0;
  p = (TrayectoriaObstaculos_B.b[1] && TrayectoriaObstaculos_B.b[5]);
  tmp[1] = p;
  tmp_1 = (TrayectoriaObstaculos_B.b[2] && TrayectoriaObstaculos_B.b[6]);
  tmp[2] = tmp_1;
  tmp_2 = (TrayectoriaObstaculos_B.b[3] && TrayectoriaObstaculos_B.b[7]);
  tmp[3] = tmp_2;
  partialTrueCount = 0;

  /* Start for MATLABSystem: '<Root>/Pure Pursuit' */
  tmp_0[0] = rEQ0;
  tmp_0[1] = p;
  tmp_0[2] = tmp_1;
  tmp_0[3] = tmp_2;
  b_k = 0;
  for (i = 0; i < 4; i++) {
    /* Start for MATLABSystem: '<Root>/Pure Pursuit' */
    if (tmp[i]) {
      tmp_data[partialTrueCount] = (int8_T)i;
      partialTrueCount++;
    }

    if (tmp_0[i]) {
      b_k++;
    }
  }

  partialTrueCount = b_k;

  /* MATLABSystem: '<Root>/Pure Pursuit' incorporates:
   *  Constant: '<Root>/Constant'
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   * */
  if (b_k == 0) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 = 0.0;
    TrayectoriaObstaculos_B.dist = 0.0;
  } else {
    searchFlag = false;
    if (TrayectoriaObstaculos_DW.obj.ProjectionLineIndex == 0.0) {
      searchFlag = true;
      TrayectoriaObstaculos_DW.obj.ProjectionPoint[0] =
        TrayectoriaObstaculos_P.Constant_Value_c[tmp_data[0]];
      TrayectoriaObstaculos_DW.obj.ProjectionPoint[1] =
        TrayectoriaObstaculos_P.Constant_Value_c[tmp_data[0] + 4];
      TrayectoriaObstaculos_DW.obj.ProjectionLineIndex = 1.0;
    }

    tmp[0] = rEQ0;
    tmp[1] = p;
    tmp[2] = tmp_1;
    tmp[3] = tmp_2;
    b_k = 0;
    for (i = 0; i < 4; i++) {
      if (tmp[i]) {
        b_k++;
      }
    }

    tmp_size_idx_0 = b_k;
    if (b_k == 1) {
      TrayectoriaObstaculos_DW.obj.ProjectionPoint[0] =
        TrayectoriaObstaculos_P.Constant_Value_c[tmp_data[0]];
      TrayectoriaObstaculos_DW.obj.ProjectionPoint[1] =
        TrayectoriaObstaculos_P.Constant_Value_c[tmp_data[0] + 4];
    } else {
      b_k = tmp_data[(int16_T)(TrayectoriaObstaculos_DW.obj.ProjectionLineIndex
        + 1.0) - 1];
      TrayectoriaObstaculos_B.lookaheadStartPt_m[0] =
        TrayectoriaObstaculos_P.Constant_Value_c[b_k];
      TrayectoriaObstaculos_B.lookaheadStartPt_m[1] =
        TrayectoriaObstaculos_P.Constant_Value_c[b_k + 4];
      for (i_0 = 0; i_0 < 2; i_0++) {
        TrayectoriaObstaculos_B.dv1[i_0] =
          TrayectoriaObstaculos_DW.obj.ProjectionPoint[i_0];
      }

      TrayectoriaO_closestPointOnLine(TrayectoriaObstaculos_B.dv1,
        TrayectoriaObstaculos_B.lookaheadStartPt_m,
        &TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0],
        TrayectoriaObstaculos_DW.obj.ProjectionPoint,
        &TrayectoriaObstaculos_B.minDistance);
      b_k = tmp_data[(int16_T)(TrayectoriaObstaculos_DW.obj.ProjectionLineIndex
        + 1.0) - 1];
      TrayectoriaObstaculos_B.lookaheadStartPt_m[0] =
        TrayectoriaObstaculos_DW.obj.ProjectionPoint[0] -
        TrayectoriaObstaculos_P.Constant_Value_c[b_k];
      TrayectoriaObstaculos_B.lookaheadStartPt_m[1] =
        TrayectoriaObstaculos_DW.obj.ProjectionPoint[1] -
        TrayectoriaObstaculos_P.Constant_Value_c[b_k + 4];
      TrayectoriaObstaculos_B.dist = TrayectoriaObstaculos_norm
        (TrayectoriaObstaculos_B.lookaheadStartPt_m);
      TrayectoriaObstaculos_B.overshootDist =
        TrayectoriaObstaculos_DW.obj.ProjectionLineIndex + 1.0;
      i = (int16_T)((1.0 - (TrayectoriaObstaculos_DW.obj.ProjectionLineIndex +
                            1.0)) + ((real_T)partialTrueCount - 1.0)) - 1;
      partialTrueCount = 0;
      exitg1 = false;
      while ((!exitg1) && (partialTrueCount <= i)) {
        TrayectoriaObstaculos_B.i = TrayectoriaObstaculos_B.overshootDist +
          (real_T)partialTrueCount;
        if ((!searchFlag) && (TrayectoriaObstaculos_B.dist >
                              TrayectoriaObstaculos_DW.obj.LookaheadDistance)) {
          exitg1 = true;
        } else {
          b_k = tmp_data[(int16_T)TrayectoriaObstaculos_B.i - 1];
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
            TrayectoriaObstaculos_P.Constant_Value_c[b_k];
          i_0 = tmp_data[(int16_T)(TrayectoriaObstaculos_B.i + 1.0) - 1];
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
            TrayectoriaObstaculos_P.Constant_Value_c[i_0];
          TrayectoriaObstaculos_B.lookaheadStartPt_m[0] =
            TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 -
            TrayectoriaObstaculos_B.lookaheadEndPt_idx_1;
          TrayectoriaObstaculos_B.dv1[0] =
            TrayectoriaObstaculos_B.lookaheadEndPt_idx_0;
          TrayectoriaObstaculos_B.dv[0] =
            TrayectoriaObstaculos_B.lookaheadEndPt_idx_1;
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
            TrayectoriaObstaculos_P.Constant_Value_c[b_k + 4];
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
            TrayectoriaObstaculos_P.Constant_Value_c[i_0 + 4];
          TrayectoriaObstaculos_B.lookaheadStartPt_m[1] =
            TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 -
            TrayectoriaObstaculos_B.lookaheadEndPt_idx_1;
          TrayectoriaObstaculos_B.dv1[1] =
            TrayectoriaObstaculos_B.lookaheadEndPt_idx_0;
          TrayectoriaObstaculos_B.dv[1] =
            TrayectoriaObstaculos_B.lookaheadEndPt_idx_1;
          TrayectoriaObstaculos_B.dist += TrayectoriaObstaculos_norm
            (TrayectoriaObstaculos_B.lookaheadStartPt_m);
          TrayectoriaO_closestPointOnLine(TrayectoriaObstaculos_B.dv1,
            TrayectoriaObstaculos_B.dv,
            &TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0],
            TrayectoriaObstaculos_B.lookaheadStartPt,
            &TrayectoriaObstaculos_B.lookaheadEndPt_idx_0);
          if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 <
              TrayectoriaObstaculos_B.minDistance) {
            TrayectoriaObstaculos_B.minDistance =
              TrayectoriaObstaculos_B.lookaheadEndPt_idx_0;
            TrayectoriaObstaculos_DW.obj.ProjectionPoint[0] =
              TrayectoriaObstaculos_B.lookaheadStartPt[0];
            TrayectoriaObstaculos_DW.obj.ProjectionPoint[1] =
              TrayectoriaObstaculos_B.lookaheadStartPt[1];
            TrayectoriaObstaculos_DW.obj.ProjectionLineIndex =
              TrayectoriaObstaculos_B.i;
          }

          partialTrueCount++;
        }
      }
    }

    if (tmp_size_idx_0 == 1) {
      TrayectoriaObstaculos_DW.obj.LookaheadPoint[0] =
        TrayectoriaObstaculos_P.Constant_Value_c[tmp_data[0]];
      TrayectoriaObstaculos_DW.obj.LookaheadPoint[1] =
        TrayectoriaObstaculos_P.Constant_Value_c[tmp_data[0] + 4];
    } else {
      b_k = tmp_data[(int16_T)(TrayectoriaObstaculos_DW.obj.ProjectionLineIndex
        + 1.0) - 1];
      TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
        TrayectoriaObstaculos_P.Constant_Value_c[b_k];
      TrayectoriaObstaculos_B.lookaheadStartPt_m[0] =
        TrayectoriaObstaculos_DW.obj.ProjectionPoint[0] -
        TrayectoriaObstaculos_B.lookaheadEndPt_idx_0;
      TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
        TrayectoriaObstaculos_P.Constant_Value_c[b_k + 4];
      TrayectoriaObstaculos_B.lookaheadStartPt_m[1] =
        TrayectoriaObstaculos_DW.obj.ProjectionPoint[1] -
        TrayectoriaObstaculos_B.lookaheadEndPt_idx_1;
      TrayectoriaObstaculos_B.dist = TrayectoriaObstaculos_norm
        (TrayectoriaObstaculos_B.lookaheadStartPt_m);
      TrayectoriaObstaculos_B.lookaheadStartPt[0] =
        TrayectoriaObstaculos_DW.obj.ProjectionPoint[0];
      TrayectoriaObstaculos_B.lookaheadStartPt[1] =
        TrayectoriaObstaculos_DW.obj.ProjectionPoint[1];
      TrayectoriaObstaculos_B.overshootDist = TrayectoriaObstaculos_B.dist -
        TrayectoriaObstaculos_DW.obj.LookaheadDistance;
      TrayectoriaObstaculos_B.minDistance =
        TrayectoriaObstaculos_DW.obj.ProjectionLineIndex;
      while ((TrayectoriaObstaculos_B.overshootDist < 0.0) &&
             (TrayectoriaObstaculos_B.minDistance < (real_T)tmp_size_idx_0 - 1.0))
      {
        TrayectoriaObstaculos_B.minDistance++;
        b_k = tmp_data[(int16_T)TrayectoriaObstaculos_B.minDistance - 1];
        TrayectoriaObstaculos_B.overshootDist =
          TrayectoriaObstaculos_P.Constant_Value_c[b_k];
        TrayectoriaObstaculos_B.lookaheadStartPt[0] =
          TrayectoriaObstaculos_B.overshootDist;
        i = tmp_data[(int16_T)(TrayectoriaObstaculos_B.minDistance + 1.0) - 1];
        TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
          TrayectoriaObstaculos_P.Constant_Value_c[i];
        TrayectoriaObstaculos_B.lookaheadStartPt_m[0] =
          TrayectoriaObstaculos_B.overshootDist -
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_0;
        TrayectoriaObstaculos_B.overshootDist =
          TrayectoriaObstaculos_P.Constant_Value_c[b_k + 4];
        TrayectoriaObstaculos_B.lookaheadStartPt[1] =
          TrayectoriaObstaculos_B.overshootDist;
        TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
          TrayectoriaObstaculos_P.Constant_Value_c[i + 4];
        TrayectoriaObstaculos_B.lookaheadStartPt_m[1] =
          TrayectoriaObstaculos_B.overshootDist -
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_1;
        TrayectoriaObstaculos_B.dist += TrayectoriaObstaculos_norm
          (TrayectoriaObstaculos_B.lookaheadStartPt_m);
        TrayectoriaObstaculos_B.overshootDist = TrayectoriaObstaculos_B.dist -
          TrayectoriaObstaculos_DW.obj.LookaheadDistance;
      }

      TrayectoriaObstaculos_B.lookaheadStartPt_m[0] =
        TrayectoriaObstaculos_B.lookaheadStartPt[0] -
        TrayectoriaObstaculos_B.lookaheadEndPt_idx_0;
      TrayectoriaObstaculos_B.lookaheadStartPt_m[1] =
        TrayectoriaObstaculos_B.lookaheadStartPt[1] -
        TrayectoriaObstaculos_B.lookaheadEndPt_idx_1;
      TrayectoriaObstaculos_B.dist = TrayectoriaObstaculos_B.overshootDist /
        TrayectoriaObstaculos_norm(TrayectoriaObstaculos_B.lookaheadStartPt_m);
      if (TrayectoriaObstaculos_B.dist > 0.0) {
        TrayectoriaObstaculos_DW.obj.LookaheadPoint[0] = (1.0 -
          TrayectoriaObstaculos_B.dist) *
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 +
          TrayectoriaObstaculos_B.dist *
          TrayectoriaObstaculos_B.lookaheadStartPt[0];
        TrayectoriaObstaculos_DW.obj.LookaheadPoint[1] = (1.0 -
          TrayectoriaObstaculos_B.dist) *
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 +
          TrayectoriaObstaculos_B.dist *
          TrayectoriaObstaculos_B.lookaheadStartPt[1];
      } else {
        TrayectoriaObstaculos_DW.obj.LookaheadPoint[0] =
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_0;
        TrayectoriaObstaculos_DW.obj.LookaheadPoint[1] =
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_1;
      }
    }

    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 = rt_atan2d_snf
      (TrayectoriaObstaculos_DW.obj.LookaheadPoint[1] -
       TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1],
       TrayectoriaObstaculos_DW.obj.LookaheadPoint[0] -
       TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0]) -
      TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];
    if (fabs(TrayectoriaObstaculos_B.lookaheadEndPt_idx_0) > 3.1415926535897931)
    {
      if (rtIsNaN(TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 +
                  3.1415926535897931) || rtIsInf
          (TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 + 3.1415926535897931)) {
        TrayectoriaObstaculos_B.dist = (rtNaN);
      } else if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 +
                 3.1415926535897931 == 0.0) {
        TrayectoriaObstaculos_B.dist = 0.0;
      } else {
        TrayectoriaObstaculos_B.dist = fmod
          (TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 + 3.1415926535897931,
           6.2831853071795862);
        rEQ0 = (TrayectoriaObstaculos_B.dist == 0.0);
        if (!rEQ0) {
          TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 = fabs
            ((TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 + 3.1415926535897931)
             / 6.2831853071795862);
          rEQ0 = !(fabs(TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 - floor
                        (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 + 0.5)) >
                   2.2204460492503131E-16 *
                   TrayectoriaObstaculos_B.lookaheadEndPt_idx_1);
        }

        if (rEQ0) {
          TrayectoriaObstaculos_B.dist = 0.0;
        } else if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 +
                   3.1415926535897931 < 0.0) {
          TrayectoriaObstaculos_B.dist += 6.2831853071795862;
        }
      }

      if ((TrayectoriaObstaculos_B.dist == 0.0) &&
          (TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 + 3.1415926535897931 >
           0.0)) {
        TrayectoriaObstaculos_B.dist = 6.2831853071795862;
      }

      TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
        TrayectoriaObstaculos_B.dist - 3.1415926535897931;
    }

    TrayectoriaObstaculos_B.dist = 2.0 * sin
      (TrayectoriaObstaculos_B.lookaheadEndPt_idx_0) /
      TrayectoriaObstaculos_DW.obj.LookaheadDistance;
    if ((fabs(fabs(TrayectoriaObstaculos_B.lookaheadEndPt_idx_0) -
              3.1415926535897931) < 1.4901161193847656E-8) && (!rtIsNaN
         (TrayectoriaObstaculos_B.dist))) {
      if (TrayectoriaObstaculos_B.dist < 0.0) {
        TrayectoriaObstaculos_B.dist = -1.0;
      } else {
        TrayectoriaObstaculos_B.dist = (TrayectoriaObstaculos_B.dist > 0.0);
      }
    }

    if (fabs(TrayectoriaObstaculos_B.dist) >
        TrayectoriaObstaculos_DW.obj.MaxAngularVelocity) {
      if (rtIsNaN(TrayectoriaObstaculos_B.dist)) {
        TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 = (rtNaN);
      } else if (TrayectoriaObstaculos_B.dist < 0.0) {
        TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 = -1.0;
      } else {
        TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
          (TrayectoriaObstaculos_B.dist > 0.0);
      }

      TrayectoriaObstaculos_B.dist =
        TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 *
        TrayectoriaObstaculos_DW.obj.MaxAngularVelocity;
    }

    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
      TrayectoriaObstaculos_DW.obj.DesiredLinearVelocity;
    TrayectoriaObstaculos_DW.obj.LastPose[0] =
      TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0];
    TrayectoriaObstaculos_DW.obj.LastPose[1] =
      TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1];
    TrayectoriaObstaculos_DW.obj.LastPose[2] =
      TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];
  }

  /* Switch: '<Root>/Switch' */
  if (TrayectoriaObstaculos_B.c > TrayectoriaObstaculos_P.Switch_Threshold) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 = TrayectoriaObstaculos_B.V;
    TrayectoriaObstaculos_B.dist = TrayectoriaObstaculos_B.W;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<S5>/Sum' incorporates:
   *  Constant: '<S3>/Jacobiano inverso'
   *  Product: '<S3>/Matrix Multiply'
   */
  TrayectoriaObstaculos_B.lookaheadStartPt[0] =
    (TrayectoriaObstaculos_P.Jacobianoinverso_Value[0] *
     TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 +
     TrayectoriaObstaculos_P.Jacobianoinverso_Value[2] *
     TrayectoriaObstaculos_B.dist) - TrayectoriaObstaculos_DW.UD_DSTATE[0];
  TrayectoriaObstaculos_B.lookaheadStartPt[1] =
    (TrayectoriaObstaculos_P.Jacobianoinverso_Value[1] *
     TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 +
     TrayectoriaObstaculos_P.Jacobianoinverso_Value[3] *
     TrayectoriaObstaculos_B.dist) - TrayectoriaObstaculos_DW.UD_DSTATE[1];

  /* Gain: '<S94>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S86>/Filter'
   *  Gain: '<S85>/Derivative Gain'
   *  Sum: '<S86>/SumD'
   */
  TrayectoriaObstaculos_B.dist = (TrayectoriaObstaculos_P.PIDder_D *
    TrayectoriaObstaculos_B.lookaheadStartPt[1] -
    TrayectoriaObstaculos_DW.Filter_DSTATE) * TrayectoriaObstaculos_P.PIDder_N;

  /* Sum: '<S100>/Sum' incorporates:
   *  DiscreteIntegrator: '<S91>/Integrator'
   *  Gain: '<S96>/Proportional Gain'
   */
  TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
    (TrayectoriaObstaculos_P.PIDder_P *
     TrayectoriaObstaculos_B.lookaheadStartPt[1] +
     TrayectoriaObstaculos_DW.Integrator_DSTATE) + TrayectoriaObstaculos_B.dist;

  /* Saturate: '<S98>/Saturation' */
  if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 >
      TrayectoriaObstaculos_P.PIDder_UpperSaturationLimit) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
      TrayectoriaObstaculos_P.PIDder_UpperSaturationLimit;
  } else if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 <
             TrayectoriaObstaculos_P.PIDder_LowerSaturationLimit) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
      TrayectoriaObstaculos_P.PIDder_LowerSaturationLimit;
  }

  /* End of Saturate: '<S98>/Saturation' */

  /* MATLABSystem: '<S157>/Enable Der' incorporates:
   *  Constant: '<S160>/Constant'
   *  RelationalOperator: '<S160>/Compare'
   */
  writeDigitalPin(12, (uint8_T)(TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 !=
    TrayectoriaObstaculos_P.Constant_Value_d));

  /* MATLABSystem: '<S157>/PWM Hacia Detrás Der' */
  TrayectoriaObstaculos_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (4UL);

  /* Saturate: '<S157>/Saturation3' */
  if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 >
      TrayectoriaObstaculos_P.Saturation3_UpperSat) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
      TrayectoriaObstaculos_P.Saturation3_UpperSat;
  } else if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 <
             TrayectoriaObstaculos_P.Saturation3_LowerSat) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
      TrayectoriaObstaculos_P.Saturation3_LowerSat;
  } else {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
      TrayectoriaObstaculos_B.lookaheadEndPt_idx_1;
  }

  /* Abs: '<S157>/Abs1' incorporates:
   *  Saturate: '<S157>/Saturation3'
   */
  TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 = fabs
    (TrayectoriaObstaculos_B.lookaheadEndPt_idx_0);

  /* Start for MATLABSystem: '<S157>/PWM Hacia Detrás Der' */
  if (!(TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 <= 255.0)) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 = 255.0;
  }

  /* MATLABSystem: '<S157>/PWM Hacia Detrás Der' */
  MW_PWM_SetDutyCycle(TrayectoriaObstaculos_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE,
                      TrayectoriaObstaculos_B.lookaheadEndPt_idx_0);

  /* MATLABSystem: '<S157>/PWM Hacia delante Der' */
  TrayectoriaObstaculos_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (5UL);

  /* Saturate: '<S157>/Saturation2' */
  if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 >
      TrayectoriaObstaculos_P.Saturation2_UpperSat) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
      TrayectoriaObstaculos_P.Saturation2_UpperSat;
  } else if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 <
             TrayectoriaObstaculos_P.Saturation2_LowerSat) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
      TrayectoriaObstaculos_P.Saturation2_LowerSat;
  }

  /* End of Saturate: '<S157>/Saturation2' */

  /* Start for MATLABSystem: '<S157>/PWM Hacia delante Der' */
  if (!(TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 <= 255.0)) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 = 255.0;
  }

  if (!(TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 >= 0.0)) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 = 0.0;
  }

  /* MATLABSystem: '<S157>/PWM Hacia delante Der' */
  MW_PWM_SetDutyCycle(TrayectoriaObstaculos_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                      TrayectoriaObstaculos_B.lookaheadEndPt_idx_1);

  /* Gain: '<S142>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S134>/Filter'
   *  Gain: '<S133>/Derivative Gain'
   *  Sum: '<S134>/SumD'
   */
  TrayectoriaObstaculos_B.minDistance = (TrayectoriaObstaculos_P.PIDizq_D *
    TrayectoriaObstaculos_B.lookaheadStartPt[0] -
    TrayectoriaObstaculos_DW.Filter_DSTATE_n) * TrayectoriaObstaculos_P.PIDizq_N;

  /* Sum: '<S148>/Sum' incorporates:
   *  DiscreteIntegrator: '<S139>/Integrator'
   *  Gain: '<S144>/Proportional Gain'
   */
  TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
    (TrayectoriaObstaculos_P.PIDizq_P *
     TrayectoriaObstaculos_B.lookaheadStartPt[0] +
     TrayectoriaObstaculos_DW.Integrator_DSTATE_c) +
    TrayectoriaObstaculos_B.minDistance;

  /* Saturate: '<S146>/Saturation' */
  if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 >
      TrayectoriaObstaculos_P.PIDizq_UpperSaturationLimit) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
      TrayectoriaObstaculos_P.PIDizq_UpperSaturationLimit;
  } else if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 <
             TrayectoriaObstaculos_P.PIDizq_LowerSaturationLimit) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
      TrayectoriaObstaculos_P.PIDizq_LowerSaturationLimit;
  }

  /* End of Saturate: '<S146>/Saturation' */

  /* MATLABSystem: '<S157>/Enable Izq' incorporates:
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S159>/Compare'
   */
  writeDigitalPin(13, (uint8_T)(TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 !=
    TrayectoriaObstaculos_P.Constant_Value));

  /* MATLABSystem: '<S157>/PWM Hacia Detrás Izq' */
  TrayectoriaObstaculos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (7UL);

  /* Saturate: '<S157>/Saturation1' */
  if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 >
      TrayectoriaObstaculos_P.Saturation1_UpperSat) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
      TrayectoriaObstaculos_P.Saturation1_UpperSat;
  } else if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 <
             TrayectoriaObstaculos_P.Saturation1_LowerSat) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
      TrayectoriaObstaculos_P.Saturation1_LowerSat;
  } else {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
      TrayectoriaObstaculos_B.lookaheadEndPt_idx_1;
  }

  /* Abs: '<S157>/Abs' incorporates:
   *  Saturate: '<S157>/Saturation1'
   */
  TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 = fabs
    (TrayectoriaObstaculos_B.lookaheadEndPt_idx_0);

  /* Start for MATLABSystem: '<S157>/PWM Hacia Detrás Izq' */
  if (!(TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 <= 255.0)) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 = 255.0;
  }

  /* MATLABSystem: '<S157>/PWM Hacia Detrás Izq' */
  MW_PWM_SetDutyCycle(TrayectoriaObstaculos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                      TrayectoriaObstaculos_B.lookaheadEndPt_idx_0);

  /* MATLABSystem: '<S157>/PWM Hacia delante Izq' */
  TrayectoriaObstaculos_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
    (6UL);

  /* Saturate: '<S157>/Saturation' */
  if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 >
      TrayectoriaObstaculos_P.Saturation_UpperSat) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
      TrayectoriaObstaculos_P.Saturation_UpperSat;
  } else if (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 <
             TrayectoriaObstaculos_P.Saturation_LowerSat) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
      TrayectoriaObstaculos_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S157>/Saturation' */

  /* Start for MATLABSystem: '<S157>/PWM Hacia delante Izq' */
  if (!(TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 <= 255.0)) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 = 255.0;
  }

  if (!(TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 >= 0.0)) {
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 = 0.0;
  }

  /* MATLABSystem: '<S157>/PWM Hacia delante Izq' */
  MW_PWM_SetDutyCycle(TrayectoriaObstaculos_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE,
                      TrayectoriaObstaculos_B.lookaheadEndPt_idx_1);

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  TrayectoriaObstaculos_B.lookaheadEndPt_idx_0 =
    TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* Trigonometry: '<S6>/Cos' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   */
  TrayectoriaObstaculos_B.lookaheadEndPt_idx_1 =
    TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
  TrayectoriaObstaculos_B.overshootDist =
    TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Trigonometry: '<S6>/Cos1' incorporates:
   *  DiscreteIntegrator: '<S6>/Discrete-Time Integrator'
   */
  TrayectoriaObstaculos_B.i =
    TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];

  /* Update for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S4>/Jacobiano directo'
   *  Product: '<S4>/Matrix Multiply'
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product1'
   *  Trigonometry: '<S6>/Cos'
   *  Trigonometry: '<S6>/Cos1'
   */
  TrayectoriaObstaculos_B.d =
    TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2];
  TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0] = cos
    (TrayectoriaObstaculos_B.lookaheadEndPt_idx_1) *
    TrayectoriaObstaculos_B.rtb_MatrixMultiply_c *
    TrayectoriaObstaculos_P.DiscreteTimeIntegrator_gainval +
    TrayectoriaObstaculos_B.lookaheadEndPt_idx_0;
  TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1] =
    TrayectoriaObstaculos_B.rtb_MatrixMultiply_c * sin(TrayectoriaObstaculos_B.i)
    * TrayectoriaObstaculos_P.DiscreteTimeIntegrator_gainval +
    TrayectoriaObstaculos_B.overshootDist;
  TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] =
    (TrayectoriaObstaculos_DW.UD_DSTATE[0] *
     TrayectoriaObstaculos_P.Jacobianodirecto_Value[1] +
     TrayectoriaObstaculos_DW.UD_DSTATE[1] *
     TrayectoriaObstaculos_P.Jacobianodirecto_Value[3]) *
    TrayectoriaObstaculos_P.DiscreteTimeIntegrator_gainval +
    TrayectoriaObstaculos_B.d;

  /* Update for UnitDelay: '<S161>/UD' incorporates:
   *  Sum: '<S161>/Diff'
   *
   * Block description for '<S161>/UD':
   *
   *  Store in Global RAM
   *
   * Block description for '<S161>/Diff':
   *
   *  Add in CPU
   */
  TrayectoriaObstaculos_DW.UD_DSTATE[0] =
    TrayectoriaObstaculos_B.rtb_TSamp_idx_0;
  TrayectoriaObstaculos_DW.UD_DSTATE[1] =
    TrayectoriaObstaculos_B.rtb_TSamp_idx_1;

  /* Update for DiscreteIntegrator: '<S86>/Filter' */
  TrayectoriaObstaculos_DW.Filter_DSTATE +=
    TrayectoriaObstaculos_P.Filter_gainval * TrayectoriaObstaculos_B.dist;

  /* Update for DiscreteIntegrator: '<S91>/Integrator' incorporates:
   *  Gain: '<S88>/Integral Gain'
   */
  TrayectoriaObstaculos_DW.Integrator_DSTATE += TrayectoriaObstaculos_P.PIDder_I
    * TrayectoriaObstaculos_B.lookaheadStartPt[1] *
    TrayectoriaObstaculos_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S134>/Filter' */
  TrayectoriaObstaculos_DW.Filter_DSTATE_n +=
    TrayectoriaObstaculos_P.Filter_gainval_j *
    TrayectoriaObstaculos_B.minDistance;

  /* Update for DiscreteIntegrator: '<S139>/Integrator' incorporates:
   *  Gain: '<S136>/Integral Gain'
   */
  TrayectoriaObstaculos_DW.Integrator_DSTATE_c +=
    TrayectoriaObstaculos_P.PIDizq_I * TrayectoriaObstaculos_B.lookaheadStartPt
    [0] * TrayectoriaObstaculos_P.Integrator_gainval_m;
}

/* Model step function for TID1 */
void TrayectoriaObstaculos_step1(void) /* Sample time: [0.05s, 0.0s] */
{
  /* S-Function (Sensores5_VL53L0X_VL53L1X_I2C): '<S7>/S-Function Builder2' */
  Sensores5_VL53L0X_VL53L1X_I2C_Outputs_wrapper_cgen
    (&TrayectoriaObstaculos_B.SFunctionBuilder2_o1[0],
     &TrayectoriaObstaculos_B.SFunctionBuilder2_o2[0],
     &TrayectoriaObstaculos_DW.SFunctionBuilder2_DSTATE);

  /* RateTransition: '<S7>/Rate Transition' incorporates:
   *  Gain: '<S7>/mm a cm'
   *  S-Function (Sensores5_VL53L0X_VL53L1X_I2C): '<S7>/S-Function Builder2'
   */
  TrayectoriaObstaculos_DW.RateTransition_Buffer0[0] =
    TrayectoriaObstaculos_P.mmacm_Gain *
    TrayectoriaObstaculos_B.SFunctionBuilder2_o1[0];
  TrayectoriaObstaculos_DW.RateTransition_Buffer0[1] =
    TrayectoriaObstaculos_P.mmacm_Gain *
    TrayectoriaObstaculos_B.SFunctionBuilder2_o1[1];
  TrayectoriaObstaculos_DW.RateTransition_Buffer0[2] =
    TrayectoriaObstaculos_P.mmacm_Gain *
    TrayectoriaObstaculos_B.SFunctionBuilder2_o1[2];

  /* Update for S-Function (Sensores5_VL53L0X_VL53L1X_I2C): '<S7>/S-Function Builder2' */

  /* S-Function "Sensores5_VL53L0X_VL53L1X_I2C_wrapper" Block: <S7>/S-Function Builder2 */
  Sensores5_VL53L0X_VL53L1X_I2C_Update_wrapper_cgen
    (&TrayectoriaObstaculos_B.SFunctionBuilder2_o1[0],
     &TrayectoriaObstaculos_B.SFunctionBuilder2_o2[0],
     &TrayectoriaObstaculos_DW.SFunctionBuilder2_DSTATE);
}

/* Model initialize function */
void TrayectoriaObstaculos_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int16_T i;

    /* Start for RateTransition: '<S7>/Rate Transition' */
    TrayectoriaObstaculos_B.RateTransition[0] =
      TrayectoriaObstaculos_P.RateTransition_InitialCondition;
    TrayectoriaObstaculos_B.RateTransition[1] =
      TrayectoriaObstaculos_P.RateTransition_InitialCondition;
    TrayectoriaObstaculos_B.RateTransition[2] =
      TrayectoriaObstaculos_P.RateTransition_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S6>/Discrete-Time Integrator' */
    TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[0] =
      TrayectoriaObstaculos_P.DiscreteTimeIntegrator_IC;
    TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[1] =
      TrayectoriaObstaculos_P.DiscreteTimeIntegrator_IC;
    TrayectoriaObstaculos_DW.DiscreteTimeIntegrator_DSTATE[2] =
      TrayectoriaObstaculos_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for UnitDelay: '<S161>/UD' incorporates:
     *  Sum: '<S161>/Diff'
     *
     * Block description for '<S161>/UD':
     *
     *  Store in Global RAM
     *
     * Block description for '<S161>/Diff':
     *
     *  Add in CPU
     */
    TrayectoriaObstaculos_DW.UD_DSTATE[0] =
      TrayectoriaObstaculos_P.DiscreteDerivative_ICPrevScaled;
    TrayectoriaObstaculos_DW.UD_DSTATE[1] =
      TrayectoriaObstaculos_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for RateTransition: '<S7>/Rate Transition' */
    TrayectoriaObstaculos_DW.RateTransition_Buffer0[0] =
      TrayectoriaObstaculos_P.RateTransition_InitialCondition;
    TrayectoriaObstaculos_DW.RateTransition_Buffer0[1] =
      TrayectoriaObstaculos_P.RateTransition_InitialCondition;
    TrayectoriaObstaculos_DW.RateTransition_Buffer0[2] =
      TrayectoriaObstaculos_P.RateTransition_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S86>/Filter' */
    TrayectoriaObstaculos_DW.Filter_DSTATE =
      TrayectoriaObstaculos_P.PIDder_InitialConditionForFilte;

    /* InitializeConditions for DiscreteIntegrator: '<S91>/Integrator' */
    TrayectoriaObstaculos_DW.Integrator_DSTATE =
      TrayectoriaObstaculos_P.PIDder_InitialConditionForInteg;

    /* InitializeConditions for DiscreteIntegrator: '<S134>/Filter' */
    TrayectoriaObstaculos_DW.Filter_DSTATE_n =
      TrayectoriaObstaculos_P.PIDizq_InitialConditionForFilte;

    /* InitializeConditions for DiscreteIntegrator: '<S139>/Integrator' */
    TrayectoriaObstaculos_DW.Integrator_DSTATE_c =
      TrayectoriaObstaculos_P.PIDizq_InitialConditionForInteg;

    /* InitializeConditions for S-Function (Sensores5_VL53L0X_VL53L1X_I2C): '<S7>/S-Function Builder2' */

    /* S-Function Block: <S7>/S-Function Builder2 */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          TrayectoriaObstaculos_DW.SFunctionBuilder2_DSTATE = initVector[0];
        }
      }
    }

    /* Start for MATLABSystem: '<S158>/Encoder' */
    TrayectoriaObstaculos_DW.obj_k.Index = 0U;
    TrayectoriaObstaculos_DW.obj_k.matlabCodegenIsDeleted = false;
    TrayectoriaObstaculos_DW.obj_k.SampleTime =
      TrayectoriaObstaculos_P.Encoder_SampleTime;
    TrayectoriaObstaculos_DW.obj_k.isInitialized = 1L;
    MW_EncoderSetup(2UL, 3UL, &TrayectoriaObstaculos_DW.obj_k.Index);
    TrayectoriaObstaculos_DW.obj_k.isSetupComplete = true;
    TrayectoriaObstaculos_DW.obj_k.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S158>/Encoder' */
    MW_EncoderReset(TrayectoriaObstaculos_DW.obj_k.Index);

    /* Start for MATLABSystem: '<S158>/Encoder1' */
    TrayectoriaObstaculos_DW.obj_h.Index = 0U;
    TrayectoriaObstaculos_DW.obj_h.matlabCodegenIsDeleted = false;
    TrayectoriaObstaculos_DW.obj_h.SampleTime =
      TrayectoriaObstaculos_P.Encoder1_SampleTime;
    TrayectoriaObstaculos_DW.obj_h.isInitialized = 1L;
    MW_EncoderSetup(19UL, 18UL, &TrayectoriaObstaculos_DW.obj_h.Index);
    TrayectoriaObstaculos_DW.obj_h.isSetupComplete = true;
    TrayectoriaObstaculos_DW.obj_h.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S158>/Encoder1' */
    MW_EncoderReset(TrayectoriaObstaculos_DW.obj_h.Index);

    /* Start for MATLABSystem: '<Root>/Pure Pursuit' */
    TrayectoriaObstaculos_DW.obj.DesiredLinearVelocity =
      TrayectoriaObstaculos_P.PurePursuit_DesiredLinearVeloci;
    TrayectoriaObstaculos_DW.obj.MaxAngularVelocity =
      TrayectoriaObstaculos_P.PurePursuit_MaxAngularVelocity;
    TrayectoriaObstaculos_DW.obj.LookaheadDistance =
      TrayectoriaObstaculos_P.PurePursuit_LookaheadDistance;
    TrayectoriaObstaculos_DW.obj.isInitialized = 1L;
    for (i = 0; i < 8; i++) {
      TrayectoriaObstaculos_DW.obj.WaypointsInternal[i] = (rtNaN);
    }

    /* InitializeConditions for MATLABSystem: '<Root>/Pure Pursuit' */
    TrayectoriaObstaculos_DW.obj.LookaheadPoint[0] = 0.0;
    TrayectoriaObstaculos_DW.obj.LookaheadPoint[1] = 0.0;
    TrayectoriaObstaculos_DW.obj.LastPose[0] = 0.0;
    TrayectoriaObstaculos_DW.obj.LastPose[1] = 0.0;
    TrayectoriaObstaculos_DW.obj.LastPose[2] = 0.0;
    TrayectoriaObstaculos_DW.obj.ProjectionPoint[0] = (rtNaN);
    TrayectoriaObstaculos_DW.obj.ProjectionPoint[1] = (rtNaN);
    TrayectoriaObstaculos_DW.obj.ProjectionLineIndex = 0.0;

    /* Start for MATLABSystem: '<S157>/Enable Der' */
    TrayectoriaObstaculos_DW.obj_i.matlabCodegenIsDeleted = false;
    TrayectoriaObstaculos_DW.obj_i.isInitialized = 1L;
    digitalIOSetup(12, 1);
    TrayectoriaObstaculos_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S157>/PWM Hacia Detrás Der' */
    TrayectoriaObstaculos_DW.obj_kf.matlabCodegenIsDeleted = false;
    TrayectoriaObstaculos_DW.obj_kf.isInitialized = 1L;
    TrayectoriaObstaculos_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL,
      0.0, 0.0);
    TrayectoriaObstaculos_DW.obj_kf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S157>/PWM Hacia delante Der' */
    TrayectoriaObstaculos_DW.obj_a.matlabCodegenIsDeleted = false;
    TrayectoriaObstaculos_DW.obj_a.isInitialized = 1L;
    TrayectoriaObstaculos_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL,
      0.0, 0.0);
    TrayectoriaObstaculos_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S157>/Enable Izq' */
    TrayectoriaObstaculos_DW.obj_n.matlabCodegenIsDeleted = false;
    TrayectoriaObstaculos_DW.obj_n.isInitialized = 1L;
    digitalIOSetup(13, 1);
    TrayectoriaObstaculos_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S157>/PWM Hacia Detrás Izq' */
    TrayectoriaObstaculos_DW.obj_o.matlabCodegenIsDeleted = false;
    TrayectoriaObstaculos_DW.obj_o.isInitialized = 1L;
    TrayectoriaObstaculos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7UL,
      0.0, 0.0);
    TrayectoriaObstaculos_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S157>/PWM Hacia delante Izq' */
    TrayectoriaObstaculos_DW.obj_io.matlabCodegenIsDeleted = false;
    TrayectoriaObstaculos_DW.obj_io.isInitialized = 1L;
    TrayectoriaObstaculos_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL,
      0.0, 0.0);
    TrayectoriaObstaculos_DW.obj_io.isSetupComplete = true;
  }
}

/* Model terminate function */
void TrayectoriaObstaculos_terminate(void)
{
  /* Terminate for MATLABSystem: '<S158>/Encoder' */
  if (!TrayectoriaObstaculos_DW.obj_k.matlabCodegenIsDeleted) {
    TrayectoriaObstaculos_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((TrayectoriaObstaculos_DW.obj_k.isInitialized == 1L) &&
        TrayectoriaObstaculos_DW.obj_k.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S158>/Encoder' */

  /* Terminate for MATLABSystem: '<S158>/Encoder1' */
  if (!TrayectoriaObstaculos_DW.obj_h.matlabCodegenIsDeleted) {
    TrayectoriaObstaculos_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((TrayectoriaObstaculos_DW.obj_h.isInitialized == 1L) &&
        TrayectoriaObstaculos_DW.obj_h.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S158>/Encoder1' */

  /* Terminate for MATLABSystem: '<S157>/Enable Der' */
  if (!TrayectoriaObstaculos_DW.obj_i.matlabCodegenIsDeleted) {
    TrayectoriaObstaculos_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S157>/Enable Der' */

  /* Terminate for MATLABSystem: '<S157>/PWM Hacia Detrás Der' */
  if (!TrayectoriaObstaculos_DW.obj_kf.matlabCodegenIsDeleted) {
    TrayectoriaObstaculos_DW.obj_kf.matlabCodegenIsDeleted = true;
    if ((TrayectoriaObstaculos_DW.obj_kf.isInitialized == 1L) &&
        TrayectoriaObstaculos_DW.obj_kf.isSetupComplete) {
      TrayectoriaObstaculos_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(4UL);
      MW_PWM_SetDutyCycle
        (TrayectoriaObstaculos_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      TrayectoriaObstaculos_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(4UL);
      MW_PWM_Close(TrayectoriaObstaculos_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/PWM Hacia Detrás Der' */

  /* Terminate for MATLABSystem: '<S157>/PWM Hacia delante Der' */
  if (!TrayectoriaObstaculos_DW.obj_a.matlabCodegenIsDeleted) {
    TrayectoriaObstaculos_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((TrayectoriaObstaculos_DW.obj_a.isInitialized == 1L) &&
        TrayectoriaObstaculos_DW.obj_a.isSetupComplete) {
      TrayectoriaObstaculos_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (TrayectoriaObstaculos_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      TrayectoriaObstaculos_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_Close(TrayectoriaObstaculos_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/PWM Hacia delante Der' */

  /* Terminate for MATLABSystem: '<S157>/Enable Izq' */
  if (!TrayectoriaObstaculos_DW.obj_n.matlabCodegenIsDeleted) {
    TrayectoriaObstaculos_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S157>/Enable Izq' */

  /* Terminate for MATLABSystem: '<S157>/PWM Hacia Detrás Izq' */
  if (!TrayectoriaObstaculos_DW.obj_o.matlabCodegenIsDeleted) {
    TrayectoriaObstaculos_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((TrayectoriaObstaculos_DW.obj_o.isInitialized == 1L) &&
        TrayectoriaObstaculos_DW.obj_o.isSetupComplete) {
      TrayectoriaObstaculos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(7UL);
      MW_PWM_SetDutyCycle
        (TrayectoriaObstaculos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      TrayectoriaObstaculos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(7UL);
      MW_PWM_Close(TrayectoriaObstaculos_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/PWM Hacia Detrás Izq' */

  /* Terminate for MATLABSystem: '<S157>/PWM Hacia delante Izq' */
  if (!TrayectoriaObstaculos_DW.obj_io.matlabCodegenIsDeleted) {
    TrayectoriaObstaculos_DW.obj_io.matlabCodegenIsDeleted = true;
    if ((TrayectoriaObstaculos_DW.obj_io.isInitialized == 1L) &&
        TrayectoriaObstaculos_DW.obj_io.isSetupComplete) {
      TrayectoriaObstaculos_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle
        (TrayectoriaObstaculos_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      TrayectoriaObstaculos_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(6UL);
      MW_PWM_Close(TrayectoriaObstaculos_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S157>/PWM Hacia delante Izq' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
