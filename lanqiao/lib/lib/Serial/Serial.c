#include "STC15F2K60S2.h"  
#include "intrins.h"
#define BAUD	     2400 	  //������
#define SYSTEMCLOCK  11059200L //ϵͳʱ��Ƶ��
  

void delay()
{
	unsigned char i, j;
    for(i=0;i<180;i++)
	for(j=0;j<200;j++);
}


void Init()
{
	SCON = 0x50; //���ڲ���Ϊģʽ1���������          

    AUXR = 0x40;                
    TMOD = 0x00;               
    TL1 = (65536 - (SYSTEMCLOCK/4/BAUD)); 
    TH1 = (65536 - (SYSTEMCLOCK/4/BAUD))>>8;
    TR1 = 1;   //������ʱ��1
	EA=1;	   //ʹ�����ж�
	ES=1;      //ʹ�ܴ����ж� 
}

void SendByte(unsigned char Dat)	//����
{
	SBUF = Dat;    //����
	while(TI == 0);//�ȴ�������ɣ�ΪTIΪ1ʱ����ʾ�������
		TI = 0;    //�����־
}

void uart_sendstring(unsigned char *str)
{
    unsigned char *s;
    
    s = str;
    while(*s != '\0')
    {
        SBUF = *s;		 //�����ݷŽ�SBUF������
		while(TI == 0);  //�ȴ������������
		TI = 0;			 //���������ɱ�־
        s++;
    }
}

