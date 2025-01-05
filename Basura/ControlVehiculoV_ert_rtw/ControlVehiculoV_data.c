/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlVehiculoV_data.c
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

/* Block parameters (default storage) */
P_ControlVehiculoV_T ControlVehiculoV_P = {
  /* Mask Parameter: PIDder_D
   * Referenced by: '<S34>/Derivative Gain'
   */
  143.175258111694,

  /* Mask Parameter: PIDizq_D
   * Referenced by: '<S82>/Derivative Gain'
   */
  157.454610744546,

  /* Mask Parameter: PIDder_I
   * Referenced by: '<S37>/Integral Gain'
   */
  1456.35617878903,

  /* Mask Parameter: PIDizq_I
   * Referenced by: '<S85>/Integral Gain'
   */
  1462.07060239984,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S110>/UD'
   */
  0.0,

  /* Mask Parameter: PIDder_InitialConditionForFilte
   * Referenced by: '<S35>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDizq_InitialConditionForFilte
   * Referenced by: '<S83>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDder_InitialConditionForInteg
   * Referenced by: '<S40>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDizq_InitialConditionForInteg
   * Referenced by: '<S88>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDder_LowerSaturationLimit
   * Referenced by: '<S47>/Saturation'
   */
  0.0,

  /* Mask Parameter: PIDizq_LowerSaturationLimit
   * Referenced by: '<S95>/Saturation'
   */
  0.0,

  /* Mask Parameter: PIDder_N
   * Referenced by: '<S43>/Filter Coefficient'
   */
  4.16368600736308,

  /* Mask Parameter: PIDizq_N
   * Referenced by: '<S91>/Filter Coefficient'
   */
  3.77770890951829,

  /* Mask Parameter: PIDder_P
   * Referenced by: '<S45>/Proportional Gain'
   */
  1289.91441452436,

  /* Mask Parameter: PIDizq_P
   * Referenced by: '<S93>/Proportional Gain'
   */
  1346.7159042262,

  /* Mask Parameter: PIDder_UpperSaturationLimit
   * Referenced by: '<S47>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDizq_UpperSaturationLimit
   * Referenced by: '<S95>/Saturation'
   */
  255.0,

  /* Expression: -1
   * Referenced by: '<S107>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S107>/Encoder1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S108>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S109>/Constant'
   */
  0.0,

  /* Expression: [1 -d/2; 1 d/2]
   * Referenced by: '<S1>/Jacobiano inverso'
   */
  { 1.0, 1.0, -0.1115, 0.1115 },

  /* Expression: [0.3 2*pi/10]
   * Referenced by: '<Root>/Consigna (v,w)'
   */
  { 0.3, 0.62831853071795862 },

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S110>/TSamp'
   */
  100.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S35>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S40>/Integrator'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<S106>/Saturation3'
   */
  1.0,

  /* Expression: -255
   * Referenced by: '<S106>/Saturation3'
   */
  -255.0,

  /* Expression: 255
   * Referenced by: '<S106>/Saturation2'
   */
  255.0,

  /* Expression: 1
   * Referenced by: '<S106>/Saturation2'
   */
  1.0,

  /* Computed Parameter: Filter_gainval_j
   * Referenced by: '<S83>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_m
   * Referenced by: '<S88>/Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S106>/Saturation1'
   */
  0.0,

  /* Expression: -255
   * Referenced by: '<S106>/Saturation1'
   */
  -255.0,

  /* Expression: 255
   * Referenced by: '<S106>/Saturation'
   */
  255.0,

  /* Expression: 1
   * Referenced by: '<S106>/Saturation'
   */
  1.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S107>/Gain'
   */
  1235130528
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
