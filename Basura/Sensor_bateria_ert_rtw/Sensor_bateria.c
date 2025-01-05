/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Sensor_bateria.c
 *
 * Code generated for Simulink model 'Sensor_bateria'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Dec 15 19:20:18 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Sensor_bateria.h"
#include "rtwtypes.h"
#include "Sensor_bateria_private.h"

/* Block signals (default storage) */
B_Sensor_bateria_T Sensor_bateria_B;

/* Block states (default storage) */
DW_Sensor_bateria_T Sensor_bateria_DW;

/* Real-time model */
static RT_MODEL_Sensor_bateria_T Sensor_bateria_M_;
RT_MODEL_Sensor_bateria_T *const Sensor_bateria_M = &Sensor_bateria_M_;

/* Model step function */
void Sensor_bateria_step(void)
{
  uint16_T b_varargout_1;

  /* MATLABSystem: '<S1>/Analog Input' */
  if (Sensor_bateria_DW.obj.SampleTime !=
      Sensor_bateria_P.AnalogInput_SampleTime) {
    Sensor_bateria_DW.obj.SampleTime = Sensor_bateria_P.AnalogInput_SampleTime;
  }

  Sensor_bateria_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(55UL);
  MW_AnalogInSingle_ReadResult
    (Sensor_bateria_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE, &b_varargout_1,
     MW_ANALOGIN_UINT16);

  /* Gain: '<S1>/Gain' incorporates:
   *  MATLABSystem: '<S1>/Analog Input'
   * */
  Sensor_bateria_B.Gain = (uint32_T)Sensor_bateria_P.Gain_Gain * b_varargout_1;

  {                                    /* Sample time: [0.2s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Sensor_bateria_M->Timing.taskTime0 =
    ((time_T)(++Sensor_bateria_M->Timing.clockTick0)) *
    Sensor_bateria_M->Timing.stepSize0;
}

/* Model initialize function */
void Sensor_bateria_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Sensor_bateria_M, -1);
  Sensor_bateria_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  Sensor_bateria_M->Sizes.checksums[0] = (2767851439U);
  Sensor_bateria_M->Sizes.checksums[1] = (2477152568U);
  Sensor_bateria_M->Sizes.checksums[2] = (2526431035U);
  Sensor_bateria_M->Sizes.checksums[3] = (2905260801U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Sensor_bateria_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Sensor_bateria_M->extModeInfo,
      &Sensor_bateria_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Sensor_bateria_M->extModeInfo,
                        Sensor_bateria_M->Sizes.checksums);
    rteiSetTPtr(Sensor_bateria_M->extModeInfo, rtmGetTPtr(Sensor_bateria_M));
  }

  /* Start for MATLABSystem: '<S1>/Analog Input' */
  Sensor_bateria_DW.obj.matlabCodegenIsDeleted = false;
  Sensor_bateria_DW.obj.SampleTime = Sensor_bateria_P.AnalogInput_SampleTime;
  Sensor_bateria_DW.obj.isInitialized = 1L;
  Sensor_bateria_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogInSingle_Open(55UL);
  Sensor_bateria_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void Sensor_bateria_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Analog Input' */
  if (!Sensor_bateria_DW.obj.matlabCodegenIsDeleted) {
    Sensor_bateria_DW.obj.matlabCodegenIsDeleted = true;
    if ((Sensor_bateria_DW.obj.isInitialized == 1L) &&
        Sensor_bateria_DW.obj.isSetupComplete) {
      Sensor_bateria_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
        MW_AnalogIn_GetHandle(55UL);
      MW_AnalogIn_Close
        (Sensor_bateria_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Analog Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
