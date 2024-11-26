/*
 * LCD_lib.h
 *
 * Created: 11/21/2024 4:01:00 PM
 *  Author: aweka
 */ 


#ifndef LCD_LIB_H_
#define LCD_LIB_H_

#define FOUR_Bit  0
#define Eight_bit 1
#define MODE Eight_bit
#define A 0
#define B 1
#define C 2
#define D 3
#define Control_port A
#define Data_port D

#define RS 6
#define E 7 

#define FSet8b2L7		0x38
#define ON_OFFNoCNoB    0x0c
#define ON_OFFCNoB		0x0E
#define ON_OFFCNB		0x0F
#define Clear			0x01
#define EntryINCNOSH	0x06
void LCD_init();
void SetCursor(int row, int col);
void send_command(unsigned char cmd);
void LCD_Write_char(unsigned char x);
void LCD_Write_str(unsigned char *s);



#endif /* LCD_LIB_H_ */