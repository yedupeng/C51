#include "STC15F2K60S2.h"
#include "itrpt.h"
void Inter_Init(void)
{
	IT0 = 1;
	EX0 = 1;
	IT1 = 1;
	EX1 = 1;
	EA = 1;
}

void Timer0Init(void)		//100微秒@11.0592MHz
{
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xf5;		//设置定时初值
	TH0 = 0xff;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	EA = 1;
}


void Timer1Init(void)		//100微秒@11.0592MHz
{
	AUXR |= 0x40;		//定时器时钟1T模式
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0x20;		//设置定时初始值
	TH1 = 0xD1;		//设置定时初始值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时
	ET1 = 1;
	EA = 1;
}


void counter0_init(void)
{
	AUXR &= 0X1f;		//定时器时钟1T模式
	TMOD |= 5;		//设置计数器模式，P3.4/TO口每检测一次上升沿，计数器加一，16位自动重装载
	TL0 = 0;			//设置定时初值
	TH0 = 0;			//设置定时初值
	TF0 = 0;			//清除TF0标志
	TR0 = 1;			//定时器0关闭
}

void counter1_init(void)
{
	AUXR &= 0XF7;		//定时器时钟1T模式
	TMOD |= 0x50;		//设置计数器模式，P3.4/TO口每检测一次上升沿，计数器加一，16位自动重装载
	TL1 = 0;			//设置定时初值
	TH1 = 0;			//设置定时初值
	TF1 = 0;			//清除TF0标志
	TR1 = 1;			//定时器0关闭
}