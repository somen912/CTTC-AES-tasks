// control direction of the rotation of DC motor by a switch

#include <reg51.h>

sbit forward_button = P1^0;
sbit backward_button = P1^1;
sbit right_button = P1^2;
sbit left_button = P1^3;

sbit a_pin1 = P0^0;
sbit a_pin2 = P0^1;

sbit b_pin1 = P0^2;
sbit b_pin2 = P0^3;

sbit c_pin1 = P0^4;
sbit c_pin2 = P0^5;

sbit d_pin1 = P0^6;
sbit d_pin2 = P0^7;

void move_forward()
{
  a_pin1=1;
	a_pin2=0;
	
	b_pin1=1;
	b_pin2=0;
	
	c_pin1=1;
	c_pin2=0;
	
	d_pin1=1;
	d_pin2=0;
}

void move_backward()
{
  a_pin1=0;
	a_pin2=1;
	
	b_pin1=0;
	b_pin2=1;
	
	c_pin1=0;
	c_pin2=1;
	
	d_pin1=0;
	d_pin2=1;
}

void move_left()
{
  a_pin1=1;
	a_pin2=0;
	
	b_pin1=0;
	b_pin2=1;
	
	c_pin1=0;
	c_pin2=1;
	
	d_pin1=1;
	d_pin2=0;
}

void move_right()
{
  a_pin1=0;
	a_pin2=1;
	
	b_pin1=1;
	b_pin2=0;
	
	c_pin1=1;
	c_pin2=0;
	
	d_pin1=0;
	d_pin2=1;
}

void stop()
{
  a_pin1=0;
	a_pin2=0;
	
	b_pin1=0;
	b_pin2=0;
	
	c_pin1=0;
	c_pin2=0;
	
	d_pin1=0;
	d_pin2=0;

}

void main()
{
	while(1)
	{
	  if(forward_button==0)
		{
		  move_forward();
		}
		else if(backward_button==0)
		{
		  move_backward();
		}
		else if(right_button==0)
		{
		  move_right();
		}
		else if(left_button==0)
		{
		  move_left();
		}
		else
    {
		  stop();
		}
	}

}