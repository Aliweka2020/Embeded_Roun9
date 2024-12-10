
/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

#ifndef LCD_H_
#define LCD_H_
typedef unsigned char u8;
#define FOUR 0
#define EIGHT 1
#define TYPE EIGHT
#if TYPE == EIGHT 
	#define LCD_Dir_data DDRB
	#define LCD_Port_data PORTB

	#define LCD_Dir_control DDRC
	#define LCD_Port_control PORTC

	#define RS 0
	#define EN 2		
#endif

#if TYPE == FOUR
#define LCD_Dir_data DDRA
#define LCD_Port_data PORTA

#define RS 1
#define RW 2
#define EN 3
#endif
/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void);

/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(u8 u8CmdCpy);

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(u8 u8DataCpy);

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index);


void Gotoxy (u8 Y,u8 X);
void LCD_vidWriteExtraChar (u8 Y,u8 X);

#endif /* LCD_H_ */
