/*
 * InterruptPractive_2_utube.c
 *
 * Created: 10/26/2017 12:41:05 AM
 * Author : real
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>



int main(void)
{
	DDRB = 0x01;
	TCCR1B = ( 1<< WGM12);
	OCR1A =19531;
	TIMSK1 = (1 << OCIE1A);
	
	sei();
	 
	 TCCR1B |= (1<<CS12) | (1<<CS10);
	 
    while (1) 
    {
    }
}
	ISR(TIMER1_COMPA_vect)
	{
		PORTB ^= (1 << PORTB0);
	}


