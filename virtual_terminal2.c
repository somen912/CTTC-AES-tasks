// Receive a character on virtual terminal 
// if 'a' ADD values of P1 and P2 , similarly for 's' SUB, 'm' MUL, 'd' DIV else 'error'
// show result on P0


#include <reg51.h>

int i,y;

char arr[14]="syntax error";

void main()
{
  P1= 0x05;
	P2= 0x04;
	
	SCON=0x50;
	TMOD= 0x20;
	TH1=0xFD;
	TR1=1;
	
	while(RI==0);
	y=SBUF;
	RI=0;
	
	if(y=='a')
	{
	 P0=P1+P2; 
	}
	else if(y=='s')
	{
	 P0=P1-P2;
	}
	else if(y=='m')
	{
	 P0=P1*P2;
	}
	else if(y=='d')
	{
	 P0=P1/P2;
	}
	else
	{
	  for(i=0;i<14;i++)
		{
		  SBUF=arr[i];
			while(TI==0);
			TI=0;
		}
	}
}