#define F_CPU 8000000UL//

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
char dis [] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};
DDRD = 0xFF;
DDRB = 0xFF;
	        while (1) 
    {		
		for (int k=0;k<=9;k++)
		{
			PORTD= dis[0];
			PORTB= dis[k];
			int i=0;
			for (i=0;i<=9;i++)
			{
				PORTD = dis[i];
				_delay_ms(500);
						
			}
			
			
		}	
		
    }
}

