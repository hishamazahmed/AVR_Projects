#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#define BAUDRATE 19200
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)
#define VREF 5
#define POT 10000

//Declaration of our functions
uint16_t adc_value;
void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);
void USART_putstring(char* StringPtr);
void USART_putInt(int number);

void InitADC()
{
	// Select Vref=AVcc
	ADMUX |= (1<<REFS0);
	//set prescaller to 128 and enable ADC
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
}
uint16_t ReadADC(uint8_t ADCchannel)
{
	//select ADC channel with safety mask
	ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);
	//single conversion mode
	ADCSRA |= (1<<ADSC);
	// wait until ADC conversion is complete
	while( ADCSRA & (1<<ADSC) );
	return ADC;
}
int main(void){
	USART_init();        //Call the USART initialization code
	InitADC();
	DDRB = 0x01;
	while(1)
	{
		
		adc_value = ReadADC(0);
		char buffer[4];
		utoa(adc_value, buffer, 10);
		USART_putstring(buffer);
		_delay_ms(100);
		
		if (ReadADC(0) > 512)
		{
			PORTB |= (1<<PB0);
			_delay_ms(100);
		}
		else
		{
			PORTB &=~ (1<<PB0);
			_delay_ms(100);
		}
	}
	return 0;
}


void USART_init(void)
{
	
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
}

unsigned char USART_receive(void)
{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void USART_send( unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
	
}

void USART_putInt(int number)
{
	char buffer [sizeof(unsigned int)*8+1];
	utoa (number,buffer,10);
	USART_putstring(buffer);
}

void USART_putstring(char* StringPtr)
{
	
	while(*StringPtr != 0x00){
		USART_send(*StringPtr);
	StringPtr++;}
	USART_send('\r');
	
}

