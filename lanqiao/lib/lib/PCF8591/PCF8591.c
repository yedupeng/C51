#include "intrins.h"
#include "iic.h"

unsigned char PCF8591_ADC(void)
{
	unsigned char temp;
	
	IIC_Start();
	IIC_SendByte(0x90);
	IIC_WaitAck();

	IIC_SendByte(0x43);
	IIC_WaitAck();

	IIC_Start();
	IIC_SendByte(0x91);
	IIC_WaitAck();

	temp = IIC_RecByte();
	IIC_SendAck(1);
	IIC_Stop();
	return temp;
}

void PCF8591_DAC(unsigned char dat)
{
	IIC_Start();
	IIC_SendByte(0x90);
	IIC_WaitAck();
	IIC_SendByte(0x43);
	IIC_WaitAck();
	IIC_SendByte(dat);
	IIC_WaitAck();
	IIC_Stop();
}

