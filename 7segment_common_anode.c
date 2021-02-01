// display 0 to F by use of 7 segment common anode display with 1sec delay.


#include <reg51.h>

int i,j;

char arr[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};

void delay()  // 1 sec delay function
{
  TMOD=0x02;
	for(i=0;i<3600;i++)
	{
	  TH0=0;
		TR0=1;
		while(TF0==0);
		TF0=0;
	}
}



void main()
{
  while(1)
	{
	  for(j=15;j>=0;j--)
		{
		  P2=arr[j];
			delay();
		}
	}
}