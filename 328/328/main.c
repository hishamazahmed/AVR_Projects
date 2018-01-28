/*
 * atmega328p.c
 *
 * Created: 10/29/2017 2:39:00 PM
 * Author : user-6
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL//
#include <avr/interrupt.h>


int timevariable=0;
ISR(TIMER0_OVF_vect)
{
	timevariable++;
	if (timevariable >=115)
	{
		timevariable=0;
		PORTB ^= (1<<PORTB5);
	}
}

int main(void)
{   
	DDRB=0xFF;
	TCCR0B |= (1<<CS00);
	TIFR0=1<<TOV0;
	TIMSK0=1<<TOIE0;
	
	sei();
  
    while (1) 
    {
		
    }
}

