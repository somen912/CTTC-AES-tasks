// display 0 to F by use of 7 segment common anode display with 1sec delay.


#include <reg51.h>

int i,j;

char arr[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

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
	  for(j=0;j<16;j++)
		{
		  P2=arr[j];
			delay();
		}
	}
}