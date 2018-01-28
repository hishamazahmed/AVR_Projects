/*
 * 7Segmenttwotransistors.cpp
 *
 * Created: 10/24/2017 1:50:53 PM
 * Author : real
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


/* Replace with your library code */
int main(void)
{while(1)
	{	DDRC=0xFF;
		DDRB=0b00000011;
		char ARR[]={0x3f,0x06,0x5b,0x4f, 0x66,0x6d, 0x7d,0x07,0xff,0x6f};
		for(int i=0; i<=9; i++)
			{	PORTB= 0x00;
			
			for(int j=0; j<=9;j++)
				{
					PORTB=0b00000001;
					PORTC = ARR [i];
					_delay_ms(100);
					
					PORTB = 0b00000010;
					PORTC = ARR[j];
					_delay_ms(100);
				}
		}
				
	}
	return 0;
}

