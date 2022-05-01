#ifndef	__SERIAL__H
#define __SERIAL__H
typedef unsigned char uchar;


void delay();
void Init();
void SendByte(unsigned char Dat);	//·¢ËÍ
void uart_sendstring(unsigned char *str);

#endif 