/*
 * Keypad.h
 *
 * Created: 8/20/2024 4:34:52 PM
 *  Author: aweka
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define KEYPAD_PORT DDRC
void Keypad_init();
unsigned char Get_Key_Pressed();


#endif /* KEYPAD_H_ */