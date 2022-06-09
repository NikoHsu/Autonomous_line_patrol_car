
#include "hc-sr04.h"

u16 EchoCnt;

void HC04_Init(void)
{
	Trig = 0;
	Echo = 0;
	TMOD &=0Xf0;
	TMOD |=0X01;//ʹ��ģʽ1��16λ��ʱ��0;
	TH0=0;//װ��ֵ
	TL0=0;
	EA=1;//�����ж�
	ET0=1;//����ʱ��0�ж�
	TR0=0;//��ʱ��0
}

void HC04_Loop(void)
{  
	Trig = 1;
	DelayUs(20);
	Trig = 0;
	while(Echo == 0);
	TH0=0;
	TL0=0;
	TR0=1;
	while(Echo == 1);
	EchoCnt = (TH0*256 + TL0)*1.7/100;
	TR0=0;
}

