/*
 * AVR_LED_8_Blinking.c
 *
 * Created: 23-Oct-17 7:22:30 AM
 * Author : Hisham
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{  
	 DDRC = 0xff;
	 int a=0;
	/* Replace with your application code */
	while (1)
	{
		
		for(int i=0;i<=9;i++)
		{
			
			_delay_ms(20);
			for(int k=0;k<=9;k++)
				{
					
					PORTC = k|a;
				  _delay_ms(50);
			  
			   }
			
			a=a+0b00010000;
			PORTC=a|0;
		}
		a=0;
		PORTC=0;
		
	 }
		
	
	

	return 0;
}
