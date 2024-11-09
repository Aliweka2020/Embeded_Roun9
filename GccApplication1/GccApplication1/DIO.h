/*
 * DIO.h
 *
 * Created: 11/9/2024 10:01:52 AM
 *  Author: aweka
 */ 


#ifndef DIO_H_
#define DIO_H_

#define  OUTPUT 0
#define  INPUT  1
#define  LOW 0
#define  HIGH  1
#define PORTB_Start 1
#define PORTD_Start 14

unsigned char digitalRead(unsigned char pin);
void digitalWrite(unsigned char pin, unsigned char val);
void pinMode(unsigned char pin , unsigned char dir);



#endif /* DIO_H_ */