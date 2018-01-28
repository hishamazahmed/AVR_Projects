/*
 * L293D_Motor_Code.c
 *
 * Created: 11/19/2017 12:32:34 PM
 * Author : Nu
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0xFF; 
	DDRC = 0x00;
    while (1) 
    {
		uint8_t val ;
		val = PINC & (1<<PC0);
		
		if(val == 1 ){
			PORTB = (1<<PORTB0);
			_delay_ms(50);
			PORTB  = (1<<PORTB1);
			_delay_ms(50);
		}
		else if(val == 0){
			PORTB = ~(1<<PORTB0);
			PORTB  = ~(1<<PORTB1);
		}
    }
}

