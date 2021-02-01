// Transmitt 'Good morning' to virtual terminal with 1 sec delay continuosly.


#include <reg51.h>

int i,j;

char arr[]="Good morning";

void delay()
{
	for(j=0;j<3600;j++)
	{
	  TH0=0;
		TR0=1;
		while(TF0==0);
		TF0=0;
	}
}

void main()
{
	
	SCON=0x50;
	TMOD= 0x22;
	TH1=0xFD;
	TR1=1;
	
	while(1)
	{
	  for(i=0;i<sizeof arr;i++)
		{
		  SBUF=arr[i];
			while(TI==0);
			TI=0;
		}
		delay();
	}
}