/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TrayectoriaObstaculos.h
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

#ifndef RTW_HEADER_TrayectoriaObstaculos_h_
#define RTW_HEADER_TrayectoriaObstaculos_h_
#ifndef TrayectoriaObstaculos_COMMON_INCLUDES_
#define TrayectoriaObstaculos_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Sensores5_VL53L0X_VL53L1X_I2C_cgen_wrapper.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#include "MW_ArduinoEncoder.h"
#endif                              /* TrayectoriaObstaculos_COMMON_INCLUDES_ */

#include "TrayectoriaObstaculos_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T RateTransition[3];            /* '<S7>/Rate Transition' */
  real_T SFunctionBuilder2_o1[3];      /* '<S7>/S-Function Builder2' */
  real_T SFunctionBuilder2_o2[3];      /* '<S7>/S-Function Builder2' */
  real_T lookaheadStartPt[2];
  real_T dv[2];
  real_T lookaheadStartPt_m[2];
  real_T dv1[2];
  real_T refPt[2];
  boolean_T b[8];
  real_T c;                            /* '<Root>/Chart' */
  real_T V;                            /* '<Root>/Chart' */
  real_T W;                            /* '<Root>/Chart' */
  real_T minDistance;
  real_T dist;
  real_T i;
  real_T overshootDist;
  real_T d;
  real_T rtb_TSamp_idx_0;
  real_T rtb_TSamp_idx_1;
  real_T lookaheadEndPt_idx_0;
  real_T lookaheadEndPt_idx_1;
  real_T rtb_MatrixMultiply_c;
  real_T alpha;
  real_T v12;
  real_T v12_k;
} B_TrayectoriaObstaculos_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  nav_slalgs_internal_PurePursu_T obj; /* '<Root>/Pure Pursuit' */
  codertarget_arduinobase_int_c_T obj_h;/* '<S158>/Encoder1' */
  codertarget_arduinobase_int_c_T obj_k;/* '<S158>/Encoder' */
  codertarget_arduinobase_block_T obj_n;/* '<S157>/Enable Izq' */
  codertarget_arduinobase_block_T obj_i;/* '<S157>/Enable Der' */
  codertarget_arduinobase_inter_T obj_io;/* '<S157>/PWM Hacia delante Izq' */
  codertarget_arduinobase_inter_T obj_a;/* '<S157>/PWM Hacia delante Der' */
  codertarget_arduinobase_inter_T obj_o;/* '<S157>/PWM Hacia Detrás Izq' */
  codertarget_arduinobase_inter_T obj_kf;/* '<S157>/PWM Hacia Detrás Der' */
  real_T DiscreteTimeIntegrator_DSTATE[3];/* '<S6>/Discrete-Time Integrator' */
  real_T UD_DSTATE[2];                 /* '<S161>/UD' */
  real_T Filter_DSTATE;                /* '<S86>/Filter' */
  real_T Integrator_DSTATE;            /* '<S91>/Integrator' */
  real_T Filter_DSTATE_n;              /* '<S134>/Filter' */
  real_T Integrator_DSTATE_c;          /* '<S139>/Integrator' */
  real_T SFunctionBuilder2_DSTATE;     /* '<S7>/S-Function Builder2' */
  real_T RateTransition_Buffer0[3];    /* '<S7>/Rate Transition' */
  uint8_T is_active_c3_TrayectoriaObstacu;/* '<Root>/Chart' */
  uint8_T is_c3_TrayectoriaObstaculos; /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_TrayectoriaObstaculos_T;

