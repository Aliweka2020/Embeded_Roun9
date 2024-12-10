/*
 * Seven_Seg.c
 *
 * Created: 11/9/2024 10:44:10 AM
 *  Author: aweka
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
int i ;
ISR(TIMER0_OVF_vect)
{
	 Seg_print99(i);
}
void Seg_print99(int num)
{
	PORTB |= (1<<4);
	PORTB &=~(1<<5);
	
	PORTB = (PORTB & 0xF0) | (num%10);
	_delay_ms(10);
	PORTB |= (1<<5);
	PORTB &=~(1<<4);
	PORTB = (PORTB & 0xF0) | (num/10);
	_delay_ms(10);
}
int main(void)
{
	TCCR0 |= (1<<CS00) | (1<<CS02) ; //Normal Mode 1024 prescalar
	TIMSK |=(1<<TOIE0);  //enable interrupt when overflow occur
	TCNT0 = 0;
	sei();
	
	
	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRC = 0xFF;
	int nums[] = {0b01000000,0b01111001,0b00100100};
    while(1)
    {
		
		
		for ( i =0 ; i<100; i ++)
		{
			//Seg_print99 (i);
			_delay_ms(1000);
		}
		
		
		//count 0-99
        //for (int j=0;j<3;j++)
		//{
			//PORTB = (PORTB & 0x00) | (j<<4);
		//
			//for (int i =0 ; i<3; i++)
			//{
				//PORTB = (PORTB & 0xF0) | i ;
				//_delay_ms(1000);
			//}
		//}
		//PORTD =0xFF;
			//PORTD &=~ (1<<0);
			//_delay_ms(50); 
			//PORTD &=~ (1<<1);
			//_delay_ms(50); 
			//PORTD &=~ (1<<2);
			//_delay_ms(50); 
			//PORTD &=~ (1<<3);
			//_delay_ms(50); 
			//PORTD &=~ (1<<4);
			//_delay_ms(50); 
			//PORTD &=~ (1<<5);			
			//
			//_delay_ms(1000);
			//PORTD =0xFF;
			//
			//PORTD &=~ (1<<1);
			//_delay_ms(300);
			//PORTD &=~ (1<<2);
			//
			//
			//_delay_ms(1000);
			//
		//PORTD =0xFF;
		//
		//
		//PORTD &=~ (1<<0);
		//_delay_ms(50);
		//PORTD &=~ (1<<1);
		//_delay_ms(50);
		//PORTD &=~ (1<<3);
		//_delay_ms(50);
		//PORTD &=~ (1<<4);
		//_delay_ms(50);
		//PORTD &=~ (1<<6);
		//_delay_ms(50);
		//
		//
		//_delay_ms(1000);
		
		//for (int i =0 ; i<10; i++)
		//{
			//PORTB = i;
			//_delay_ms(1000);
		//}
    }
}