#include "../../Types.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LED_Interface.h"

void HAL_LED_TurnOn(Led_info *LED)
{
	MCAL_DIO_SetPinDirection(LED->LED_Port, LED->LED_Pin, DIO_Output);

	if (LED->ConnectionType == Source_Connection)
	{
		MCAL_DIO_SetPinValue(LED->LED_Port, LED->LED_Pin, Pin_High);
	}
	else if (LED->ConnectionType == Sink_Connection)
	{
		MCAL_DIO_SetPinValue(LED->LED_Port, LED->LED_Pin, Pin_Low);
	}
}


void HAL_LED_TurnOff(Led_info *LED)
{
	MCAL_DIO_SetPinDirection(LED->LED_Port, LED->LED_Pin, DIO_Output);

	if (LED->ConnectionType == Source_Connection)
	{
		MCAL_DIO_SetPinValue(LED->LED_Port, LED->LED_Pin, Pin_Low);
	}
	else if (LED->ConnectionType == Sink_Connection)
	{
		MCAL_DIO_SetPinValue(LED->LED_Port, LED->LED_Pin, Pin_High);
	}
}


void HAL_LED_Toggle(Led_info *LED)
{
	MCAL_DIO_SetPinDirection(LED->LED_Port, LED->LED_Pin, DIO_Output);
	MCAL_DIO_TogglePinValue(LED->LED_Port, LED->LED_Pin);
}
