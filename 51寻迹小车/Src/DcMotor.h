

#ifndef DCMOTOR_H
#define DCMOTOR_H

#include "basic.h"

// 电机接口定义
sbit MOTOR0 = P1^2;
sbit MOTOR1 = P1^1;
sbit MOTOR2 = P1^5;
sbit MOTOR3 = P1^4;

// 红外避障接口定义
sbit BIZHANG0 = P2^0;
sbit BIZHANG1 = P2^1;

// 红外寻迹接口定义
sbit GO_RIGHT = P3^7;
sbit GO_LEFT = P3^6;

typedef enum
{
	FORWARD=0,
	BACKUP,
	LEFT,
	RIGHT,
	STOP,
}MOTOR_DIR;

void MotorContorl(MOTOR_DIR dir, u8 speed);		// 小车直流电机控制，dir方向，speed速度


#endif
