/*
 * LED.c
 *
 * Created: 11/26/2024 3:53:33 PM
 *  Author: aweka
 */ 
#include "LED.h"
#include <avr/io.h>

void lED_inti(LED *l)
{
	switch (l->p)
	{
		case A:
		
		break;
		case B:
		DDRB |= (1<<l->pi);
		break;
	}
}
void LED_ON(LED *l)
{
	switch (l->p)
	{
		case A:
		
		break;
		case B:
		PORTB |= (1<<l->pi);
		break;
	}
}
void LED_OFF(LED *l)
{
	switch (l->p)
	{
		case A:
		
		break;
		case B:
		PORTB &= ~(1<<l->pi);
		break;
	}
}