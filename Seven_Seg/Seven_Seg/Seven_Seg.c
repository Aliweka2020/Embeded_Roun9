/*
 * Seven_Seg.c
 *
 * Created: 11/9/2024 10:44:10 AM
 *  Author: aweka
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void Seg_print99(int num)
{
	PORTB |= (1<<4);
	PORTB &=~(1<<5);
	
	PORTB = (PORTB & 0xF0) | (num%10);
	_delay_ms(50);
	PORTB |= (1<<5);
	PORTB &=~(1<<4);
	PORTB = (PORTB & 0xF0) | (num/10);
	_delay_ms(50);
}
int main(void)
{
	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRC = 0xFF;
	int nums[] = {0b01000000,0b01111001,0b00100100};
    while(1)
    {
		
		
		for (int i =0 ; i<100; i ++)
		{
			Seg_print99 (i);
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