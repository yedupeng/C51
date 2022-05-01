#include "STC15F2K60S2.h"

void Seg_Tran(unsigned char *pucSeg_Buf, unsigned char * pucSeg_Code)
{
	unsigned char i, j = 0,temp;
	for(i=0;i<8;i++,j++)
	{																      // ģ��ƥ�䣬��pucSeg_Buf�е�ֵ����ƥ��
		switch(pucSeg_Buf[j])
		{
			case '0' : temp = 0xC0;break;
			case '1' : temp = 0xF9;break;
			case '2' : temp = 0xA4;break;
			case '3' : temp = 0xB0;break;
			case '4' : temp = 0x99;break;
			case '5' : temp = 0x92;break;
			case '6' : temp = 0x82;break;
			case '7' : temp = 0xF8;break;
			case '8' : temp = 0x80;break;
			case '9' : temp = 0x90;break;
			
			case 'A' : temp = 0x88;break;
			case 'B' : temp = 0x83;break;
			case 'C' : temp = 0xC6;break;
			case 'D' : temp = 0xA1;break;
			case 'E' : temp = 0x86;break;
			case 'F' : temp = 0x8E;break;
			case 'H' : temp = 0x89;break;
			case 'L' : temp = 0xC7;break;
			case 'N' : temp = 0xC8;break;
			case 'P' : temp = 0x8C;break;
			case 'U' : temp = 0xC1;break;
			case '-' : temp = 0xBF;break;
			case ' ' : temp = 0xff;break;
			
			default: temp = 0xFF;
		}
	if(pucSeg_Buf[j+1]==".")
	{
		temp = temp&0x7f;
		j++;
	}
		pucSeg_Code[i] =  temp;
   }
}

void Seg_Disp(unsigned char *pucSeg_Code, unsigned char ucSeg_Pos)	  	 // �������ʾ����
{																	 	 // ע��  ��ʾʱ������8������ܵ������ֱ�洢��buffer[9]�Ķ�Ӧ�ռ��н���ģ��ƥ��
	P0 = 0xff;														 	 // ����
	P2 = P2 & 0x1F | 0xE0;											 	 // ��λY7C
	P2 &= 0x1F;														 	 // ����
	P0 = 1<<ucSeg_Pos;												 	 // λѡ   1����ucSeg_Posλ
	P2 = P2 & 0x1F | 0xC0;											 	 // ��λY6C
	P2 &= 0x1F;														 	 // ����
	P0 = pucSeg_Code[ucSeg_Pos];									 	 // ��ѡ
	P2 = P2 & 0x1F | 0xE0;											 	 // ��λY7C
	P2 &= 0x1F;														 	 // ����
}
