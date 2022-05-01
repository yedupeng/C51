#include "STC15F2K60S2.h" 

unsigned char Read_key(void)
{
	unsigned int key_New;
	unsigned char key_Val;
	P44 = 0;
	P42 = 1;
	P35 = 1;
	P34 = 1;
	key_New = P3;
	P44 = 1;
	P42 = 0;
	key_New = (key_New<<4)|(P3&0x0f);
	P42 = 1;
	P35 = 0;
	key_New = (key_New<<4)|(P3&0x0f);
	P35 = 1;
	P34 = 0;
	key_New = (key_New<<4)|(P3&0x0f);
	switch(~key_New)
	{
		case 0x8000: key_Val = 4;break;
		case 0x4000: key_Val = 5;break;
		case 0x2000: key_Val = 6;break;
		case 0x1000: key_Val = 7;break;
		case 0x0800: key_Val = 8;break;
		case 0x0400: key_Val = 9;break;
		case 0x0200: key_Val = 10;break;
		case 0x0100: key_Val = 11;break;
		case 0x0080: key_Val = 12;break;
		case 0x0040: key_Val = 13;break;
		case 0x0020: key_Val = 14;break;
		case 0x0010: key_Val = 15;break;
		case 0x0008: key_Val = 16;break;
		case 0x0004: key_Val = 17;break;
		case 0x0002: key_Val = 18;break;
		case 0x0001: key_Val = 19;break;
		default:key_Val = 0;
	}
	return key_Val;
}