
/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

/********************************** Header Files INCLUSIONS ****************************/

#include <util/delay.h>
#include <avr/io.h>

//#include "DIO_reg.h"
#include "LCD_interface.h"

/***************************************************************************************/

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */

/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/

/***************************************************************************************/
/********************************** Macros *********************************************/
/***************************************************************************************/

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_FunctionSet4bit 0x28          // 4-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

/***************************************************************************************/
/********************************** Constant Variables *********************************/
/***************************************************************************************/

const unsigned char  ExtraChar[]=
{
	0x02, 0x00, 0x17, 0x15, 0x1F, 0x00, 0x00, 0x00, //Char0
	0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x0C, 0x18, //Char1
	0x04, 0x0A, 0x00, 0x15, 0x1F, 0x00, 0x00, 0x00, //Char2
	0x06, 0x0E, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, //Char3
	0x00, 0x00, 0x0E, 0x0A, 0x0E, 0x02, 0x04, 0x08, //Char4
	0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x0C, 0x18, //Char5
	0x00, 0x00, 0x04, 0x0A, 0x1B, 0x0A, 0x04, 0x00, //Char6
	0x00, 0x00, 0x07, 0x04, 0x1F, 0x00, 0x00, 0x00, //Char7
};
const unsigned char  ExtraChar2[]=
 {  0x00, 0x00, 0x00, 0x00,0x10, 0x10, 0x1F, 0x00,
	 0x00, 0x00,  0x00,  0x00, 0x00, 0x07, 0x1C, 0x00,
   0x04, 0x04,	0x04,  0x04, 0x04, 0x1F, 0x00, 0x00,
   0x00, 0x00,  0x07,  0x04, 0x04, 0x1F, 0x00, 0x00,
 };

/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void)
{
	/* Delay 30ms to ensure the initialization of the LCD driver */
	#if TYPE == EIGHT
	LCD_Dir_data = 0xFF;
	LCD_Dir_control |=(1<<RS) | (1<<EN);
	#endif
	#ifdef FOUR
	LCD_Dir_data = 0xFF;
	DDRB |=(1<<RS) | (1<<EN) ;
	#endif 
	_delay_ms(30);

	/* Return Home  */
	LCD_vidSendCommand(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	#if TYPE == EIGHT
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	#endif 
	#if TYPE == FOUR
	LCD_vidSendCommand(lcd_FunctionSet4bit);
	#endif
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(2);

}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(unsigned char u8CmdCpy)
{
	#if TYPE == EIGHT
	/* Set RS to LOW */
	LCD_Port_control &=~(1<<RS);

	
	/* Set E to HIGH  */
	LCD_Port_control |= (1<<EN);

	/* Load Command on Data bus */
	LCD_Port_data = u8CmdCpy;

	/* Set E to LOW */
	LCD_Port_control &=~(1<<EN); 

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	//LCD_Port_control |= (1<<EN);

	/* Delay for 10ms to let the LCD execute command */
	//_delay_ms(10);
	#endif 
	
	#if TYPE == FOUR
	LCD_Port_data = (LCD_Port_data & 0x0F) | (u8CmdCpy & 0xF0); /* sending upper nibble */
	PORTB &= ~ (1<<RS);		/* RS=0, command reg. */
	PORTB &= ~ (1<<RW);
	PORTB |= (1<<EN);		/* Enable pulse */
	_delay_us(1);
	PORTB &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port_data = (LCD_Port_data & 0x0F) | (u8CmdCpy << 4);  /* sending lower nibble */
	PORTB |= (1<<EN);
	_delay_us(1);
	PORTB &= ~ (1<<EN);
	_delay_ms(2);
	#endif

}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(unsigned char u8DataCpy)
{
	#if TYPE == EIGHT
	/* Set RS to HIGH */
	LCD_Port_control |= (1<<RS);


	/* Set E to HIGH */
	LCD_Port_control |= (1<<EN);

	/* Load Command on Data bus */
	LCD_Port_data = u8DataCpy;

	/* Set E to LOW */
	LCD_Port_control &=~(1<<EN); 

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	LCD_Port_control |= (1<<EN);

	/* Delay to let the LCD Display the character */
	_delay_ms(10);
	#endif 
	
	#if TYPE == FOUR
	LCD_Port_data = (LCD_Port_data & 0x0F) | (u8DataCpy & 0xF0); /* sending upper nibble */
	PORTB |= (1<<RS);		/* RS=1, data reg. */
	PORTB &= ~ (1<<RW);
	PORTB|= (1<<EN);
	_delay_us(1);
	PORTB &= ~ (1<<EN);

	_delay_us(200);

	LCD_Port_data = (LCD_Port_data & 0x0F) | (u8DataCpy << 4); /* sending lower nibble */
	PORTB |= (1<<EN);
	_delay_us(1);
	PORTB &= ~ (1<<EN);
	_delay_ms(2);
	#endif

}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (unsigned char* pu8StringCpy, unsigned char u8Index)
{

//	/* Local loop index */
//	u8 u8Index = 0;
	u8 iteration=0;
//	while (pu8StringCpy[u8Index] != '\0')
	for (iteration=0; iteration<u8Index ; iteration++)
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr(pu8StringCpy[iteration]);

//		/* Increment local loop index */
//		u8Index++;

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}

}

/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void Gotoxy (unsigned char Y,unsigned char X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 0:
			#ifdef EIGHT
		    	LCD_vidSendCommand(X+0x80);
			#endif
			#ifdef FOUR
			//LCD_vidSendCommand((X & 0x0F)|0x80);
			LCD_vidSendCommand(X+0x80);
			#endif
		    break;
		    case 1:
			#ifdef EIGHT
		    	LCD_vidSendCommand(X+0xC0);
			#endif
			#ifdef FOUR
				//LCD_vidSendCommand((X & 0x0F)|0xC0);
				LCD_vidSendCommand(X+0xC0);
			#endif
		    break;
		    default:
		    break;
	    }
	}
}

/***************************************************************************************/
/* Description! Interface to write extra characters saved in the CGRAM                 */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteExtraChar (unsigned char Y,unsigned char X)
{
    unsigned char iteration1,iteration2;

    /*DDRAM-->CGRAM*/
    LCD_vidSendCommand(0x40);
	for(iteration1=0 ; iteration1<32 ; iteration1++)
	{
		LCD_vidWriteCharctr(ExtraChar2[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_vidSendCommand(0x80);
	Gotoxy(Y,X);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=4 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_vidWriteCharctr(iteration2);

		_delay_ms(5);
	}
}
