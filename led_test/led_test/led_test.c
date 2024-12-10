/*
 * led_test.c
 *
 * Created: 12/5/2024 4:48:11 PM
 *  Author: aweka
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC |=(1<<0);
	
    while(1)
    {
    PORTC ^=(1<<0);
	_delay_ms(1000); 
    }
}