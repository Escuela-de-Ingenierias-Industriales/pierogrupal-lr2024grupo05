/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TrayectoriaObstaculos_data.c
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

/* Block parameters (default storage) */
P_TrayectoriaObstaculos_T TrayectoriaObstaculos_P = {
  /* Mask Parameter: PIDder_D
   * Referenced by: '<S85>/Derivative Gain'
   */
  143.175258111694,

  /* Mask Parameter: PIDizq_D
   * Referenced by: '<S133>/Derivative Gain'
   */
  157.454610744546,

  /* Mask Parameter: PIDder_I
   * Referenced by: '<S88>/Integral Gain'
   */
  1456.35617878903,

  /* Mask Parameter: PIDizq_I
   * Referenced by: '<S136>/Integral Gain'
   */
  1462.07060239984,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S161>/UD'
   */
  0.0,

  /* Mask Parameter: PIDder_InitialConditionForFilte
   * Referenced by: '<S86>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDizq_InitialConditionForFilte
   * Referenced by: '<S134>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDder_InitialConditionForInteg
   * Referenced by: '<S91>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDizq_InitialConditionForInteg
   * Referenced by: '<S139>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDder_LowerSaturationLimit
   * Referenced by: '<S98>/Saturation'
   */
  0.0,

  /* Mask Parameter: PIDizq_LowerSaturationLimit
   * Referenced by: '<S146>/Saturation'
   */
  0.0,

  /* Mask Parameter: PIDder_N
   * Referenced by: '<S94>/Filter Coefficient'
   */
  4.16368600736308,

  /* Mask Parameter: PIDizq_N
   * Referenced by: '<S142>/Filter Coefficient'
   */
  3.77770890951829,

  /* Mask Parameter: PIDder_P
   * Referenced by: '<S96>/Proportional Gain'
   */
  1289.91441452436,

  /* Mask Parameter: PIDizq_P
   * Referenced by: '<S144>/Proportional Gain'
   */
  1346.7159042262,

  /* Mask Parameter: PIDder_UpperSaturationLimit
   * Referenced by: '<S98>/Saturation'
   */
  255.0,

  /* Mask Parameter: PIDizq_UpperSaturationLimit
   * Referenced by: '<S146>/Saturation'
   */
  255.0,

  /* Expression: 0.3
   * Referenced by: '<Root>/Pure Pursuit'
   */
  0.3,

  /* Expression: pi/2
   * Referenced by: '<Root>/Pure Pursuit'
   */
  1.5707963267948966,

  /* Expression: 0.22
   * Referenced by: '<Root>/Pure Pursuit'
   */
  0.22,

  /* Expression: -1
   * Referenced by: '<S158>/Encoder'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S158>/Encoder1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S159>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S160>/Constant'
   */
  0.0,

  /* Expression: [0 0; 2.1 0; 2.1 4.2;7 4.2]
   * Referenced by: '<Root>/Constant'
   */
  { 0.0, 2.1, 2.1, 7.0, 0.0, 0.0, 4.2, 4.2 },

  /* Expression: [1 -d/2; 1 d/2]
   * Referenced by: '<S3>/Jacobiano inverso'
   */
  { 1.0, 1.0, -0.1115, 0.1115 },

  /* Expression: [1/2 1/2; -1/d 1/d]
   * Referenced by: '<S4>/Jacobiano directo'
   */
  { 0.5, -4.4843049327354256, 0.5, 4.4843049327354256 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S6>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S161>/TSamp'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S7>/Rate Transition'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S86>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S91>/Integrator'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<S157>/Saturation3'
   */
  1.0,

  /* Expression: -255
   * Referenced by: '<S157>/Saturation3'
   */
  -255.0,

  /* Expression: 255
   * Referenced by: '<S157>/Saturation2'
   */
  255.0,

  /* Expression: 1
   * Referenced by: '<S157>/Saturation2'
   */
  1.0,

  /* Computed Parameter: Filter_gainval_j
   * Referenced by: '<S134>/Filter'
   */
  0.01,

  /* Computed Parameter: Integrator_gainval_m
   * Referenced by: '<S139>/Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S157>/Saturation1'
   */
  0.0,

  /* Expression: -255
   * Referenced by: '<S157>/Saturation1'
   */
  -255.0,

  /* Expression: 255
   * Referenced by: '<S157>/Saturation'
   */
  255.0,

  /* Expression: 1
   * Referenced by: '<S157>/Saturation'
   */
  1.0,

  /* Expression: 1/10
   * Referenced by: '<S7>/mm a cm'
   */
  0.1,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S158>/Gain'
   */
  1235130528
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
