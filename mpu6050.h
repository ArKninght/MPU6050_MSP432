/*
 * mpu6050.h
 *
 *  Created on: 2023年7月3日
 *      Author: 15976
 */

#ifndef MPU6050_H_
#define MPU6050_H_

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <my_uart.h>
#include <my_iic.h>
#include <delay.h>
#include <math.h>

#define MPU6050_ADDR         0x68 //器件地址，接地默认地址为0x68，接vcc默认地址为0x69
#define MPU6050_SMPLRT_DIV   0x19 //陀螺仪采样率分频寄存器
#define MPU6050_CONFIG       0x1a //配置寄存器
#define MPU6050_GYRO_CONFIG  0x1b //陀螺仪配置寄存器
#define MPU6050_ACCEL_CONFIG 0x1c //加速度配置寄存器
#define MPU6050_WHO_AM_I     0x75 //
#define MPU6050_PWR_MGMT_1   0x6b //电源管理寄存器1
#define MPU6050_PWR_MGMT_2   0x6c //电源管理寄存器2
#define MPU_ACCEL_XOUTH_REG  0x3b //加速度传感器数据输出寄存器
#define MPU_GYRO_XOUTH_REG   0x43 //陀螺仪数据输出寄存器
#define MPU6050_TEMP_H       0x41 //温度传感器数据输出寄存器 高八位
#define MPU6050_TEMP_L       0x42 //温度传感器数据输出寄存器 低八位
#define MPU_DEVICE_ID_REG    0x75
typedef uint8_t u8;
typedef uint16_t u16;

#define PI 3.1415926535897932384626433832795

extern int16_t rawAccX, rawAccY, rawAccZ,rawGyroX, rawGyroY, rawGyroZ;
extern float gyroXoffset, gyroYoffset, gyroZoffset;
extern float temp, accX, accY, accZ, gyroX, gyroY, gyroZ;
extern float angleGyroX, angleGyroY, angleGyroZ,angleAccX, angleAccY, angleAccZ;
extern float angleX, angleY, angleZ;
extern uint32_t timer;
extern float accCoef;
extern float gyroCoef;

u8 MPU_Init(void);
void calcGyroOffsets(void);
void mpu_update(void);
u8 MPU_Set_Gyro_Fsr(u8 fsr);
u8 MPU_Set_Accel_Fsr(u8 fsr);
u8 MPU_Set_LPF(u16 lpf);
u8 MPU_Set_Rate(u16 rate);
short MPU_Get_Temperature();
u8 MPU_Get_Gyroscope(int16_t *gx,int16_t *gy,int16_t *gz);
u8 MPU_Get_Accelerometer(int16_t *ax,int16_t *ay,int16_t *az);
u8 MPU_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf);
u8 MPU_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf);
u8 MPU_Write_Byte(u8 reg,u8 data);
u8 MPU_Read_Byte(u8 reg);

#endif /* MPU6050_H_ */
