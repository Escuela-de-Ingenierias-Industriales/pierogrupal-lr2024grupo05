#include <string.h>
#ifdef MATLAB_MEX_FILE
#include "tmwtypes.h"
#else
#include "rtwtypes.h"
#endif

#include "Sensores5_VL53L0X_VL53L1X_I2C_cgen_wrapper.h"

extern void Sensores5_VL53L0X_VL53L1X_I2C_Outputs_wrapper(real_T *Sensor,
  real_T *Status,
  const real_T *xD);
extern void Sensores5_VL53L0X_VL53L1X_I2C_Update_wrapper(real_T *Sensor,
  real_T *Status,
  real_T *xD);
void Sensores5_VL53L0X_VL53L1X_I2C_Outputs_wrapper_cgen(real_T *Sensor,
  real_T *Status,
  const real_T *xD)
{
  Sensores5_VL53L0X_VL53L1X_I2C_Outputs_wrapper(Sensor,
    Status,
    xD);
}

void Sensores5_VL53L0X_VL53L1X_I2C_Update_wrapper_cgen(real_T *Sensor,
  real_T *Status,
  real_T *xD)
{
  Sensores5_VL53L0X_VL53L1X_I2C_Update_wrapper(Sensor,
    Status,
    xD);
}