/* Parameters (default storage) */
struct P_TrayectoriaObstaculos_T_ {
  real_T PIDder_D;                     /* Mask Parameter: PIDder_D
                                        * Referenced by: '<S85>/Derivative Gain'
                                        */
  real_T PIDizq_D;                     /* Mask Parameter: PIDizq_D
                                        * Referenced by: '<S133>/Derivative Gain'
                                        */
  real_T PIDder_I;                     /* Mask Parameter: PIDder_I
                                        * Referenced by: '<S88>/Integral Gain'
                                        */
  real_T PIDizq_I;                     /* Mask Parameter: PIDizq_I
                                        * Referenced by: '<S136>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S161>/UD'
                               */
  real_T PIDder_InitialConditionForFilte;
                              /* Mask Parameter: PIDder_InitialConditionForFilte
                               * Referenced by: '<S86>/Filter'
                               */
  real_T PIDizq_InitialConditionForFilte;
                              /* Mask Parameter: PIDizq_InitialConditionForFilte
                               * Referenced by: '<S134>/Filter'
                               */
  real_T PIDder_InitialConditionForInteg;
                              /* Mask Parameter: PIDder_InitialConditionForInteg
                               * Referenced by: '<S91>/Integrator'
                               */
  real_T PIDizq_InitialConditionForInteg;
                              /* Mask Parameter: PIDizq_InitialConditionForInteg
                               * Referenced by: '<S139>/Integrator'
                               */
  real_T PIDder_LowerSaturationLimit;
                                  /* Mask Parameter: PIDder_LowerSaturationLimit
                                   * Referenced by: '<S98>/Saturation'
                                   */
  real_T PIDizq_LowerSaturationLimit;
                                  /* Mask Parameter: PIDizq_LowerSaturationLimit
                                   * Referenced by: '<S146>/Saturation'
                                   */
  real_T PIDder_N;                     /* Mask Parameter: PIDder_N
                                        * Referenced by: '<S94>/Filter Coefficient'
                                        */
  real_T PIDizq_N;                     /* Mask Parameter: PIDizq_N
                                        * Referenced by: '<S142>/Filter Coefficient'
                                        */
  real_T PIDder_P;                     /* Mask Parameter: PIDder_P
                                        * Referenced by: '<S96>/Proportional Gain'
                                        */
  real_T PIDizq_P;                     /* Mask Parameter: PIDizq_P
                                        * Referenced by: '<S144>/Proportional Gain'
                                        */
  real_T PIDder_UpperSaturationLimit;
                                  /* Mask Parameter: PIDder_UpperSaturationLimit
                                   * Referenced by: '<S98>/Saturation'
                                   */
  real_T PIDizq_UpperSaturationLimit;
                                  /* Mask Parameter: PIDizq_UpperSaturationLimit
                                   * Referenced by: '<S146>/Saturation'
                                   */
  real_T PurePursuit_DesiredLinearVeloci;/* Expression: 0.3
                                          * Referenced by: '<Root>/Pure Pursuit'
                                          */
  real_T PurePursuit_MaxAngularVelocity;/* Expression: pi/2
                                         * Referenced by: '<Root>/Pure Pursuit'
                                         */
  real_T PurePursuit_LookaheadDistance;/* Expression: 0.22
                                        * Referenced by: '<Root>/Pure Pursuit'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<S158>/Encoder'
                                        */
  real_T Encoder1_SampleTime;          /* Expression: -1
                                        * Referenced by: '<S158>/Encoder1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S159>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S160>/Constant'
                                        */
  real_T Constant_Value_c[8];         /* Expression: [0 0; 2.1 0; 2.1 4.2;7 4.2]
                                       * Referenced by: '<Root>/Constant'
                                       */
  real_T Jacobianoinverso_Value[4];    /* Expression: [1 -d/2; 1 d/2]
                                        * Referenced by: '<S3>/Jacobiano inverso'
                                        */
  real_T Jacobianodirecto_Value[4];    /* Expression: [1/2 1/2; -1/d 1/d]
                                        * Referenced by: '<S4>/Jacobiano directo'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S6>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S6>/Discrete-Time Integrator'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S161>/TSamp'
                                        */
  real_T RateTransition_InitialCondition;/* Expression: 0
                                          * Referenced by: '<S7>/Rate Transition'
                                          */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S86>/Filter'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S91>/Integrator'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S157>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -255
                                        * Referenced by: '<S157>/Saturation3'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S157>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 1
                                        * Referenced by: '<S157>/Saturation2'
                                        */
  real_T Filter_gainval_j;             /* Computed Parameter: Filter_gainval_j
                                        * Referenced by: '<S134>/Filter'
                                        */
  real_T Integrator_gainval_m;       /* Computed Parameter: Integrator_gainval_m
                                      * Referenced by: '<S139>/Integrator'
                                      */
  real_T Saturation1_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S157>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -255
                                        * Referenced by: '<S157>/Saturation1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<S157>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 1
                                        * Referenced by: '<S157>/Saturation'
                                        */
  real_T mmacm_Gain;                   /* Expression: 1/10
                                        * Referenced by: '<S7>/mm a cm'
                                        */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S158>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TrayectoriaObstaculos_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_TrayectoriaObstaculos_T TrayectoriaObstaculos_P;

/* Block signals (default storage) */
extern B_TrayectoriaObstaculos_T TrayectoriaObstaculos_B;

/* Block states (default storage) */
extern DW_TrayectoriaObstaculos_T TrayectoriaObstaculos_DW;

/* External function called from main */
extern void TrayectoriaObstaculos_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void TrayectoriaObstaculos_initialize(void);
extern void TrayectoriaObstaculos_step0(void);
extern void TrayectoriaObstaculos_step1(void);
extern void TrayectoriaObstaculos_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TrayectoriaObstaculo_T *const TrayectoriaObstaculos_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Consigna' : Unused code path elimination
 * Block '<S33>/Derivative Gain' : Unused code path elimination
 * Block '<S34>/Filter' : Unused code path elimination
 * Block '<S34>/SumD' : Unused code path elimination
 * Block '<S42>/Filter Coefficient' : Unused code path elimination
 * Block '<S44>/Proportional Gain' : Unused code path elimination
 * Block '<S48>/Sum' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S5>/Display' : Unused code path elimination
 * Block '<S5>/Display2' : Unused code path elimination
 * Block '<S157>/Display' : Unused code path elimination
 * Block '<S157>/Display1' : Unused code path elimination
 * Block '<S157>/Display2' : Unused code path elimination
 * Block '<S157>/Display3' : Unused code path elimination
 * Block '<S157>/Display4' : Unused code path elimination
 * Block '<S157>/Display5' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/Display' : Unused code path elimination
 * Block '<Root>/Sum' : Unused code path elimination
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
 * '<Root>' : 'TrayectoriaObstaculos'
 * '<S1>'   : 'TrayectoriaObstaculos/Chart'
 * '<S2>'   : 'TrayectoriaObstaculos/PID Controller'
 * '<S3>'   : 'TrayectoriaObstaculos/Subsystem Reference'
 * '<S4>'   : 'TrayectoriaObstaculos/Subsystem Reference1'
 * '<S5>'   : 'TrayectoriaObstaculos/Subsystem Reference2'
 * '<S6>'   : 'TrayectoriaObstaculos/Subsystem Reference3'
 * '<S7>'   : 'TrayectoriaObstaculos/Subsystem Reference4'
 * '<S8>'   : 'TrayectoriaObstaculos/PID Controller/Anti-windup'
 * '<S9>'   : 'TrayectoriaObstaculos/PID Controller/D Gain'
 * '<S10>'  : 'TrayectoriaObstaculos/PID Controller/Filter'
 * '<S11>'  : 'TrayectoriaObstaculos/PID Controller/Filter ICs'
 * '<S12>'  : 'TrayectoriaObstaculos/PID Controller/I Gain'
 * '<S13>'  : 'TrayectoriaObstaculos/PID Controller/Ideal P Gain'
 * '<S14>'  : 'TrayectoriaObstaculos/PID Controller/Ideal P Gain Fdbk'
 * '<S15>'  : 'TrayectoriaObstaculos/PID Controller/Integrator'
 * '<S16>'  : 'TrayectoriaObstaculos/PID Controller/Integrator ICs'
 * '<S17>'  : 'TrayectoriaObstaculos/PID Controller/N Copy'
 * '<S18>'  : 'TrayectoriaObstaculos/PID Controller/N Gain'
 * '<S19>'  : 'TrayectoriaObstaculos/PID Controller/P Copy'
 * '<S20>'  : 'TrayectoriaObstaculos/PID Controller/Parallel P Gain'
 * '<S21>'  : 'TrayectoriaObstaculos/PID Controller/Reset Signal'
 * '<S22>'  : 'TrayectoriaObstaculos/PID Controller/Saturation'
 * '<S23>'  : 'TrayectoriaObstaculos/PID Controller/Saturation Fdbk'
 * '<S24>'  : 'TrayectoriaObstaculos/PID Controller/Sum'
 * '<S25>'  : 'TrayectoriaObstaculos/PID Controller/Sum Fdbk'
 * '<S26>'  : 'TrayectoriaObstaculos/PID Controller/Tracking Mode'
 * '<S27>'  : 'TrayectoriaObstaculos/PID Controller/Tracking Mode Sum'
 * '<S28>'  : 'TrayectoriaObstaculos/PID Controller/Tsamp - Integral'
 * '<S29>'  : 'TrayectoriaObstaculos/PID Controller/Tsamp - Ngain'
 * '<S30>'  : 'TrayectoriaObstaculos/PID Controller/postSat Signal'
 * '<S31>'  : 'TrayectoriaObstaculos/PID Controller/preSat Signal'
 * '<S32>'  : 'TrayectoriaObstaculos/PID Controller/Anti-windup/Disabled'
 * '<S33>'  : 'TrayectoriaObstaculos/PID Controller/D Gain/Internal Parameters'
 * '<S34>'  : 'TrayectoriaObstaculos/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S35>'  : 'TrayectoriaObstaculos/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S36>'  : 'TrayectoriaObstaculos/PID Controller/I Gain/Disabled'
 * '<S37>'  : 'TrayectoriaObstaculos/PID Controller/Ideal P Gain/Passthrough'
 * '<S38>'  : 'TrayectoriaObstaculos/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S39>'  : 'TrayectoriaObstaculos/PID Controller/Integrator/Disabled'
 * '<S40>'  : 'TrayectoriaObstaculos/PID Controller/Integrator ICs/Disabled'
 * '<S41>'  : 'TrayectoriaObstaculos/PID Controller/N Copy/Disabled'
 * '<S42>'  : 'TrayectoriaObstaculos/PID Controller/N Gain/Internal Parameters'
 * '<S43>'  : 'TrayectoriaObstaculos/PID Controller/P Copy/Disabled'
 * '<S44>'  : 'TrayectoriaObstaculos/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S45>'  : 'TrayectoriaObstaculos/PID Controller/Reset Signal/Disabled'
 * '<S46>'  : 'TrayectoriaObstaculos/PID Controller/Saturation/Passthrough'
 * '<S47>'  : 'TrayectoriaObstaculos/PID Controller/Saturation Fdbk/Disabled'
 * '<S48>'  : 'TrayectoriaObstaculos/PID Controller/Sum/Sum_PD'
 * '<S49>'  : 'TrayectoriaObstaculos/PID Controller/Sum Fdbk/Disabled'
 * '<S50>'  : 'TrayectoriaObstaculos/PID Controller/Tracking Mode/Disabled'
 * '<S51>'  : 'TrayectoriaObstaculos/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'TrayectoriaObstaculos/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S53>'  : 'TrayectoriaObstaculos/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'TrayectoriaObstaculos/PID Controller/postSat Signal/Forward_Path'
 * '<S55>'  : 'TrayectoriaObstaculos/PID Controller/preSat Signal/Forward_Path'
 * '<S56>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference'
 * '<S57>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference1'
 * '<S58>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der'
 * '<S59>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq'
 * '<S60>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Anti-windup'
 * '<S61>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/D Gain'
 * '<S62>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Filter'
 * '<S63>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Filter ICs'
 * '<S64>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/I Gain'
 * '<S65>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Ideal P Gain'
 * '<S66>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Ideal P Gain Fdbk'
 * '<S67>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Integrator'
 * '<S68>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Integrator ICs'
 * '<S69>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/N Copy'
 * '<S70>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/N Gain'
 * '<S71>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/P Copy'
 * '<S72>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Parallel P Gain'
 * '<S73>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Reset Signal'
 * '<S74>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Saturation'
 * '<S75>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Saturation Fdbk'
 * '<S76>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Sum'
 * '<S77>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Sum Fdbk'
 * '<S78>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Tracking Mode'
 * '<S79>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Tracking Mode Sum'
 * '<S80>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Tsamp - Integral'
 * '<S81>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Tsamp - Ngain'
 * '<S82>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/postSat Signal'
 * '<S83>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/preSat Signal'
 * '<S84>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Anti-windup/Passthrough'
 * '<S85>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/D Gain/Internal Parameters'
 * '<S86>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Filter/Disc. Forward Euler Filter'
 * '<S87>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Filter ICs/Internal IC - Filter'
 * '<S88>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/I Gain/Internal Parameters'
 * '<S89>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Ideal P Gain/Passthrough'
 * '<S90>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Ideal P Gain Fdbk/Disabled'
 * '<S91>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Integrator/Discrete'
 * '<S92>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Integrator ICs/Internal IC'
 * '<S93>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/N Copy/Disabled'
 * '<S94>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/N Gain/Internal Parameters'
 * '<S95>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/P Copy/Disabled'
 * '<S96>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Parallel P Gain/Internal Parameters'
 * '<S97>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Reset Signal/Disabled'
 * '<S98>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Saturation/Enabled'
 * '<S99>'  : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Saturation Fdbk/Disabled'
 * '<S100>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Sum/Sum_PID'
 * '<S101>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Sum Fdbk/Disabled'
 * '<S102>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Tracking Mode/Disabled'
 * '<S103>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Tsamp - Integral/TsSignalSpecification'
 * '<S105>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/Tsamp - Ngain/Passthrough'
 * '<S106>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/postSat Signal/Forward_Path'
 * '<S107>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID der/preSat Signal/Forward_Path'
 * '<S108>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Anti-windup'
 * '<S109>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/D Gain'
 * '<S110>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Filter'
 * '<S111>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Filter ICs'
 * '<S112>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/I Gain'
 * '<S113>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Ideal P Gain'
 * '<S114>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Ideal P Gain Fdbk'
 * '<S115>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Integrator'
 * '<S116>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Integrator ICs'
 * '<S117>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/N Copy'
 * '<S118>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/N Gain'
 * '<S119>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/P Copy'
 * '<S120>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Parallel P Gain'
 * '<S121>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Reset Signal'
 * '<S122>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Saturation'
 * '<S123>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Saturation Fdbk'
 * '<S124>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Sum'
 * '<S125>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Sum Fdbk'
 * '<S126>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Tracking Mode'
 * '<S127>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Tracking Mode Sum'
 * '<S128>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Tsamp - Integral'
 * '<S129>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Tsamp - Ngain'
 * '<S130>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/postSat Signal'
 * '<S131>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/preSat Signal'
 * '<S132>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Anti-windup/Passthrough'
 * '<S133>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/D Gain/Internal Parameters'
 * '<S134>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Filter/Disc. Forward Euler Filter'
 * '<S135>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Filter ICs/Internal IC - Filter'
 * '<S136>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/I Gain/Internal Parameters'
 * '<S137>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Ideal P Gain/Passthrough'
 * '<S138>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Ideal P Gain Fdbk/Disabled'
 * '<S139>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Integrator/Discrete'
 * '<S140>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Integrator ICs/Internal IC'
 * '<S141>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/N Copy/Disabled'
 * '<S142>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/N Gain/Internal Parameters'
 * '<S143>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/P Copy/Disabled'
 * '<S144>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Parallel P Gain/Internal Parameters'
 * '<S145>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Reset Signal/Disabled'
 * '<S146>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Saturation/Enabled'
 * '<S147>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Saturation Fdbk/Disabled'
 * '<S148>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Sum/Sum_PID'
 * '<S149>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Sum Fdbk/Disabled'
 * '<S150>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Tracking Mode/Disabled'
 * '<S151>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Tracking Mode Sum/Passthrough'
 * '<S152>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Tsamp - Integral/TsSignalSpecification'
 * '<S153>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/Tsamp - Ngain/Passthrough'
 * '<S154>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/postSat Signal/Forward_Path'
 * '<S155>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference/PID izq/preSat Signal/Forward_Path'
 * '<S156>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1'
 * '<S157>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1/Subsystem Reference'
 * '<S158>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1/Subsystem Reference1'
 * '<S159>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1/Subsystem Reference/Compare To Zero'
 * '<S160>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1/Subsystem Reference/Compare To Zero1'
 * '<S161>' : 'TrayectoriaObstaculos/Subsystem Reference2/Subsystem Reference1/Subsystem Reference1/Subsystem Reference1/Discrete Derivative'
 */
#endif                                 /* RTW_HEADER_TrayectoriaObstaculos_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
