/*
 * 7SegmentDisplay.c
 *
 * Created: 10/23/2017 2:21:34 PM
 * Author : real
 */ 
 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{	
	char seg_code[]={0x3f,0x06,0x5b,0x4f, 0x66,0x6d, 0x7d,0x07,0xff,0x6f};
	DDRD = 0xff;
	DDRB = 0xff;
	
			
	while(1)
	{
		int i = 0; 
		for (i = 0; i<=9; i++)
		{
// 			PORTB = seg_code[i];
// 			_delay_ms(400);
			
			for (int j = 0; j <= 9; j++)
			{
 				PORTB = seg_code[i];
 				_delay_ms(100);
			
				PORTD = seg_code[j];
				_delay_ms(300);
			}
		}
	}
	
		
	return 0;
}


// {			//0
//
// 			PORTD |= (1<<PD0);
// 			PORTD |= (1<<PD1);
// 			PORTD |= (1<<PD2);
// 			PORTD |= (1<<PD4);
// 			PORTD |= (1<<PD3);
// 			PORTD |= (1<<PD5);
// 			_delay_ms(100);
// 			PORTD =0x00;
//
//
// 		//1
// 			PORTD |= (1<<PD1);
// 			PORTD |= (1<<PD2);
// 			_delay_ms(200);
// 			PORTD =0x00;
// 			//2
// 			PORTD |= (1<<PD0);
// 			PORTD |= (1<<PD1);
// 			PORTD |= (1<<PD6);
// 			PORTD |= (1<<PD4);
// 			PORTD |= (1<<PD3);
// 			_delay_ms(100);
// 			PORTD =0x00;
// 			//3
// 			PORTD |= (1<<PD0);
// 			PORTD |= (1<<PD1);
// 			PORTD |= (1<<PD6);
// 			PORTD |= (1<<PD2);
// 			PORTD |= (1<<PD3);
// 			_delay_ms(100);
// 			PORTD =0x00;
// 			//4
// 			PORTD |= (1<<PD1);
// 			PORTD |= (1<<PD5);
// 			PORTD |= (1<<PD6);
// 			PORTD |= (1<<PD2);
// 			PORTD |= (1<<PD3);
// 			_delay_ms(100);
// 			PORTD =0x00;
//
// 			//5
// 			PORTD |= (1<<PD0);
// 			PORTD |= (1<<PD5);
// 			PORTD |= (1<<PD6);
// 			PORTD |= (1<<PD2);
// 			PORTD |= (1<<PD3);
// 			_delay_ms(100);
// 			PORTD =0x00;
//
// 			//6
// 			PORTD |= (1<<PD0);
// 			PORTD |= (1<<PD5);
// 			PORTD |= (1<<PD4);
// 			PORTD |= (1<<PD3);
// 			PORTD |= (1<<PD2);
// 			PORTD |= (1<<PD6);
// 			_delay_ms(100);
// 			PORTD =0x00;
//
// 			//7
// 			PORTD |= (1<<PD0);
// 			PORTD |= (1<<PD1);
// 			PORTD |= (1<<PD2);
//
// 			_delay_ms(100);
// 			PORTD =0x00;
//
// 			//8
//
// 			PORTD |= (1<<PD0);
// 			PORTD |= (1<<PD1);
// 			PORTD |= (1<<PD2);
// 			PORTD |= (1<<PD3);
// 			PORTD |= (1<<PD4);
// 			PORTD |= (1<<PD5);
// 			PORTD |= (1<<PD6);
// 			_delay_ms(100);
// 			PORTD =0x00;
//
// 			//9
// 			PORTD |= (1<<PD0);
// 			PORTD |= (1<<PD1);
// 			PORTD |= (1<<PD2);
// 			PORTD |= (1<<PD3);
// 			PORTD |= (1<<PD5);
// 			PORTD |= (1<<PD6);
// 			_delay_ms(100);
// 			PORTD =0x00;
//
// 		}