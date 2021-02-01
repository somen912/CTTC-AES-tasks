// create password login in virtual terminal

#include <reg51.h>

char pw[]="123456";
int pwsize[6];
char a[]="Enter password";
char b[]="Correct";
char c[]="denied";
unsigned int x,y,z,p,q,flag;


void main()
{
   SCON = 0x50;
	 TMOD = 0x20;
	 TH1=0xFD;
	 TR1=1;
	
	for(y=0;y<14;y++)
	{
	  SBUF=a[y];
		while(TI==0);
		TI=0;
	}
	
	
	SBUF=0x0D;
	while(TI==0);
	TI=0;
	
	for(x=0;x<6;x++)
	{
	  while(RI==0);
		pwsize[x]=SBUF;
		RI=0;
		
		SBUF=x;
		while(TI==0);
		TI=0;
	}
	
	SBUF=0x0D;
	while(TI==0);
	TI=0;
	
	for(z=0;z<6;z++)
	{
	  if(pw[z]==pwsize[z])
		{
		  flag++;
		}
	}
	
	if(flag==6)
	{
	  flag=0;
		for(p=0;p<sizeof b;p++)
		{
		  SBUF=b[p];
			while(TI==0);
			TI=0;
		}
	}
		else 
		{
		  flag=0;
			for(q=0;q<sizeof c; q++)
			{
			  SBUF=c[q];
				while(TI==0);
				TI=0;
			}
		}
		
	SBUF=0x0D;
	while(TI==0);
	TI=0;
	}
