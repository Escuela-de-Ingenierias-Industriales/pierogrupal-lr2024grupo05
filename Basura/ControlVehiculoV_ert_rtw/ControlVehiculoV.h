/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlVehiculoV.h
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

#ifndef RTW_HEADER_ControlVehiculoV_h_
#define RTW_HEADER_ControlVehiculoV_h_
#ifndef ControlVehiculoV_COMMON_INCLUDES_
#define ControlVehiculoV_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#endif                                 /* ControlVehiculoV_COMMON_INCLUDES_ */

#include "ControlVehiculoV_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T FilterCoefficient;            /* '<S43>/Filter Coefficient' */
} B_ControlVehiculoV_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_o_T obj; /* '<S107>/Encoder1' */
  codertarget_arduinobase_int_o_T obj_k;/* '<S107>/Encoder' */
  codertarget_arduinobase_block_T obj_n;/* '<S106>/Enable Izq' */
  codertarget_arduinobase_block_T obj_i;/* '<S106>/Enable Der' */
  codertarget_arduinobase_inter_T obj_io;/* '<S106>/PWM Hacia delante Izq' */
  codertarget_arduinobase_inter_T obj_a;/* '<S106>/PWM Hacia delante Der' */
  codertarget_arduinobase_inter_T obj_o;/* '<S106>/PWM Hacia Detrás Izq' */
  codertarget_arduinobase_inter_T obj_kf;/* '<S106>/PWM Hacia Detrás Der' */
  real_T UD_DSTATE[2];                 /* '<S110>/UD' */
  real_T Filter_DSTATE;                /* '<S35>/Filter' */
  real_T Integrator_DSTATE;            /* '<S40>/Integrator' */
  real_T Filter_DSTATE_n;              /* '<S83>/Filter' */
  real_T Integrator_DSTATE_c;          /* '<S88>/Integrator' */
} DW_ControlVehiculoV_T;

