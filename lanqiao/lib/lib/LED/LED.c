#include "STC15F2K60S2.h"

void Cls_Peripheral(void)		           				// 关闭外设
{
	P0 = 0xFF;
	P2 = P2 & 0x1F | 0x80;
	P2 &= 0x1F;
	P0 = 0x00;
	P2 = P2 & 0x1F | 0xA0;
	P2 &= 0x1F;
}

void Led_Disp(unsigned char ucLed)						// Led显示
{
	P0 = ~ucLed;
	P2 = P2 & 0x1F | 0x80;								
	P2 &= 0x1F;
}