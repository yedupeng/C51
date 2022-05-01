#include "STC15F2K60S2.h"

void Cls_Peripheral(void)		           				// �ر�����
{
	P0 = 0xFF;
	P2 = P2 & 0x1F | 0x80;
	P2 &= 0x1F;
	P0 = 0x00;
	P2 = P2 & 0x1F | 0xA0;
	P2 &= 0x1F;
}

void Led_Disp(unsigned char ucLed)						// Led��ʾ
{
	P0 = ~ucLed;
	P2 = P2 & 0x1F | 0x80;								
	P2 &= 0x1F;
}