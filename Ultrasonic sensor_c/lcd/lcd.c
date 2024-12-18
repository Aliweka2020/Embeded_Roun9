/*
 * lcd.c
 *
 * Created: 9/3/2022 4:45:30 PM
 *  Author: Ali
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LCD_interface.h"
#define  Trigger_pin	PA0	/* Trigger pin */

int TimerOverflow = 0;

ISR(TIMER1_OVF_vect)
{
	TimerOverflow++;	/* Increment Timer Overflow count */
}

int main(void)
{
	LCD_vidInit();
	
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
		LCD_vidSendCommand(0x01);
		Gotoxy(0,0);
		LCD_vidWriteString("Ultrasonic",10);
		
        /////* Give 10us trigger pulse on trig. pin to HC-SR04 */
        //PORTA |= (1 << Trigger_pin);
        //_delay_us(10);
        //PORTA &= (~(1 << Trigger_pin));
        //
        //TCNT1 = 0;	/* Clear Timer counter */
        //TCCR1B = 0x41;	/* Capture on rising edge, No prescaler*/
        //TIFR |= 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
        //TIFR |= 1<<TOV1;	/* Clear Timer Overflow flag */
//
        ///*Calculate width of Echo by Input Capture (ICP) */
        //
        //while ((TIFR & (1 << ICF1)) == 0);/* Wait for rising edge */
        //TCNT1 = 0;	/* Clear Timer counter */
        //TCCR1B = 0x01;	/* Capture on falling edge, No prescaler */
        //TIFR |= 1<<ICF1;	/* Clear ICP flag (Input Capture flag) */
        //TIFR |= 1<<TOV1;	/* Clear Timer Overflow flag */
        //TimerOverflow = 0;/* Clear Timer overflow count */
//
        //while ((TIFR & (1 << ICF1)) == 0);/* Wait for falling edge */
        //count = (ICR1 + (65535 * TimerOverflow));	/* Take count */
        ///* 8MHz Timer freq, sound speed =343 m/s */
        //distance = (double)count / 466.47;
//
        //dtostrf(distance, 2, 2, string);/* distance to string */
        //strcat(string, " cm   ");	/* Concat unit i.e.cm */
		//LCD_vidSendCommand(0x01);
		//Gotoxy(0,0);
		//LCD_vidWriteString("Ultrasonic",10);
		//Gotoxy(1,1);
        //LCD_vidWriteString(string,12);	/* Print distance */
        //_delay_ms(200);
		
    }
}
