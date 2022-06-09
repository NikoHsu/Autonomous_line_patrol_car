
#include "basic.h"
/*
	��ʱus�����Ȳ���
*/
void DelayUs(u16 i)
{
	while(--i);
}
/*
	��ʱms�����Ȳ���
*/
void DelayMs(u16 t)
{
	u16 i,j;
	for(i=0; i<t; i++)
		for(j=0; j<120; j++);
}
