// monitor P3.5 if 1 display your name else display your sir name.


#include <reg51.h>

sbit rs=P0^1;
sbit rw=P0^2;
sbit en=P0^3;

sbit a=P1^1;

char text1[]="Somen";
char text2[]="Das";

char cmd1[]={0x38,0x0E,0x01,0x06,0x80};
char cmd2[]={0x38,0x0E,0x01,0x06,0xC0};

int i,j,k;


void delay()  // 500msec delay function
{
  TMOD=0x02;
	for(i=0;i<1800;i++)
	{
	  TH0=0;
		TR0=1;
		while(TF0==0);
		TF0=0;
	}
}

void my_command()
{
  rs=0;
	rw=0;
	en=0;
	delay();
	en=1;
}

void my_data()
{
  rs=1;
	rw=0;
	en=0;
	delay();
	en=1;
}

void main()
{
  if(a==1)
	{
	  for(j=0;j<sizeof cmd1;j++)
		{
		  P2=cmd1[j];
			my_command();
		}
		
		for(k=0;k<sizeof text1;k++)
		{
		  P2=text1[j];
			my_data();
		}
		
		
	}
	else
	{
	  for(j=0;j<sizeof cmd2;j++)
		  {
		    P2=cmd2[j];
			  my_command();
		  }
		
		for(k=0;k<sizeof text2;k++)
		  {
		    P2=text2[j];
		  	my_data();
		  }
	
	}
}