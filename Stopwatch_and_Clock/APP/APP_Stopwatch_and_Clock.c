#include "../Types.h"
#include "../Bit_Math.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/TIMER/Timer_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KeyPad/Keypad_Interface.h"
#include "APP_Stopwatch_and_Clock.h"
#include "util/delay.h"


KeyPad_Info KEYPAD = {DIO_PortB, DIO_PortB, DIO_Pin7, DIO_Pin6, DIO_Pin5, DIO_Pin4, DIO_Pin3, DIO_Pin2, DIO_Pin1, DIO_Pin0};
LCD_Info LCD = {DIO_PortD, DIO_PortD, DIO_PortD, DIO_Pin0, DIO_Pin1, DIO_Pin2, DIO_PortA};
Timer_Info Timer = {CTC, Disconnected, PS_256, Enable_CM};


u8 hour, min, sec;
Reading result = No_Reading;
u8 time[9] = {'0', '0', ':', '0', '0', ':', '0', '0', '\0'};
u32 Seconds_Counter;

void Stopwatch_init(void)
{
	HAL_LCD_SendCommand(LCD_ClearDisplay, &LCD);
	HAL_LCD_GoXY(&LCD, 0, 0);
	HAL_LCD_SendString(time, &LCD);
	result = No_Reading;
	_delay_ms(200);
	for(int i = 0; i < 8; i++)
	{
		CLR_Bit(SREG, 7);
		while (result == No_Reading)
		{
			result = HAL_KeyPad_Read(&KEYPAD);
		}
		_delay_ms(250);
		if (result == '=')
		{
			break;
		}
		if (i == 2 || i == 5)
		{
			continue;
		}
		time[i] = result;
		HAL_LCD_GoXY(&LCD, 0, 0);
		HAL_LCD_SendString(time, &LCD);
		result = No_Reading;
	}
	_delay_ms(1000);
	Seconds_Counter = (time[0] - '0') * 36000 + (time[1] - '0') * 3600 + (time[3] - '0') * 600 + (time[4] - '0') * 60 + (time[6] - '0') * 10 + (time[7] - '0');
	MCAL_Timer2_CompareMatch_SetCallBackFun(&Stopwatch);
	SET_Bit(SREG, 7);
}

void Stopwatch(void)
{
	static u8 Ticks_Counter;
	Ticks_Counter++;
	if (Ticks_Counter == 125)
	{
		Ticks_Counter = 0;                    /*Reset every second*/
		HAL_LCD_GoXY(&LCD, 0, 0);
		Seconds_Counter--;                 /*Decrement the number of seconds*/
		if (Seconds_Counter == 0)
		{
			HAL_LCD_SendString((u8*)"Finished!", &LCD);
			_delay_ms(1000);
			main();
		}
		sec = Seconds_Counter % 60;         /*Calculate the number of seconds*/
		time[6] = sec / 10 + '0';          /*Seconds units digit*/
		time[7] = sec % 10 + '0';          /*Seconds tens digit*/

		min = (Seconds_Counter / 60) % 60;  /*Calculate the number of minutes*/
		time[3] = min / 10 + '0';          /*Minutes units digit*/
		time[4] = min % 10 + '0';          /*Minutes tens digit*/

		hour = Seconds_Counter / 3600;       /*Calculate the number of hours*/
		time[0] = hour / 10 + '0';          /*Hours units digit*/
		time[1] = hour % 10 + '0';          /*Hours tens digit*/

		HAL_LCD_SendString(time, &LCD);     /*Send the time to LCD*/
	}
}

void Clock_init(void)
{
	HAL_LCD_SendCommand(LCD_ClearDisplay, &LCD);
	HAL_LCD_GoXY(&LCD, 0, 0);
	HAL_LCD_SendString(time, &LCD);
	result = No_Reading;
	MCAL_Timer2_CompareMatch_SetCallBackFun(&Clock);
}

void Clock(void)
{
	static u8 Ticks_Counter;
	Ticks_Counter++;
	if (Ticks_Counter == 125)
	{
		Ticks_Counter = 0;                    /*Reset every second*/
		HAL_LCD_GoXY(&LCD, 0, 0);
		Seconds_Counter++;                  /*Increment the number of seconds*/

		if (Seconds_Counter == 86400)       /*Reset every 24 hours*/
		{
			Seconds_Counter = 0;
		}

		sec = Seconds_Counter % 60;         /*Calculate the number of seconds*/
		time[6] = sec / 10 + '0';          /*Seconds units digit*/
		time[7] = sec % 10 + '0';          /*Seconds tens digit*/

		min = (Seconds_Counter / 60) % 60;  /*Calculate the number of minutes*/
		time[3] = min / 10 + '0';          /*Minutes units digit*/
		time[4] = min % 10 + '0';          /*Minutes tens digit*/

		hour = Seconds_Counter / 3600;       /*Calculate the number of hours*/
		time[0] = hour / 10 + '0';          /*Hours units digit*/
		time[1] = hour % 10 + '0';          /*Hours tens digit*/

		HAL_LCD_SendString(time, &LCD);     /*Send the time to LCD*/
	}
}

void Try_Again(void)
{
	result = No_Reading;
	HAL_LCD_SendCommand(LCD_ClearDisplay, &LCD);
	HAL_LCD_GoXY(&LCD, 0, 0);
	HAL_LCD_SendString((u8*)"Try Again", &LCD);
	_delay_ms(1000);
	main();
}
