
/***************************************************************************************/
#ifndef _DIO_REG_H
#define _DIO_REG_H

///* Group A Registers */
//#define PORTA_Register  *((volatile u8*)0x3B)
//#define DDRA_Register   *((volatile u8*)0x3A)
//#define PINA_Register   *((volatile u8*)0x39)
//
///* Group B Registers */
//#define PORTB_Register  *((volatile u8*)0x38)
//#define DDRB_Register   *((volatile u8*)0x37)
//#define PINB_Register   *((volatile u8*)0x36)
//
///* Group C Registers */
//#define PORTC_Register  *((volatile u8*)0x35)
//#define DDRC_Register   *((volatile u8*)0x34)
//#define PINC_Register   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD_Register  *((volatile unsigned char*)0x32)
#define DDRD_Register   *((volatile unsigned char*)0x31)
#define PIND_Register   *((volatile unsigned char*)0x30)

#define PORTA  *((volatile unsigned char*)0x32)
#define DDRA_Register   *((volatile unsigned char*)0x31)
#define PINA_Register   *((volatile unsigned char*)0x30)


#endif
