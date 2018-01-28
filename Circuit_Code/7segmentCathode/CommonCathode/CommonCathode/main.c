/*
 * CommonCathode.c
 *
 * Created: 10/24/2017 2:31:05 PM
 * Author : user-9
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xff;
	DDRB =  0xff;
    /* Replace with your application code */
    while (1) 
    {
		PORTB =  PB1;
		_delay_ms(200);
		PORTB = PB2;
		_delay_ms(200);
		PORTC = 0x6d;
		_delay_ms(200);
    }
}                                                                                                                                                                  

