/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlVehiculoV.c
 *
 * Code generated for Simulink model 'ControlVehiculoV'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Nov 10 19:03:52 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ControlVehiculoV.h"
#include <math.h>
#include "rtwtypes.h"
#include "ControlVehiculoV_private.h"

/* Block signals (default storage) */
B_ControlVehiculoV_T ControlVehiculoV_B;

/* Block states (default storage) */
DW_ControlVehiculoV_T ControlVehiculoV_DW;

/* Real-time model */
static RT_MODEL_ControlVehiculoV_T ControlVehiculoV_M_;
RT_MODEL_ControlVehiculoV_T *const ControlVehiculoV_M = &ControlVehiculoV_M_;

/* Model step function */
void ControlVehiculoV_step(void)
{
  real_T rtb_Filter_n;
  real_T rtb_Saturation_o;
  real_T rtb_Sum_idx_0;
  real_T rtb_Sum_idx_1;
  real_T rtb_TSamp_idx_0;
  real_T rtb_TSamp_idx_1;
  real_T u0;
  int32_T rtb_Encoder1_0;
  int32_T rtb_Encoder_0;

  /* MATLABSystem: '<S107>/Encoder' */
  if (ControlVehiculoV_DW.obj_k.SampleTime !=
      ControlVehiculoV_P.Encoder_SampleTime) {
    ControlVehiculoV_DW.obj_k.SampleTime = ControlVehiculoV_P.Encoder_SampleTime;
  }

  if (ControlVehiculoV_DW.obj_k.TunablePropsChanged) {
    ControlVehiculoV_DW.obj_k.TunablePropsChanged = false;
  }

  MW_EncoderRead(ControlVehiculoV_DW.obj_k.Index, &rtb_Encoder_0);

  /* MATLABSystem: '<S107>/Encoder1' */
  if (ControlVehiculoV_DW.obj.SampleTime !=
      ControlVehiculoV_P.Encoder1_SampleTime) {
    ControlVehiculoV_DW.obj.SampleTime = ControlVehiculoV_P.Encoder1_SampleTime;
  }

  if (ControlVehiculoV_DW.obj.TunablePropsChanged) {
    ControlVehiculoV_DW.obj.TunablePropsChanged = false;
  }

  MW_EncoderRead(ControlVehiculoV_DW.obj.Index, &rtb_Encoder1_0);

  /* Gain: '<S107>/Gain' */
  rtb_TSamp_idx_1 = (real_T)ControlVehiculoV_P.Gain_Gain *
    1.1368683772161603E-13;

  /* SampleTimeMath: '<S110>/TSamp' incorporates:
   *  Gain: '<S107>/Gain'
   *  MATLABSystem: '<S107>/Encoder'
   *  MATLABSystem: '<S107>/Encoder1'
   *
   * About '<S110>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_TSamp_idx_0 = rtb_TSamp_idx_1 * (real_T)rtb_Encoder_0 *
    ControlVehiculoV_P.TSamp_WtEt;
  rtb_TSamp_idx_1 = rtb_TSamp_idx_1 * (real_T)rtb_Encoder1_0 *
    ControlVehiculoV_P.TSamp_WtEt;

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<Root>/Consigna (v,w)'
   *  Constant: '<S1>/Jacobiano inverso'
   *  Product: '<S1>/Matrix Multiply'
   *  Sum: '<S110>/Diff'
   *  UnitDelay: '<S110>/UD'
   *
   * Block description for '<S110>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S110>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Sum_idx_0 = (ControlVehiculoV_P.Jacobianoinverso_Value[0] *
                   ControlVehiculoV_P.Consignavw_Value[0] +
                   ControlVehiculoV_P.Consignavw_Value[1] *
                   ControlVehiculoV_P.Jacobianoinverso_Value[2]) -
    (rtb_TSamp_idx_0 - ControlVehiculoV_DW.UD_DSTATE[0]);
  rtb_Sum_idx_1 = (ControlVehiculoV_P.Consignavw_Value[0] *
                   ControlVehiculoV_P.Jacobianoinverso_Value[1] +
                   ControlVehiculoV_P.Consignavw_Value[1] *
                   ControlVehiculoV_P.Jacobianoinverso_Value[3]) -
    (rtb_TSamp_idx_1 - ControlVehiculoV_DW.UD_DSTATE[1]);

  /* Gain: '<S43>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S35>/Filter'
   *  Gain: '<S34>/Derivative Gain'
   *  Sum: '<S35>/SumD'
   */
  ControlVehiculoV_B.FilterCoefficient = (ControlVehiculoV_P.PIDder_D *
    rtb_Sum_idx_1 - ControlVehiculoV_DW.Filter_DSTATE) *
    ControlVehiculoV_P.PIDder_N;

  /* Sum: '<S49>/Sum' incorporates:
   *  DiscreteIntegrator: '<S40>/Integrator'
   *  Gain: '<S45>/Proportional Gain'
   */
  rtb_Filter_n = (ControlVehiculoV_P.PIDder_P * rtb_Sum_idx_1 +
                  ControlVehiculoV_DW.Integrator_DSTATE) +
    ControlVehiculoV_B.FilterCoefficient;

  /* Saturate: '<S47>/Saturation' */
  if (rtb_Filter_n > ControlVehiculoV_P.PIDder_UpperSaturationLimit) {
    rtb_Filter_n = ControlVehiculoV_P.PIDder_UpperSaturationLimit;
  } else if (rtb_Filter_n < ControlVehiculoV_P.PIDder_LowerSaturationLimit) {
    rtb_Filter_n = ControlVehiculoV_P.PIDder_LowerSaturationLimit;
  }

  /* End of Saturate: '<S47>/Saturation' */

  /* MATLABSystem: '<S106>/Enable Der' incorporates:
   *  Constant: '<S109>/Constant'
   *  RelationalOperator: '<S109>/Compare'
   */
  writeDigitalPin(12, (uint8_T)(rtb_Filter_n !=
    ControlVehiculoV_P.Constant_Value_d));

  /* MATLABSystem: '<S106>/PWM Hacia Detrás Der' */
  ControlVehiculoV_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(4UL);

  /* Saturate: '<S106>/Saturation3' */
  if (rtb_Filter_n > ControlVehiculoV_P.Saturation3_UpperSat) {
    u0 = ControlVehiculoV_P.Saturation3_UpperSat;
  } else if (rtb_Filter_n < ControlVehiculoV_P.Saturation3_LowerSat) {
    u0 = ControlVehiculoV_P.Saturation3_LowerSat;
  } else {
    u0 = rtb_Filter_n;
  }

  /* Abs: '<S106>/Abs1' incorporates:
   *  Saturate: '<S106>/Saturation3'
   */
  u0 = fabs(u0);

  /* Start for MATLABSystem: '<S106>/PWM Hacia Detrás Der' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  /* MATLABSystem: '<S106>/PWM Hacia Detrás Der' */
  MW_PWM_SetDutyCycle(ControlVehiculoV_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE, u0);

  /* MATLABSystem: '<S106>/PWM Hacia delante Der' */
  ControlVehiculoV_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Saturate: '<S106>/Saturation2' */
  if (rtb_Filter_n > ControlVehiculoV_P.Saturation2_UpperSat) {
    rtb_Filter_n = ControlVehiculoV_P.Saturation2_UpperSat;
  } else if (rtb_Filter_n < ControlVehiculoV_P.Saturation2_LowerSat) {
    rtb_Filter_n = ControlVehiculoV_P.Saturation2_LowerSat;
  }

  /* End of Saturate: '<S106>/Saturation2' */

  /* Start for MATLABSystem: '<S106>/PWM Hacia delante Der' */
  if (!(rtb_Filter_n <= 255.0)) {
    rtb_Filter_n = 255.0;
  }

  if (!(rtb_Filter_n >= 0.0)) {
    rtb_Filter_n = 0.0;
  }

  /* MATLABSystem: '<S106>/PWM Hacia delante Der' */
  MW_PWM_SetDutyCycle(ControlVehiculoV_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_Filter_n);

  /* Gain: '<S91>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S83>/Filter'
   *  Gain: '<S82>/Derivative Gain'
   *  Sum: '<S83>/SumD'
   */
  rtb_Filter_n = (ControlVehiculoV_P.PIDizq_D * rtb_Sum_idx_0 -
                  ControlVehiculoV_DW.Filter_DSTATE_n) *
    ControlVehiculoV_P.PIDizq_N;

  /* Sum: '<S97>/Sum' incorporates:
   *  DiscreteIntegrator: '<S88>/Integrator'
   *  Gain: '<S93>/Proportional Gain'
   */
  rtb_Saturation_o = (ControlVehiculoV_P.PIDizq_P * rtb_Sum_idx_0 +
                      ControlVehiculoV_DW.Integrator_DSTATE_c) + rtb_Filter_n;

  /* Saturate: '<S95>/Saturation' */
  if (rtb_Saturation_o > ControlVehiculoV_P.PIDizq_UpperSaturationLimit) {
    rtb_Saturation_o = ControlVehiculoV_P.PIDizq_UpperSaturationLimit;
  } else if (rtb_Saturation_o < ControlVehiculoV_P.PIDizq_LowerSaturationLimit)
  {
    rtb_Saturation_o = ControlVehiculoV_P.PIDizq_LowerSaturationLimit;
  }

  /* End of Saturate: '<S95>/Saturation' */

  /* MATLABSystem: '<S106>/Enable Izq' incorporates:
   *  Constant: '<S108>/Constant'
   *  RelationalOperator: '<S108>/Compare'
   */
  writeDigitalPin(13, (uint8_T)(rtb_Saturation_o !=
    ControlVehiculoV_P.Constant_Value));

  /* MATLABSystem: '<S106>/PWM Hacia Detrás Izq' */
  ControlVehiculoV_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(7UL);

  /* Saturate: '<S106>/Saturation1' */
  if (rtb_Saturation_o > ControlVehiculoV_P.Saturation1_UpperSat) {
    u0 = ControlVehiculoV_P.Saturation1_UpperSat;
  } else if (rtb_Saturation_o < ControlVehiculoV_P.Saturation1_LowerSat) {
    u0 = ControlVehiculoV_P.Saturation1_LowerSat;
  } else {
    u0 = rtb_Saturation_o;
  }

  /* Abs: '<S106>/Abs' incorporates:
   *  Saturate: '<S106>/Saturation1'
   */
  u0 = fabs(u0);

  /* Start for MATLABSystem: '<S106>/PWM Hacia Detrás Izq' */
  if (!(u0 <= 255.0)) {
    u0 = 255.0;
  }

  /* MATLABSystem: '<S106>/PWM Hacia Detrás Izq' */
  MW_PWM_SetDutyCycle(ControlVehiculoV_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE, u0);

  /* MATLABSystem: '<S106>/PWM Hacia delante Izq' */
  ControlVehiculoV_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Saturate: '<S106>/Saturation' */
  if (rtb_Saturation_o > ControlVehiculoV_P.Saturation_UpperSat) {
    rtb_Saturation_o = ControlVehiculoV_P.Saturation_UpperSat;
  } else if (rtb_Saturation_o < ControlVehiculoV_P.Saturation_LowerSat) {
    rtb_Saturation_o = ControlVehiculoV_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<S106>/Saturation' */

  /* Start for MATLABSystem: '<S106>/PWM Hacia delante Izq' */
  if (!(rtb_Saturation_o <= 255.0)) {
    rtb_Saturation_o = 255.0;
  }

  if (!(rtb_Saturation_o >= 0.0)) {
    rtb_Saturation_o = 0.0;
  }

  /* MATLABSystem: '<S106>/PWM Hacia delante Izq' */
  MW_PWM_SetDutyCycle(ControlVehiculoV_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_Saturation_o);

  /* Update for UnitDelay: '<S110>/UD'
   *
   * Block description for '<S110>/UD':
   *
   *  Store in Global RAM
   */
  ControlVehiculoV_DW.UD_DSTATE[0] = rtb_TSamp_idx_0;
  ControlVehiculoV_DW.UD_DSTATE[1] = rtb_TSamp_idx_1;

  /* Update for DiscreteIntegrator: '<S35>/Filter' */
  ControlVehiculoV_DW.Filter_DSTATE += ControlVehiculoV_P.Filter_gainval *
    ControlVehiculoV_B.FilterCoefficient;

  /* Update for DiscreteIntegrator: '<S40>/Integrator' incorporates:
   *  Gain: '<S37>/Integral Gain'
   */
  ControlVehiculoV_DW.Integrator_DSTATE += ControlVehiculoV_P.PIDder_I *
    rtb_Sum_idx_1 * ControlVehiculoV_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S83>/Filter' */
  ControlVehiculoV_DW.Filter_DSTATE_n += ControlVehiculoV_P.Filter_gainval_j *
    rtb_Filter_n;

  /* Update for DiscreteIntegrator: '<S88>/Integrator' incorporates:
   *  Gain: '<S85>/Integral Gain'
   */
  ControlVehiculoV_DW.Integrator_DSTATE_c += ControlVehiculoV_P.PIDizq_I *
    rtb_Sum_idx_0 * ControlVehiculoV_P.Integrator_gainval_m;
}

/* Model initialize function */
void ControlVehiculoV_initialize(void)
{
  /* InitializeConditions for UnitDelay: '<S110>/UD'
   *
   * Block description for '<S110>/UD':
   *
   *  Store in Global RAM
   */
  ControlVehiculoV_DW.UD_DSTATE[0] =
    ControlVehiculoV_P.DiscreteDerivative_ICPrevScaled;
  ControlVehiculoV_DW.UD_DSTATE[1] =
    ControlVehiculoV_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S35>/Filter' */
  ControlVehiculoV_DW.Filter_DSTATE =
    ControlVehiculoV_P.PIDder_InitialConditionForFilte;

  /* InitializeConditions for DiscreteIntegrator: '<S40>/Integrator' */
  ControlVehiculoV_DW.Integrator_DSTATE =
    ControlVehiculoV_P.PIDder_InitialConditionForInteg;

  /* InitializeConditions for DiscreteIntegrator: '<S83>/Filter' */
  ControlVehiculoV_DW.Filter_DSTATE_n =
    ControlVehiculoV_P.PIDizq_InitialConditionForFilte;

  /* InitializeConditions for DiscreteIntegrator: '<S88>/Integrator' */
  ControlVehiculoV_DW.Integrator_DSTATE_c =
    ControlVehiculoV_P.PIDizq_InitialConditionForInteg;

  /* Start for MATLABSystem: '<S107>/Encoder' */
  ControlVehiculoV_DW.obj_k.Index = 0U;
  ControlVehiculoV_DW.obj_k.matlabCodegenIsDeleted = false;
  ControlVehiculoV_DW.obj_k.SampleTime = ControlVehiculoV_P.Encoder_SampleTime;
  ControlVehiculoV_DW.obj_k.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &ControlVehiculoV_DW.obj_k.Index);
  ControlVehiculoV_DW.obj_k.isSetupComplete = true;
  ControlVehiculoV_DW.obj_k.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S107>/Encoder' */
  MW_EncoderReset(ControlVehiculoV_DW.obj_k.Index);

  /* Start for MATLABSystem: '<S107>/Encoder1' */
  ControlVehiculoV_DW.obj.Index = 0U;
  ControlVehiculoV_DW.obj.matlabCodegenIsDeleted = false;
  ControlVehiculoV_DW.obj.SampleTime = ControlVehiculoV_P.Encoder1_SampleTime;
  ControlVehiculoV_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(19UL, 18UL, &ControlVehiculoV_DW.obj.Index);
  ControlVehiculoV_DW.obj.isSetupComplete = true;
  ControlVehiculoV_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<S107>/Encoder1' */
  MW_EncoderReset(ControlVehiculoV_DW.obj.Index);

  /* Start for MATLABSystem: '<S106>/Enable Der' */
  ControlVehiculoV_DW.obj_i.matlabCodegenIsDeleted = false;
  ControlVehiculoV_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(12, 1);
  ControlVehiculoV_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/PWM Hacia Detrás Der' */
  ControlVehiculoV_DW.obj_kf.matlabCodegenIsDeleted = false;
  ControlVehiculoV_DW.obj_kf.isInitialized = 1L;
  ControlVehiculoV_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(4UL, 0.0,
    0.0);
  ControlVehiculoV_DW.obj_kf.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/PWM Hacia delante Der' */
  ControlVehiculoV_DW.obj_a.matlabCodegenIsDeleted = false;
  ControlVehiculoV_DW.obj_a.isInitialized = 1L;
  ControlVehiculoV_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0,
    0.0);
  ControlVehiculoV_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/Enable Izq' */
  ControlVehiculoV_DW.obj_n.matlabCodegenIsDeleted = false;
  ControlVehiculoV_DW.obj_n.isInitialized = 1L;
  digitalIOSetup(13, 1);
  ControlVehiculoV_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/PWM Hacia Detrás Izq' */
  ControlVehiculoV_DW.obj_o.matlabCodegenIsDeleted = false;
  ControlVehiculoV_DW.obj_o.isInitialized = 1L;
  ControlVehiculoV_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(7UL, 0.0,
    0.0);
  ControlVehiculoV_DW.obj_o.isSetupComplete = true;

  /* Start for MATLABSystem: '<S106>/PWM Hacia delante Izq' */
  ControlVehiculoV_DW.obj_io.matlabCodegenIsDeleted = false;
  ControlVehiculoV_DW.obj_io.isInitialized = 1L;
  ControlVehiculoV_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0,
    0.0);
  ControlVehiculoV_DW.obj_io.isSetupComplete = true;
}

