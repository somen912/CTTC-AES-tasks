#include <reg51.h>

int i,j;

void delay()
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
  int arr[]={3,6,0xC,9};
	
	while(1)
	{
	  for(j=0;j<sizeof arr;j++)
		{
		  P3=arr[j];
			delay();
		}
	}
}