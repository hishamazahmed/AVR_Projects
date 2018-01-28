/*
 * H_Bridge_Transistor.c
 *
 * Created: 11/16/2017 3:34:48 PM
 * Author : Nu
 */ 

#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

int main(void)
{
	DDRB=0xFF;     // PORTD declared as input port
	while(1)
	{
		PORTB = 0b00000001;
		_delay_ms(1000);   
		
		PORTB = 0b00000010;
		_delay_ms(1000);   
	}			
}  			
