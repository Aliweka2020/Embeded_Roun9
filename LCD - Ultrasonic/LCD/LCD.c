/*
 * LCD.c
 *
 * Created: 11/21/2024 4:00:22 PM
 *  Author: aweka
 */ 


#include "LCD_lib.h"
#include <util/delay.h>
#include <avr/io.h>
#define  Trigger_pin	PA0	/* Trigger pin */
#include <avr/interrupt.h>
int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}
int main(void)
{
	LCD_init();
	char string[10];
	long count;
	double distance;
	DDRA = 0x01;		/* Make trigger pin as output */
	PORTD = 0xFF;		/* Turn on Pull-up */
	
	sei();			/* Enable global interrupt */
	TIMSK = (1 << TOIE1);	/* Enable Timer1 overflow interrupts */
	TCCR1A = 0;		/* Set all bit to zero Normal operation */
    while(1)
    {
		send_command(0x01);
        SetCursor(0,0);
		LCD_Write_str("Distance = ");
		
		
		PORTA |= (1 << Trigger_pin);
		_delay_us(10);
		PORTA &= (~(1 << Trigger_pin));
		
		TCNT1 = 0;	/* Clear Timer counter */
		TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/
		TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
		TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */

		/*Calculate width of Echo by Input Capture (ICP) */
		
		while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
		TCNT1 = 0;	/* Clear Timer counter */
		TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
		TIFR = 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
		TIFR = 1<<TOV1;	/* Clear Timer Overflow flag */
		TimerOverflow = 0;/* Clear Timer overflow count */

		while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
		count = (ICR1 + (65535 * TimerOverflow));	/* Take count */
		/* 8MHz Timer freq, sound speed =343 m/s */
		distance = (double)count / 466.47;
		
		SetCursor(1,1);
		LCD_Write_str(string);	/* Print distance */
		_delay_ms(500);
		
        //LCD_Write_char('A');
		//LCD_Write_char('l');
    }
}