/*
 * GccApplication1.c
 *
 * Created: 10/22/2017 9:03:17 PM
 * Author : real
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{	DDRC = 0xFF; // All ones in PORTD 
	int i;
	while(1)
	{	for (i=0; i < 8; i++)
		PORTD |=(1<<i);
		_delay_ms (500);
		PORTD &=~ (0<<i);
		_delay_ms (500);
	}
}
