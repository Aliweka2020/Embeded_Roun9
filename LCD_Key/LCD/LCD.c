/*
 * LCD.c
 *
 * Created: 11/21/2024 4:00:22 PM
 *  Author: aweka
 */ 

#define F_CPU 8000000UL
#include "LCD_lib.h"
#include <util/delay.h>
#include "Keypad.h"
//#include "LED.h"

int main(void)
{
	//LED led1 = {B,P2};
	//lED_inti(&led1);
	LCD_init();
	Keypad_init();
	int c = 0;
    while(1)
    {
		
		SetCursor(0,0);
		LCD_Write_str("Enter password");
		unsigned char x =  Get_Key_Pressed();
		SetCursor(1,c);
		LCD_Write_char(x);
		_delay_ms(200);
		c++;
		if (c>15)
		c=0;
		//LED_ON(&led1);
		///_delay_ms(1000);
		//LED_OFF(&led1);
		//_delay_ms(1000);
       // SetCursor(0,0);
        //LCD_Write_char('A');
		//LCD_Write_char('l');
    }
}