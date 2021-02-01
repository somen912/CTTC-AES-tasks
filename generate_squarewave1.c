// generate a square wave of 150 msec and 30 msec

#include <reg51.h>

sbit output_pin=P3^0;

int i,j,k;

void delay1() // delay function for 150msec
{
	TMOD=0x02;
  for(i=0;i<540;i++)
	{
    	TH0=0;
		  TR0=1;
		  while(TF0==0);
		  TF0=0;
	}
}


void delay2()  //delay function for 30msec
{
	TMOD=0x10;
  TH1=0x93;
	TL1=0xFF;
	TR1=1;
	while(TF1==0);
	TF1=0;
	TR1=0;
}

void main()
{
  
	
	for(j=0;j<2;j++)
	{
	  output_pin=~output_pin;
		delay1();
	}
	
	for(k=0;k<6;k++)
	{
	  output_pin=~output_pin;
		delay2();
	}
}