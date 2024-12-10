/*
 * ADC.c
 *
 * Created: 8/27/2024 5:49:34 PM
 *  Author: aweka
 */ 

#include "ADC.h"
#include <avr/io.h>
void ADC_init()
{
	
	ADCSRA |= (1<<ADEN) | (1<<ADPS0) | (1<<ADPS2);
}
int ADC_Read(int ch)
{
	DDRA &= ~(1<<ch);
	ADMUX =  ch;
	ADMUX |= (1<<ADLAR);
	
	ADCSRA |= (1<<ADSC);
	while ( (ADCSRA & (1<<ADIF) ) ==0);
	ADCSRA |= (1<<ADIF);
	return ((int) (ADCH));
}