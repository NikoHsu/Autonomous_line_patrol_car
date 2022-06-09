#include "uart.h"

bit busy;
u8 RxBuf;

// ���ڳ�ʼ��
void UartInit(void)
{
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TL2 = RCAP2L = (65536-(FOSC/32/BAUD)); //Set auto-reload vaule
    TH2 = RCAP2H = (65536-(FOSC/32/BAUD)) >> 8;
    T2CON = 0x34;           //Timer2 start run
    ES = 1;                 //Enable UART interrupt
    EA = 1;                 //Open master interrupt switch

}


void SendData(u8 dat)
{
    while (busy);           //Wait for the completion of the previous data is sent
    busy = 1;
    SBUF = dat;             //Send data to UART buffer
}

void SendString(char *s)
{
    while (*s)              //Check the end of the string
    {
        SendData(*s++);     //Send current char and increment string ptr
    }
}

// �����жϺ���
void UART_ISR() interrupt 4 using 1
{
    if (RI)
    {
        RI = 0;             //Clear receive interrupt flag
		RxBuf = SBUF;
    }
    if (TI)
    {
        TI = 0;             //Clear transmit interrupt flag
        busy = 0;           //Clear transmit busy flag
    }
}

