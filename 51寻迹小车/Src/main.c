
#include "basic.h"		

void main(void)				// ������
{
	UartInit();
	HC04_Init();
	SendString("SystemInitial\r\n");
	while(1)
	{
		HC04_Loop();   //���������
		if(EchoCnt < 15)			// ����������С��10cm
				{
					//MotorContorl(STOP, 20);				// С��ֹͣ
//					MOTOR0 = 1;
//			MOTOR1 = 0;
//			MOTOR2 = 0;
//			MOTOR3 = 1;				// С���������
						MotorContorl(LEFT, 25);		
					//DelayMs(1000);
//					MOTOR0 = 0;
//			MOTOR1 = 1;
//			MOTOR2 = 0;
//			MOTOR3 = 1;
          //DelayMs(1000);					
				}
				else
				{
						if((GO_RIGHT == 1) && (GO_LEFT == 0))			// Ѱ���ұߺ����⵽����
							{
								MotorContorl(RIGHT, 23);				// С�����ұ���
							}
							else if((GO_RIGHT == 0) && (GO_LEFT == 1))		// С����ߺ����⵽����
							{
								MotorContorl(LEFT, 23);				// С���������
							}
							else if((GO_RIGHT == 0) && (GO_LEFT == 0))		// С�����Ҷ�û�м�⵽����
							{
								MotorContorl(FORWARD, 23);			// С��ֱ��
							}
				}
	}
}
