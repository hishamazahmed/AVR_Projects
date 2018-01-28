/*
 * timer.c
 *
 * Created: 10/29/2017 2:41:12 PM
 * Author : user-9
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>


volatile uint8_t timeVariable=0;
ISR(TIMER0_OVF_vect){
	timeVariable++;
	if(timeVariable>=1){
		timeVariable = 0 ;
		PORTB ^= (1<<PORTB5);
	}
}

int main(void)
{
	DDRB = 0x20;
	TCCR0B =  (1<<CS00);
	TIFR0 = (1<<TOV0);
	TIMSK0 = (1<<TOIE0);
	sei();
    while (1) 
    {
    }
}

