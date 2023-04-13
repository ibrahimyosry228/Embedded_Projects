#include "../Types.h"
#include "../Bit_Math.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "SPI_App.h"
#include "../MCAL/TIMER/Timer_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KeyPad/Keypad_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "util/delay.h"



extern KeyPad_Info KEYPAD;
extern LCD_Info LCD;
extern Timer_Info Timer;
extern Reading result;


int main(void)
{
	MCAL_Timer2_Init(&Timer);
	MCAL_Timer2_SetOutputCompare(250);
	HAL_KeyPad_Init(&KEYPAD);
	HAL_LCD_Init(&LCD);

	HAL_LCD_SendCommand(LCD_ClearDisplay, &LCD);
	HAL_LCD_GoXY(&LCD, 0, 0);
	HAL_LCD_SendString((u8*)"Enter the mode:", &LCD);
	_delay_ms(750);
	HAL_LCD_SendCommand(LCD_ClearDisplay, &LCD);
	HAL_LCD_GoXY(&LCD, 0, 0);
	HAL_LCD_SendString((u8*)"1. Clock", &LCD);
	HAL_LCD_GoXY(&LCD, 1, 0);
	HAL_LCD_SendString((u8*)"2. Stopwatch", &LCD);
	while (result == No_Reading)
	{
		result = HAL_KeyPad_Read(&KEYPAD);
	}
	switch (result)
	{
		case '1': Clock_init();     break;
		case '2': Stopwatch_init(); break;
		default : Try_Again();      break;
	}


	while (1)
	{

	}

	return 0;
}
