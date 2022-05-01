#include "STC15F2K60S2.h"

sbit TX = P1^0;
sbit RX = P1^1;

void Time0_Init(void)
{
	AUXR &= 0x7F;
	TMOD &= 0xFD;
	TH0 = 0xff;
	TL0 = 0xf4;
	TR0 = 0;
	TF0 = 0;	
}

unsigned char Wave_Recv(void)
{
	unsigned char ucNum = 10, ucDist;
	TX = 0;
	TH0 = 0xFF;
	TL0 = 0xF4;
	TR0 = 1;
	while(ucNum--)
	{
		while(!TF0);
		TX ^= 1;
		TF0 = 0;
	}
	TR0 = 0;
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;
	while(RX && !TF0);
	TR0 = 0;
	if(TF0)
	{
		TF0 = 0;
		ucDist = 255;
	}
	else
		ucDist = ((TH0<<8)+TL0)*0.017;
	return ucDist;
}
