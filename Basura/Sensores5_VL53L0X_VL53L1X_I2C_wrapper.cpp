
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE

#include<Arduino.h>
#include<math.h>
#include<twi.h>
#include<twi.c>
#include<Wire.h>
#include<Wire.cpp>
#include<VL53L0X.h>
#include<VL53L0X.cpp>

VL53L0X sensorL0[7];
unsigned char pin_sensor[7]={48,50,52};
int nueva_direccion[7]={42,44,46};

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 3
#define y_1_width 3

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void Sensores5_VL53L0X_VL53L1X_I2C_Outputs_wrapper(real_T *Sensor,
			real_T *Status,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==1)
{
    #ifndef MATLAB_MEX_FILE

    for(int i=0;i<3;i++)
    {
        
        Sensor[i]=sensorL0[i].readRangeContinuousMillimeters();
        
    }
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void Sensores5_VL53L0X_VL53L1X_I2C_Update_wrapper(real_T *Sensor,
			real_T *Status,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1)
{
    #ifndef MATLAB_MEX_FILE
    
    for(int i=0;i<7;i++)    Status[i]=0;
    
    for(int i=48;i<=52;i++)    pinMode(i,OUTPUT);
    for(int i=48;i<=52;i++)   digitalWrite(i,LOW);
    
    Wire.begin();
    
    for(int i=0;i<3;i++)
    {
        digitalWrite(pin_sensor[i],HIGH);
        delay(10);
        
        Wire.beginTransmission(0x29);                  
        sensorL0[i].setAddress(nueva_direccion[i]);   
        if(!sensorL0[i].init())                       
        {
            Status[i]=1;
        }
      sensorL0[i].setTimeout(500);                 
      sensorL0[i].startContinuous();               
      Wire.endTransmission();                    
    }
    
    #endif
    
    xD[0]=1;  
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

