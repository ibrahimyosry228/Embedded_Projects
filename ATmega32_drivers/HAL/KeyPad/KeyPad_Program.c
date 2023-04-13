#include <util/delay.h>
#include "../../Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include "Keypad_Interface.h"

void HAL_KeyPad_Reverse(KeyPad_Info* KEYPAD)
{
	MCAL_DIO_SetPinDirection(KEYPAD->Cols_Port, KEYPAD->col0, DIO_Input);
	MCAL_DIO_SetPinDirection(KEYPAD->Cols_Port, KEYPAD->col1, DIO_Input);
	MCAL_DIO_SetPinDirection(KEYPAD->Cols_Port, KEYPAD->col2, DIO_Input);
	MCAL_DIO_SetPinDirection(KEYPAD->Cols_Port, KEYPAD->col3, DIO_Input);

	MCAL_DIO_EnableInternalPullup(KEYPAD->Cols_Port, KEYPAD->col0);
	MCAL_DIO_EnableInternalPullup(KEYPAD->Cols_Port, KEYPAD->col1);
	MCAL_DIO_EnableInternalPullup(KEYPAD->Cols_Port, KEYPAD->col2);
	MCAL_DIO_EnableInternalPullup(KEYPAD->Cols_Port, KEYPAD->col3);

	MCAL_DIO_SetPinDirection(KEYPAD->Rows_Port, KEYPAD->row0, DIO_Output);
	MCAL_DIO_SetPinDirection(KEYPAD->Rows_Port, KEYPAD->row1, DIO_Output);
	MCAL_DIO_SetPinDirection(KEYPAD->Rows_Port, KEYPAD->row2, DIO_Output);
	MCAL_DIO_SetPinDirection(KEYPAD->Rows_Port, KEYPAD->row3, DIO_Output);

	MCAL_DIO_SetPinValue(KEYPAD->Rows_Port, KEYPAD->row0, Pin_Low);
	MCAL_DIO_SetPinValue(KEYPAD->Rows_Port, KEYPAD->row1, Pin_Low);
	MCAL_DIO_SetPinValue(KEYPAD->Rows_Port, KEYPAD->row2, Pin_Low);
	MCAL_DIO_SetPinValue(KEYPAD->Rows_Port, KEYPAD->row3, Pin_Low);
}

void HAL_KeyPad_Init(KeyPad_Info* KEYPAD)
{
	MCAL_DIO_SetPinDirection(KEYPAD->Rows_Port, KEYPAD->row0, DIO_Input);
	MCAL_DIO_SetPinDirection(KEYPAD->Rows_Port, KEYPAD->row1, DIO_Input);
	MCAL_DIO_SetPinDirection(KEYPAD->Rows_Port, KEYPAD->row2, DIO_Input);
	MCAL_DIO_SetPinDirection(KEYPAD->Rows_Port, KEYPAD->row3, DIO_Input);

	MCAL_DIO_EnableInternalPullup(KEYPAD->Rows_Port, KEYPAD->row0);
	MCAL_DIO_EnableInternalPullup(KEYPAD->Rows_Port, KEYPAD->row1);
	MCAL_DIO_EnableInternalPullup(KEYPAD->Rows_Port, KEYPAD->row2);
	MCAL_DIO_EnableInternalPullup(KEYPAD->Rows_Port, KEYPAD->row3);

	MCAL_DIO_SetPinDirection(KEYPAD->Cols_Port, KEYPAD->col0, DIO_Output);
	MCAL_DIO_SetPinDirection(KEYPAD->Cols_Port, KEYPAD->col1, DIO_Output);
	MCAL_DIO_SetPinDirection(KEYPAD->Cols_Port, KEYPAD->col2, DIO_Output);
	MCAL_DIO_SetPinDirection(KEYPAD->Cols_Port, KEYPAD->col3, DIO_Output);

	MCAL_DIO_SetPinValue(KEYPAD->Cols_Port, KEYPAD->col0, Pin_Low);
	MCAL_DIO_SetPinValue(KEYPAD->Cols_Port, KEYPAD->col1, Pin_Low);
	MCAL_DIO_SetPinValue(KEYPAD->Cols_Port, KEYPAD->col2, Pin_Low);
	MCAL_DIO_SetPinValue(KEYPAD->Cols_Port, KEYPAD->col3, Pin_Low);
}

Reading HAL_KeyPad_Read(KeyPad_Info* KEYPAD)
{
	if (MCAL_DIO_ReadPinValue(KEYPAD->Rows_Port, KEYPAD->row0) == 0)
	{
		HAL_KeyPad_Reverse(KEYPAD);
		if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col0) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R0_C0;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col1) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R0_C1;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col2) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R0_C2;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col3) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R0_C3;
		}
	}
	else if (MCAL_DIO_ReadPinValue(KEYPAD->Rows_Port, KEYPAD->row1) == 0)
	{
		HAL_KeyPad_Reverse(KEYPAD);
		if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col0) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R1_C0;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col1) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R1_C1;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col2) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R1_C2;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col3) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R1_C3;
		}
	}
	else if (MCAL_DIO_ReadPinValue(KEYPAD->Rows_Port, KEYPAD->row2) == 0)
	{
		HAL_KeyPad_Reverse(KEYPAD);
		if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col0) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R2_C0;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col1) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R2_C1;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col2) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R2_C2;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col3) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R2_C3;
		}
	}
	else if (MCAL_DIO_ReadPinValue(KEYPAD->Rows_Port, KEYPAD->row3) == 0)
	{
		HAL_KeyPad_Reverse(KEYPAD);
		if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col0) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R3_C0;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col1) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R3_C1;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col2) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R3_C2;
		}
		else if (MCAL_DIO_ReadPinValue(KEYPAD->Cols_Port, KEYPAD->col3) == 0)
		{
			HAL_KeyPad_Init(KEYPAD);
			return R3_C3;
		}
	}
	return No_Reading;
}
