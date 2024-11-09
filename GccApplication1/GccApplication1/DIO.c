/*
 * DIO.c
 *
 * Created: 11/9/2024 10:01:33 AM
 *  Author: aweka
 */ 
#include <avr/io.h>
#include "DIO.h"
void pinMode(unsigned char pin , unsigned char dir)
{
	if (pin >0 && pin <9)
	{
		if (dir == OUTPUT)
		DDRB |=(1<<(pin-PORTB_Start));
		else if (dir == INPUT)
		DDRB &=~(1<<(pin-PORTB_Start));
	}
	else if (pin >13 && pin <22)
	{
		if (dir == OUTPUT)
		DDRD |=(1<<(pin-PORTD_Start));
		else if (dir == INPUT)
		DDRD &=~(1<<(pin-PORTD_Start));
	}
}
void digitalWrite(unsigned char pin, unsigned char val)
{
	if (pin >0 && pin <9)
	{
		if (val == HIGH)
		PORTB |=(1<<(pin-PORTB_Start));
		else if(val == LOW)
		PORTB &=~(1<<(pin-PORTB_Start));
	}
	else if (pin >13 && pin <22)
	{
		if (val == HIGH)
		PORTD |=(1<<(pin-PORTD_Start));
		else if(val == LOW)
		PORTD &=~(1<<(pin-PORTD_Start));
	}
}
unsigned char digitalRead(unsigned char pin)
{
	if (pin >0 && pin <9)
	{
		return ((PINB&(1<<(pin-PORTB_Start) )>> (pin-PORTB_Start)));
	}
	else if (pin >13 && pin <22)
	{
		return ((PIND&(1<<(pin-PORTD_Start) ))>> ((pin-PORTD_Start)));
	}
}
