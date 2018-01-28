#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
   DDRC= (1<<PC0) | (1<<PC1);
   
    while (1) 
    {
		PORTC |= (1 << PC0);
		_delay_ms(2000);
		PORTC &= ~(1 << PC0);
		_delay_ms(100);
		PORTC |= (1 << PC1);
		_delay_ms(2000);
		PORTC &= ~(1 << PC1);
		_delay_ms(100);
	}
}

