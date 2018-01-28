/*
 * Two_Microcontroller_1.c
 *
 * Created: 11/9/2017 1:31:51 PM
 * Author : user-9
 */ 


/*#define F_CPU 16000000UL
#define USART_BAUDRATE 19200
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>


void USARTInit(uint16_t ubrr_value)
{

   UBRR0L = ubrr_value;
   UBRR0H = (ubrr_value>>8);
   UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00); // charcater size
   //UCSR0B=(1<<RXEN0)|(1<<TXEN0); //Transfer enable 
   UCSR0B = (1 << TXEN0)| (1 << TXCIE0) | (1 << RXEN0) | (1 << RXCIE0);
}
char USARTReadChar()
{
	while(!(UCSR0A & (1<<RXC0)))
	{
		//Do nothing
	}
	return UDR0;
}

void USARTWriteChar(char data)
{
	while(!(UCSR0A & (1<<UDRE0)))
	{
		//Do nothing
	}
	UDR0=data;
}
int main(void)
{
   char data;
   for(data = 1; data<=100; data++)
   {
	   
   }
   USARTInit(51);    //UBRR = 51
   while(1)
   {
      USARTWriteChar(data);
   }
}*/
//---------------------------------------------------------------


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000
#define BUAD 19200
#define BUAD_RATE_CALC ((F_CPU/16/BUAD) - 1)

int main(void){
    
    //High and low bits
    UBRR0H = (BUAD_RATE_CALC >> 8);
    UBRR0L = BUAD_RATE_CALC;
    ////////////////
    //transimit and recieve enable
    UCSR0B = (1 << TXEN0)| (1 << TXCIE0) | (1 << RXEN0) | (1 << RXCIE0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);  //8 bit data format
    ////////////////////////////////////////////////////////////////
    int i = 0;
    int counter = 0;
    DDRC = 0xff;
    while (1)
	{
        send_usart(counter);
        rcv_usart();
        counter++;
        _delay_ms(1000);
        if(counter == 100)
		{
            return 0;
		} 
    }
}

void send_usart( unsigned char data )
{
    while (( UCSR0A & (1<<UDRE0))  == 0){};
    UDR0 = data;
}

void rcv_usart()
{
    while (!(UCSR0A & (1<<RXC0)) ){};
    PORTC = UDR0;
}