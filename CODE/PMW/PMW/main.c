/*
 * PMW.c
 *
 * Created: 09-07-2024 09:55:06
 * Author : SRIDHAR
 */ 

#define F_CPU 1000000UL
#include "avr/io.h"
#include <util/delay.h>

void PWM_init()
{
	/*set fast PWM mode with non-inverted output and clear OC2 on compare match*/
	TCCR2 = (1<<WGM20) | (1<<WGM21) | (1<<COM21) | (1<<CS20) | (0<<CS21) | (0<<CS22);
	DDRD|=(1<<PB7);  /*set OC2 pin as output*/
}

int main ()
{
	unsigned char duty;
	
	PWM_init();

	while (1)
	{
		for(duty=0; duty<255; duty++)
		{
			OCR2=duty;  /*increase the LED light intensity*/
			_delay_ms(10);
		}
		for(duty=255; duty>1; duty--)
		{
			OCR2=duty;  /*decrease the LED light intensity*/
			_delay_ms(10);
		}
	}
}