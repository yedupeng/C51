#include "iic.h"
#include "intrins.h"


void EEPROM_Read(unsigned char* pucBuf, unsigned char addr, unsigned char num)
{
	IIC_Start();
	IIC_SendByte(0xa0);
	IIC_WaitAck();

	IIC_SendByte(addr);
    IIC_WaitAck();

	IIC_Start();
	IIC_SendByte(0xa1);
	IIC_WaitAck();

	while(num--)
	{
		*pucBuf++ = IIC_RecByte();
		if(num) IIC_SendAck(0);
		else IIC_SendAck(1);
	}
	IIC_Stop();
}


void EEPROM_Write(unsigned char* pucBuf, unsigned char addr, unsigned char num)
{
	IIC_Start();
	IIC_SendByte(0xa0);
	IIC_WaitAck();

	IIC_SendByte(addr);
	IIC_WaitAck();

	while(num--)
	{
		IIC_SendByte(*pucBuf++);
		IIC_WaitAck();
		IIC_Delay(200);
	}
     	IIC_Stop();
		IIC_Delay(20);

}
