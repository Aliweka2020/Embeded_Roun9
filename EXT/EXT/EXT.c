/*
 * EXT.c
 *
 * Created: 11/28/2024 1:45:06 PM
 *  Author: aweka
 */ 
#define F_CPU 8000000UL 
#include <avr/io.h>
#include "LED.h"
#include <util/delay.h>
#include <avr/interrupt.h>
LED l1 = {B,P0};
ISR(INT0_vect)
{
	LED_OFF(&l1);
}
int main(void)
{
	
	lED_inti(&l1);
	DDRD &=~(1<<2);
	GICR |= (1<<INT0);
	MCUCR |=  (1<<ISC01);
	sei();
	//SREG |=(1<<7);
    while(1)
    {
		LED_ON(&l1);
		_delay_ms(2000);
		LED_OFF(&l1);
		_delay_ms(2000);
		
    }
}