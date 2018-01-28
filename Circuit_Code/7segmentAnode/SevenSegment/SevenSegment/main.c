/*
 * SevenSegment.c
 *
 * Created: 10/24/2017 10:11:35 AM
 * Author : user-9
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	int i, j;
	DDRC = 0xff;
	DDRD = 0xff;
    /* Replace with your application code */
    while (1) 
    {
		for(i=0; i<=9; i++){
			PORTC = i;
			_delay_ms(100);
			for(j=0; j<=9; j++){
				PORTD = j;
				_delay_ms(100);
			}
		}
    }
}

