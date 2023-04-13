#include <util/delay.h>
#include "../../Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Lcd_Interface.h"


u8 LCD_RamAddress = 0x00;

void HAL_LCD_Init(LCD_Info* LCD)
{
	//Pins configuration
	MCAL_DIO_SetPortDirection(LCD->Data_Port, DIO_Output);
	MCAL_DIO_SetPinDirection(LCD->RS_Port, LCD->RS_Pin, DIO_Output);
	MCAL_DIO_SetPinDirection(LCD->RW_Port, LCD->RW_Pin, DIO_Output);
	MCAL_DIO_SetPinDirection(LCD->E_Port, LCD->E_Pin, DIO_Output);

	//Startup sequence
	_delay_ms(35);
	HAL_LCD_SendCommand(LCD_Reset, LCD);
	_delay_ms(1);

	HAL_LCD_SendCommand(LCD_Set8Bit2Line5x8, LCD);
	HAL_LCD_SendCommand(LCD_DisplayOn, LCD);
	HAL_LCD_SendCommand(LCD_ClearDisplay, LCD);
	HAL_LCD_SendCommand(LCD_EntryMode, LCD);
}

void HAL_LCD_SendCommand(u8 Copy_Command, LCD_Info * Lcd)
{
	MCAL_DIO_SetPinValue(Lcd->RS_Port, Lcd->RS_Pin, Pin_Low);
	MCAL_DIO_SetPinValue(Lcd->RW_Port, Lcd->RW_Pin, Pin_Low);

	MCAL_DIO_SetPortValue(Lcd->Data_Port, Copy_Command);

	MCAL_DIO_SetPinValue(Lcd->E_Port, Lcd->E_Pin, Pin_High);
	_delay_ms(1);
	MCAL_DIO_SetPinValue(Lcd->E_Port, Lcd->E_Pin, Pin_Low);
	_delay_ms(1);
}

void HAL_LCD_SetRamAddress(RAM_TYPE RAM, u8 Address, LCD_Info* LCD)
{
	LCD_RamAddress = Address;
	MCAL_DIO_SetPinValue(LCD->RS_Port, LCD->RS_Pin, Pin_Low);
	MCAL_DIO_SetPinValue(LCD->RW_Port, LCD->RW_Pin, Pin_Low);

	MCAL_DIO_SetPortValue(LCD->Data_Port, LCD_RamAddress + (1 << RAM));

	MCAL_DIO_SetPinValue(LCD->E_Port, LCD->E_Pin, Pin_High);
	_delay_ms(1);
	MCAL_DIO_SetPinValue(LCD->E_Port, LCD->E_Pin, Pin_Low);
	_delay_ms(1);
}

void HAL_LCD_WriteToRam(u8 Data, LCD_Info * Lcd)
{
	MCAL_DIO_SetPinValue(Lcd->RS_Port, Lcd->RS_Pin, Pin_High);
	MCAL_DIO_SetPinValue(Lcd->RW_Port, Lcd->RW_Pin, Pin_Low);

	MCAL_DIO_SetPortValue(Lcd->Data_Port, Data);

	MCAL_DIO_SetPinValue(Lcd->E_Port, Lcd->E_Pin, Pin_High);
	_delay_ms(1);
	MCAL_DIO_SetPinValue(Lcd->E_Port, Lcd->E_Pin, Pin_Low);
	_delay_ms(1);
}

void HAL_LCD_SendChar(u8 Copy_Char, LCD_Info* LCD)
{
	LCD_RamAddress++;
	if (LCD_RamAddress > 0x4F)
	{
		HAL_LCD_SendCommand(LCD_ClearDisplay, LCD);
		LCD_RamAddress = 0x00;
	}
	if (LCD_RamAddress == 0x11)
	{
		HAL_LCD_SetRamAddress(DDRAM, 0x40, LCD);
	}
	MCAL_DIO_SetPinValue(LCD->RS_Port, LCD->RS_Pin, Pin_High);
	MCAL_DIO_SetPinValue(LCD->RW_Port, LCD->RW_Pin, Pin_Low);

	MCAL_DIO_SetPortValue(LCD->Data_Port, Copy_Char);

	MCAL_DIO_SetPinValue(LCD->E_Port, LCD->E_Pin, Pin_High);
	_delay_ms(1);
	MCAL_DIO_SetPinValue(LCD->E_Port, LCD->E_Pin, Pin_Low);
	_delay_ms(1);
}

void HAL_LCD_SendString(u8* String ,LCD_Info* LCD)
{
	u8 i = 0;
	while(String[i] != '\0')
	{
		HAL_LCD_SendChar(String[i++],LCD);
	}
}

void HAL_LCD_StoreSpecial(u8* Special, u8 Offset,  LCD_Info* LCD)
{
	u8 i;
	for (i = Offset; i < Offset + LCD_CharSize; i++)
	{
		HAL_LCD_SetRamAddress(CGRAM, i, LCD);
		HAL_LCD_WriteToRam(Special[i % 8], LCD);
	}
}

void HAL_LCD_SendSpecial(u8 SpecialOffset,  LCD_Info* LCD)
{
	HAL_LCD_SendChar(SpecialOffset / LCD_CharSize, LCD);
}

void HAL_LCD_SendNumber(s32 Number,  LCD_Info* Lcd)
{
	s8 i = 0, len = 0;
	u8 numbers[7] = {};

	if (Number < 0)
	{
		numbers[i++] = '-';
		len = i;
		Number *= -1;
	}
	else if (Number == 0)
	{
		numbers[i++] = '0';
		len = i;
	}

	s16 temp = Number;
	while (temp != 0)
	{
		len++;
		temp /= 10;
	}
	numbers[len--] = '\0';


	for (; len >= i; len--)
	{
		numbers[len] = (Number % 10) + '0';
		Number /= 10;
	}

	HAL_LCD_SendString(numbers , Lcd);
}

void HAL_LCD_GoXY(LCD_Info* LCD ,u8 XLocation ,u8 YLocation )
{
	LCD_RamAddress = XLocation * LCD_SecondLine + YLocation;
	HAL_LCD_SetRamAddress(DDRAM,  LCD_RamAddress, LCD);
}
