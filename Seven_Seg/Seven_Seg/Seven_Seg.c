/*
 * Seven_Seg.c
 *
 * Created: 11/9/2024 10:44:10 AM
 *  Author: aweka
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
	DDRB = 0xFF;
	int nums[] = {0b01000000,0b01111001,0b00100100};
    while(1)
    {
        //for (int i =0 ; i<3; i++)
        //{
			//PORTB = nums[i];
			//_delay_ms(1000);
        //}
		for (int i =0 ; i<10; i++)
		{
			PORTB = i;
			_delay_ms(1000);
		}
    }
}