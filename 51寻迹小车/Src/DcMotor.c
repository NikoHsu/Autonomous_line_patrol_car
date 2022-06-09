
#include "dcmotor.h"

/*
	ͨ������2�����������С���˶���
	dir��ʾ�˶�����
	speed��ʾ�˶��ٶ�
*/
void MotorContorl(MOTOR_DIR dir, u8 speed)
{
	switch(dir)
	{
		// ǰ��
		case FORWARD:
			MOTOR0 = 0;
			MOTOR1 = 1;
			MOTOR2 = 0;
			MOTOR3 = 1;
		break;
		// ����
		case BACKUP:
			MOTOR0 = 1;
			MOTOR1 = 0;
			MOTOR2 = 1;
			MOTOR3 = 0;
		break;
		// ��ת
		case LEFT:
			MOTOR0 = 1;
			MOTOR1 = 0;
			MOTOR2 = 0;
			MOTOR3 = 1;
		break;
		// ��ת
		case RIGHT:
			MOTOR0 = 0;
			MOTOR1 = 1;
			MOTOR2 = 1;
			MOTOR3 = 0;
		break;
		// ֹͣ
		case STOP:
			MOTOR0 = 1;
			MOTOR1 = 1;
			MOTOR2 = 1;
			MOTOR3 = 1;
		break;
		// ����
		default:
			MOTOR0 = 1;
			MOTOR1 = 1;
			MOTOR2 = 1;
			MOTOR3 = 1;
		break;
	}
	DelayMs(speed);		// speed��ֵԽ���ٶ�Խ��
	MOTOR0 = 1;
	MOTOR1 = 1;
	MOTOR2 = 1;
	MOTOR3 = 1;
	DelayMs(25 - speed);	// speed��ֵԽ����ʱʱ��Խ�̣��ٶ�Խ��
}
