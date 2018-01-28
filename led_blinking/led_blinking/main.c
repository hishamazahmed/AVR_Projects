/*
 * led_blinking.c
 *
 * Created: 22-Oct-17 10:12:17 PM
 * Author : Shiddiqur R Sumon
 */ 


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

void delay_ms(unsigned int ms)
{
	while (ms)
	{
		_delay_ms(1.000);
		ms--;
	}
}
int main(void)
{
    //DDRD |= (1 << PD0);
    DDRD = 0xff;
   //DDRD=0b11111111;


    //DDRD=0b00000001;
    //DDRD=0x01;
    
    
    while (1) 
    {   

       for (int x=7; x<=0; x--)
       {
	    
	  
		PORTD |=(1<<x);
		delay_ms(1000);
		PORTD &= (0 <<x);
		delay_ms(1000);
	  }
		
       
     }
	return 0;
}




/*

  DDRC &= (0<<PC0);
  DDRD |=(1<<PD0);
  uint8_t inputTemp=0

  while(1)

  {
    inputTemp= PINC & 0x01;                                                                       
    
   if(inputTemp ==0x00)
    {
       PORTD |= (1<<PD0);
    }

   else
    {
    
     PORTD &=~ (1<<PD0);
    }

 

   }

   



*/

