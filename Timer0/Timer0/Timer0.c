/*
 * Timer0.c
 *
 * Created: 11/30/2024 10:18:54 AM
 *  Author: aweka
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int counter =0;
ISR(TIMER0_OVF_vect)
{
	counter ++;
	if(counter ==8)
	{
		PORTB ^=(1<<0);
		counter =0;
	}
}

int main(void)
{
	DDRB |= (1<<3);
	//DDRD |= (1<<2);
	
	//TCCR0 |= (1<<CS00) | (1<<CS02) ; //Normal Mode 1024 prescalar
	//TIMSK |=(1<<TOIE0);  //enable interrupt when overflow occur
	//TCNT0 = 0;
	//sei();
	
	//// CTC code
	//DDRB |=(1<<3);
	//TCCR0 |= (1<<WGM01) | (1<<CS02) | (1<<CS00) | (1<<COM00);
	//OCR0 = 250;
	
	
	// Fast PWM
	
	TCCR0 |= (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00) | (1<<CS02);
	
    while(1)
    {
		 for(int i =0; i<255; i++)
		 {
			 OCR0 = i;
			 _delay_ms(1);
		 }
		 
    }
}