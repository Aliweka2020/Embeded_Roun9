/*
 * Keypad.c
 *
 * Created: 8/20/2024 4:34:35 PM
 *  Author: aweka
 */ 
#include "Keypad.h"
#include <avr/io.h>
#include <util/delay.h>
unsigned chars [4][4]=
{
	{'1' ,'2','3','%'},
	{'4' ,'5','6','x'},
	{'7' ,'8','9','-'},
	{' ' ,'0','=','+'}
} ;
void Keypad_init()
{
	DDRC = 0x0F;
	PORTC = 0XFF;
}
unsigned char Get_Key_Pressed()
{
	unsigned return_key;
	while (1)
	{
		for(int col=0;col<4;col++)
		{
			PORTC &= ~(1<<col);
			_delay_ms(1);
			for(int row=4;row<8;row++)
			{
				if ( ((PINC & (1<<row)) >> row) == 0 )
				{
					return_key = chars[col][row-4];
					PORTC |=(1<<col);
					PORTB |=(1<<2);
					_delay_ms(50);
					PORTB &=~(1<<2);
					return return_key;
				}
			}
			PORTC |=(1<<col);
			_delay_ms(1);
		}
	}
}