/* Model terminate function */
void ControlVehiculoV_terminate(void)
{
  /* Terminate for MATLABSystem: '<S107>/Encoder' */
  if (!ControlVehiculoV_DW.obj_k.matlabCodegenIsDeleted) {
    ControlVehiculoV_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((ControlVehiculoV_DW.obj_k.isInitialized == 1L) &&
        ControlVehiculoV_DW.obj_k.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S107>/Encoder' */

  /* Terminate for MATLABSystem: '<S107>/Encoder1' */
  if (!ControlVehiculoV_DW.obj.matlabCodegenIsDeleted) {
    ControlVehiculoV_DW.obj.matlabCodegenIsDeleted = true;
    if ((ControlVehiculoV_DW.obj.isInitialized == 1L) &&
        ControlVehiculoV_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<S107>/Encoder1' */

  /* Terminate for MATLABSystem: '<S106>/Enable Der' */
  if (!ControlVehiculoV_DW.obj_i.matlabCodegenIsDeleted) {
    ControlVehiculoV_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S106>/Enable Der' */

  /* Terminate for MATLABSystem: '<S106>/PWM Hacia Detrás Der' */
  if (!ControlVehiculoV_DW.obj_kf.matlabCodegenIsDeleted) {
    ControlVehiculoV_DW.obj_kf.matlabCodegenIsDeleted = true;
    if ((ControlVehiculoV_DW.obj_kf.isInitialized == 1L) &&
        ControlVehiculoV_DW.obj_kf.isSetupComplete) {
      ControlVehiculoV_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (4UL);
      MW_PWM_SetDutyCycle(ControlVehiculoV_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ControlVehiculoV_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (4UL);
      MW_PWM_Close(ControlVehiculoV_DW.obj_kf.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/PWM Hacia Detrás Der' */

  /* Terminate for MATLABSystem: '<S106>/PWM Hacia delante Der' */
  if (!ControlVehiculoV_DW.obj_a.matlabCodegenIsDeleted) {
    ControlVehiculoV_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((ControlVehiculoV_DW.obj_a.isInitialized == 1L) &&
        ControlVehiculoV_DW.obj_a.isSetupComplete) {
      ControlVehiculoV_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (5UL);
      MW_PWM_SetDutyCycle(ControlVehiculoV_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ControlVehiculoV_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (5UL);
      MW_PWM_Close(ControlVehiculoV_DW.obj_a.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/PWM Hacia delante Der' */

  /* Terminate for MATLABSystem: '<S106>/Enable Izq' */
  if (!ControlVehiculoV_DW.obj_n.matlabCodegenIsDeleted) {
    ControlVehiculoV_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S106>/Enable Izq' */

  /* Terminate for MATLABSystem: '<S106>/PWM Hacia Detrás Izq' */
  if (!ControlVehiculoV_DW.obj_o.matlabCodegenIsDeleted) {
    ControlVehiculoV_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((ControlVehiculoV_DW.obj_o.isInitialized == 1L) &&
        ControlVehiculoV_DW.obj_o.isSetupComplete) {
      ControlVehiculoV_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (7UL);
      MW_PWM_SetDutyCycle(ControlVehiculoV_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ControlVehiculoV_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (7UL);
      MW_PWM_Close(ControlVehiculoV_DW.obj_o.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/PWM Hacia Detrás Izq' */

  /* Terminate for MATLABSystem: '<S106>/PWM Hacia delante Izq' */
  if (!ControlVehiculoV_DW.obj_io.matlabCodegenIsDeleted) {
    ControlVehiculoV_DW.obj_io.matlabCodegenIsDeleted = true;
    if ((ControlVehiculoV_DW.obj_io.isInitialized == 1L) &&
        ControlVehiculoV_DW.obj_io.isSetupComplete) {
      ControlVehiculoV_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (6UL);
      MW_PWM_SetDutyCycle(ControlVehiculoV_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      ControlVehiculoV_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle
        (6UL);
      MW_PWM_Close(ControlVehiculoV_DW.obj_io.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/PWM Hacia delante Izq' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
