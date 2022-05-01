#include "STC15F2K60S2.h"  
#include "intrins.h"
#define BAUD	     2400 	  //波特率
#define SYSTEMCLOCK  11059200L //系统时钟频率
  

void delay()
{
	unsigned char i, j;
    for(i=0;i<180;i++)
	for(j=0;j<200;j++);
}


void Init()
{
	SCON = 0x50; //串口参数为模式1和允许接收          

    AUXR = 0x40;                
    TMOD = 0x00;               
    TL1 = (65536 - (SYSTEMCLOCK/4/BAUD)); 
    TH1 = (65536 - (SYSTEMCLOCK/4/BAUD))>>8;
    TR1 = 1;   //启动定时器1
	EA=1;	   //使能总中断
	ES=1;      //使能串口中断 
}

void SendByte(unsigned char Dat)	//发送
{
	SBUF = Dat;    //发送
	while(TI == 0);//等待发送完成，为TI为1时，表示发送完成
		TI = 0;    //清除标志
}

void uart_sendstring(unsigned char *str)
{
    unsigned char *s;
    
    s = str;
    while(*s != '\0')
    {
        SBUF = *s;		 //将数据放进SBUF缓冲器
		while(TI == 0);  //等待发送数据完成
		TI = 0;			 //清除发送完成标志
        s++;
    }
}

