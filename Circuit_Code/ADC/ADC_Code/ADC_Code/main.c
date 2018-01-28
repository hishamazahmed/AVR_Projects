/*
 * ADC_Code.c
 *
 * Created: 11/15/2017 12:10:41 PM
 * Author : Nu
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


#define BAUDRATE 115200
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

void init_uart(uint16_t uVal){
	  UBRR0H = (uVal >> 8);
	  UBRR0L = uVal;
	  ////////////////
	  //transimit and recieve enable
	  UCSR0B = (1 << TXEN0)| (1 << RXEN0);
	  UCSR0A = (1 << UDRE0);
	  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  //8 bit data format
}

void adc_init()
{
	ADMUX = (1<<REFS0);
	// ADC Enable and prescaler of 128
	// 16000000/128 = 125000
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

uint16_t adc_read(uint8_t ch)
{

	ADMUX &= 0xF0; // Clear the older channel that was read
	ADMUX |= ch;
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	return ADC;
}

int main(void)
{
	DDRB = 0xFF; 
	init_uart(BAUD_PRESCALLER);
	uint16_t adc_value;
	adc_init();
	
    /* Replace with your application code */
    while (1) 
    {
		adc_value = adc_read(0);
		UDR0 = adc_value;
		
		if(adc_value>=512){
			PORTB |= (1<<PORTB0);
		}
		else{
			PORTB &= ~(1<<PORTB0);
		}
		_delay_ms(1000);
    }
}