/* Parameters (default storage) */
struct P_ControlVehiculoV_T_ {
  real_T PIDder_D;                     /* Mask Parameter: PIDder_D
                                        * Referenced by: '<S34>/Derivative Gain'
                                        */
  real_T PIDizq_D;                     /* Mask Parameter: PIDizq_D
                                        * Referenced by: '<S82>/Derivative Gain'
                                        */
  real_T PIDder_I;                     /* Mask Parameter: PIDder_I
                                        * Referenced by: '<S37>/Integral Gain'
                                        */
  real_T PIDizq_I;                     /* Mask Parameter: PIDizq_I
                                        * Referenced by: '<S85>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S110>/UD'
                               */
  real_T PIDder_InitialConditionForFilte;
                              /* Mask Parameter: PIDder_InitialConditionForFilte
                               * Referenced by: '<S35>/Filter'
                               */
  real_T PIDizq_InitialConditionForFilte;
                              /* Mask Parameter: PIDizq_InitialConditionForFilte
                               * Referenced by: '<S83>/Filter'
                               */
  real_T PIDder_InitialConditionForInteg;
                              /* Mask Parameter: PIDder_InitialConditionForInteg
                               * Referenced by: '<S40>/Integrator'
                               */
  real_T PIDizq_InitialConditionForInteg;
                              /* Mask Parameter: PIDizq_InitialConditionForInteg
                               * Referenced by: '<S88>/Integrator'
                               */
  real_T PIDder_LowerSaturationLimit;
                                  /* Mask Parameter: PIDder_LowerSaturationLimit
                                   * Referenced by: '<S47>/Saturation'
                                   */
  real_T PIDizq_LowerSaturationLimit;
                                  /* Mask Parameter: PIDizq_LowerSaturationLimit
                                   * Referenced by: '<S95>/Saturation'
                                   */
  real_T PIDder_N;                     /* Mask Parameter: PIDder_N
                                        * Referenced by: '<S43>/Filter Coefficient'
                                        */
  real_T PIDizq_N;                     /* Mask Parameter: PIDizq_N
                                        * Referenced by: '<S91>/Filter Coefficient'
                                        */
  real_T PIDder_P;                     /* Mask Parameter: PIDder_P
                                        * Referenced by: '<S45>/Proportional Gain'
                                        */
  real_T PIDizq_P;                     /* Mask Parameter: PIDizq_P
                                        * Referenced by: '<S93>/Proportional Gain'
                                        */
  real_T PIDder_UpperSaturationLimit;
                                  /* Mask Parameter: PIDder_UpperSaturationLimit
                                   * Referenced by: '<S47>/Saturation'
                                   */
  real_T PIDizq_UpperSaturationLimit;
                                  /* Mask Parameter: PIDizq_UpperSaturationLimit
                                   * Referenced by: '<S95>/Saturation'
                                   */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S107>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S107>/Encoder1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S108>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S109>/Constant'
                                        */
  real_T Jacobianoinverso_Value[4];    /* Expression: [1 -d/2; 1 d/2]
                                        * Referenced by: '<S1>/Jacobiano inverso'
                                        */
  real_T Consignavw_Value[2];          /* Expression: [0.3 2*pi/10]
                                        * Referenced by: '<Root>/Consigna (v,w)'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S110>/TSamp'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S35>/Filter'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S40>/Integrator'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S106>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -255
                                        * Referenced by: '<S106>/Saturation3'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S106>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S106>/Saturation2'
                                        */
  real_T Filter_gainval_j;             /* Computed Parameter: Filter_gainval_j
                                        * Referenced by: '<S83>/Filter'
                                        */
  real_T Integrator_gainval_m;       /* Computed Parameter: Integrator_gainval_m
                                      * Referenced by: '<S88>/Integrator'
                                      */
  real_T Saturation1_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S106>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -255
                                        * Referenced by: '<S106>/Saturation1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<S106>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 1
                                        * Referenced by: '<S106>/Saturation'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S107>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ControlVehiculoV_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_ControlVehiculoV_T ControlVehiculoV_P;

/* Block signals (default storage) */
extern B_ControlVehiculoV_T ControlVehiculoV_B;

/* Block states (default storage) */
extern DW_ControlVehiculoV_T ControlVehiculoV_DW;

/* Model entry point functions */
extern void ControlVehiculoV_initialize(void);
extern void ControlVehiculoV_step(void);
extern void ControlVehiculoV_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ControlVehiculoV_T *const ControlVehiculoV_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Jacobiano directo' : Unused code path elimination
 * Block '<S2>/Matrix Multiply' : Unused code path elimination
 * Block '<S3>/Display' : Unused code path elimination
 * Block '<S3>/Display2' : Unused code path elimination
 * Block '<S106>/Display' : Unused code path elimination
 * Block '<S106>/Display1' : Unused code path elimination
 * Block '<S106>/Display2' : Unused code path elimination
 * Block '<S106>/Display3' : Unused code path elimination
 * Block '<S106>/Display4' : Unused code path elimination
 * Block '<S106>/Display5' : Unused code path elimination
 * Block '<S110>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Cos' : Unused code path elimination
 * Block '<S4>/Cos1' : Unused code path elimination
 * Block '<S4>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S4>/Product' : Unused code path elimination
 * Block '<S4>/Product1' : Unused code path elimination
 * Block '<Root>/v,w alcanzada ' : Unused code path elimination
 * Block '<Root>/v1, v2 alcanzado' : Unused code path elimination
 * Block '<Root>/v1,v2 consigna' : Unused code path elimination
 * Block '<Root>/x,y,theta' : Unused code path elimination
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
 * '<Root>' : 'ControlVehiculoV'
 * '<S1>'   : 'ControlVehiculoV/Subsystem Reference'
 * '<S2>'   : 'ControlVehiculoV/Subsystem Reference1'
 * '<S3>'   : 'ControlVehiculoV/Subsystem Reference2'
 * '<S4>'   : 'ControlVehiculoV/Subsystem Reference3'
 * '<S5>'   : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference'
 * '<S6>'   : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference1'
 * '<S7>'   : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der'
 * '<S8>'   : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq'
 * '<S9>'   : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Anti-windup'
 * '<S10>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/D Gain'
 * '<S11>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Filter'
 * '<S12>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Filter ICs'
 * '<S13>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/I Gain'
 * '<S14>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Ideal P Gain'
 * '<S15>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Ideal P Gain Fdbk'
 * '<S16>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Integrator'
 * '<S17>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Integrator ICs'
 * '<S18>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/N Copy'
 * '<S19>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/N Gain'
 * '<S20>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/P Copy'
 * '<S21>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Parallel P Gain'
 * '<S22>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Reset Signal'
 * '<S23>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Saturation'
 * '<S24>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Saturation Fdbk'
 * '<S25>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Sum'
 * '<S26>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Sum Fdbk'
 * '<S27>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Tracking Mode'
 * '<S28>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Tracking Mode Sum'
 * '<S29>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Tsamp - Integral'
 * '<S30>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Tsamp - Ngain'
 * '<S31>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/postSat Signal'
 * '<S32>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/preSat Signal'
 * '<S33>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Anti-windup/Passthrough'
 * '<S34>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/D Gain/Internal Parameters'
 * '<S35>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Filter/Disc. Forward Euler Filter'
 * '<S36>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Filter ICs/Internal IC - Filter'
 * '<S37>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/I Gain/Internal Parameters'
 * '<S38>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Ideal P Gain/Passthrough'
 * '<S39>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Integrator/Discrete'
 * '<S41>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Integrator ICs/Internal IC'
 * '<S42>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/N Copy/Disabled'
 * '<S43>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/N Gain/Internal Parameters'
 * '<S44>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/P Copy/Disabled'
 * '<S45>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Parallel P Gain/Internal Parameters'
 * '<S46>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Reset Signal/Disabled'
 * '<S47>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Saturation/Enabled'
 * '<S48>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Saturation Fdbk/Disabled'
 * '<S49>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Sum/Sum_PID'
 * '<S50>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Sum Fdbk/Disabled'
 * '<S51>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Tracking Mode/Disabled'
 * '<S52>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Tsamp - Integral/TsSignalSpecification'
 * '<S54>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/postSat Signal/Forward_Path'
 * '<S56>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID der/preSat Signal/Forward_Path'
 * '<S57>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Anti-windup'
 * '<S58>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/D Gain'
 * '<S59>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Filter'
 * '<S60>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Filter ICs'
 * '<S61>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/I Gain'
 * '<S62>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Ideal P Gain'
 * '<S63>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Ideal P Gain Fdbk'
 * '<S64>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Integrator'
 * '<S65>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Integrator ICs'
 * '<S66>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/N Copy'
 * '<S67>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/N Gain'
 * '<S68>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/P Copy'
 * '<S69>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Parallel P Gain'
 * '<S70>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Reset Signal'
 * '<S71>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Saturation'
 * '<S72>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Saturation Fdbk'
 * '<S73>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Sum'
 * '<S74>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Sum Fdbk'
 * '<S75>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Tracking Mode'
 * '<S76>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Tracking Mode Sum'
 * '<S77>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Tsamp - Integral'
 * '<S78>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Tsamp - Ngain'
 * '<S79>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/postSat Signal'
 * '<S80>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/preSat Signal'
 * '<S81>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Anti-windup/Passthrough'
 * '<S82>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/D Gain/Internal Parameters'
 * '<S83>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Filter/Disc. Forward Euler Filter'
 * '<S84>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Filter ICs/Internal IC - Filter'
 * '<S85>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/I Gain/Internal Parameters'
 * '<S86>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Ideal P Gain/Passthrough'
 * '<S87>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Ideal P Gain Fdbk/Disabled'
 * '<S88>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Integrator/Discrete'
 * '<S89>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Integrator ICs/Internal IC'
 * '<S90>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/N Copy/Disabled'
 * '<S91>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/N Gain/Internal Parameters'
 * '<S92>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/P Copy/Disabled'
 * '<S93>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Parallel P Gain/Internal Parameters'
 * '<S94>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Reset Signal/Disabled'
 * '<S95>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Saturation/Enabled'
 * '<S96>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Saturation Fdbk/Disabled'
 * '<S97>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Sum/Sum_PID'
 * '<S98>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Sum Fdbk/Disabled'
 * '<S99>'  : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Tracking Mode/Disabled'
 * '<S100>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Tsamp - Integral/TsSignalSpecification'
 * '<S102>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/Tsamp - Ngain/Passthrough'
 * '<S103>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/postSat Signal/Forward_Path'
 * '<S104>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference/PID izq/preSat Signal/Forward_Path'
 * '<S105>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1'
 * '<S106>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1/Subsystem Reference'
 * '<S107>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1/Subsystem Reference1'
 * '<S108>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1/Subsystem Reference/Compare To Zero'
 * '<S109>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1/Subsystem Reference/Compare To Zero1'
 * '<S110>' : 'ControlVehiculoV/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1/Subsystem Reference1/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_ControlVehiculoV_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
