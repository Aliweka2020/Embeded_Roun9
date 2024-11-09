/*
 * GccApplication1.c
 *
 * Created: 11/5/2024 4:05:49 PM
 *  Author: aweka
 */ 

#define F_CPU 8000000UL
#include "DIO.h"
#define LED 21
#define Button 18

int main(void)
{
	//DDRB |= (1<<LED);
	pinMode(LED,OUTPUT);
	//DDRD &= ~(1<<Button);
	pinMode(Button,INPUT);
    while(1)
    {
        if(digitalRead(Button) ==HIGH)
		{
			//PORTB |= (1<<LED);
			digitalWrite(LED,HIGH);
		}
		else
		{
			//PORTB &= ~(1<<LED);
			digitalWrite(LED,LOW);
		}
    }
}