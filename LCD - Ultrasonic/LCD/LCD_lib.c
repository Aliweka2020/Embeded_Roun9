/*
 * LCD_lib.c
 *
 * Created: 11/21/2024 4:01:11 PM
 *  Author: aweka
 */
#define F_CPU 8000000UL 
#include "LCD_lib.h"
#include <avr/io.h>
#include <util/delay.h>
void LCD_init()
{
	_delay_ms(35);
	if(MODE == Eight_bit)
	{
		switch(Data_port)
		{
			case D:
			DDRD =  0xFF;
			break;
			case C:
			DDRC =  0xFF;
			break;
		}
		switch(Control_port)
		{
			case C:
			DDRC |=  (1<<RS) |(1<<E);
			break;
			case B:
			DDRB |=  (1<<RS) |(1<<E);
			break;
		}
	}
	send_command(FSet8b2L7);
	_delay_ms(1);
	send_command(ON_OFFCNoB);
	_delay_ms(1);
	send_command(Clear);
	_delay_ms(2);
	send_command(EntryINCNOSH);
	
}
void send_command(unsigned char cmd)
{
	if(MODE == Eight_bit)
	{
		switch(Data_port)
		{
			case D:
			switch(Control_port)
			{
				case C:
				PORTC &= ~(1<<RS);
				PORTD =  cmd;
				PORTC |=(1<<E);
				_delay_us(250);
				PORTC &=~(1<<E);
				_delay_us(250);
				break;
			}
			break;
			case C:
			switch(Control_port)
			{
				case B:
				PORTB &= ~(1<<RS);
				PORTC =  cmd;
				PORTB |=(1<<E);
				_delay_us(250);
				PORTB &=~(1<<E);
				_delay_us(250);
				break;
			}
			break;
		}
		
	}
}


void SetCursor(int row, int col)
{
	switch (row)
	{
		case 0:
		send_command(0x80 +col);
		break;
		case 1:
		send_command(0xc0 +col);
		break;
	}
}
void LCD_Write_char(unsigned char x)
{
	if(MODE == Eight_bit)
	{
		switch(Data_port)
		{
			case D:
			switch(Control_port)
			{
				case C:
				PORTC |= (1<<RS);
				PORTD =  x;
				PORTC |=(1<<E);
				_delay_us(250);
				PORTC &=~(1<<E);
				_delay_us(250);
				break;
			}
			break;
			case C:
			switch(Control_port)
			{
				case B:
				PORTB |= (1<<RS);
				PORTC =  x;
				PORTB |=(1<<E);
				_delay_us(250);
				PORTB &=~(1<<E);
				_delay_us(250);
				break;
			}
			break;
		}
		
	}
}
void LCD_Write_str(unsigned char *s)
{
	while(*s != '\0')
	{
		LCD_Write_char(*s);
		s++;
	}
}