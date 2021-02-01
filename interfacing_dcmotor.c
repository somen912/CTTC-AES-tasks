// control direction of the rotation of DC motor by a switch

#include <reg51.h>

sbit a = P1^5;
sbit b = P3^0;
sbit c = P3^1;

void main()
{
	while(1)
	{
	  if(a==1)
		{
		  b=0;
			c=1;
		}
		else
		{
		  b=1;
			c=0;
		}
	}

}