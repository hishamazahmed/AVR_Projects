/*
 * 7segmentusinginterrput.c
 *
 * Created: 10/25/2017 3:47:06 PM
 * Author : real
 */ 

#include F_CPU 16000000UL;
#include <avr/io.h>
#include <in>

int main(void)
{	DDRB = 0x20;
	TCCR0B = (1<<CS02);
	TIFRO = 1<<TOVO;
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

