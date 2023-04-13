#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_


#define LCD_ClearDisplay     0x01
#define LCD_ReturnHome       0x02
#define LCD_EntryMode        0x06
#define LCD_DisplayOff       0x08  // D = 0    C = 0    B = 0    The Display is Off so Will Cursor is off  And Blinking is OFF
#define LCD_DisplayOn        0x0C  // D = 1    C = 0    B = 0    The Display is On But the Cursor is OFF so the Blinking is OFF
#define LCD_CursorOff        0x0E  // Blinking cursor is off

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Function Set
RS  R/W DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0
=== === === === === === === === === ===
 0   0   0   0   1   DL  N   F   *   *
*/

#define  LCD_Reset		             0x30

#define  LCD_Set4Bit1Line5x8         0x20     // the Data Will Send by 4 bit and the Number of line is 1 and the Font is 5x8
#define  LCD_Set4Bit1Line5x11        0x24     // the Data Will Send by 4 bit and the Number of line is 1 and the Font is 5x11
#define  LCD_Set4Bit2Line5x8	     0x28     // the Data Will Send by 4 bit and the Number of line is 2 and the Font is 5x8
#define  LCD_Set4Bit2Line5x11        0x2C     // the Data Will Send by 4 bit and the Number of line is 2 and the Font is 5x11
#define  LCD_Set8Bit1Line5x8		 0x30     // the Data Will Send by 8 bit and the Number of line is 1 and the Font is 5x8
#define  LCD_Set8Bit1Line5x11    	 0x34     // the Data Will Send by 8 bit and the Number of line is 1 and the Font is 5x11
#define  LCD_Set8Bit2Line5x8     	 0x38     // the Data Will Send by 8 bit and the Number of line is 2 and the Font is 5x8
#define  LCD_Set8Bit2Line5x11    	 0x3C     // the Data Will Send by 8 bit and the Number of line is 2 and the Font is 5x11
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/



#define LCD_PinLow          	LOW
#define LCD_PinHigh         	HIGH
#define LCD_PinInput        	INPUT
#define LCD_PinOUTPUT       	OUTPUT
#define LCD_PortMaxValue    	0xFF
#define LCD_CharSize            8
#define LCD_SecondLine          0x40


typedef enum
{
	line0,
	line1,
	Coloum0 = 0,
	Coloum1,
	Coloum2,
	Coloum3,
	Coloum4,
	Coloum5,
	Coloum6,
	Coloum7,
	Coloum8,
	Coloum9,
	Coloum10,
	Coloum11,
	Coloum12,
	Coloum13,
	Coloum14,
	Coloum15,

}
Lines;

typedef enum
{
	CGRAM = 6,
	DDRAM
}
RAM_TYPE;


#endif
