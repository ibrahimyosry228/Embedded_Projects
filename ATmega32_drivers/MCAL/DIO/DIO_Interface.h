#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "DIO_Private.h"

void  MCAL_DIO_SetPinDirection(PortNumber PORT, PinNumber PIN, Direction DIR);
void MCAL_DIO_EnableInternalPullup(PortNumber PORT, PinNumber PIN);
void  MCAL_DIO_SetPinValue(PortNumber PORT, PinNumber PIN, Value VAL);
void  MCAL_DIO_TogglePinValue(PortNumber PORT, PinNumber PIN);
Value MCAL_DIO_ReadPinValue(PortNumber PORT, PinNumber PIN);

void  MCAL_DIO_SetPortDirection(PortNumber PORT, u8 DIR);
void  MCAL_DIO_SetPortValue(PortNumber PORT, u8 VAL);
void  MCAL_DIO_TogglePortValue(PortNumber PORT);
Value MCAL_DIO_ReadPortValue(PortNumber PORT);


#endif
