/*
 * LCD.c
 *
 * Created: 11/21/2024 4:00:22 PM
 *  Author: aweka
 */ 


#include "LCD_lib.h"

int main(void)
{
	LCD_init();
	
    while(1)
    {
        SetCursor(0,0);
        LCD_Write_char('A');
		LCD_Write_char('l');
    }
}