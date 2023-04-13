#include "../../Types.h"
#include "../../Bit_Math.h"
#include "DIO_Interface.h"

void MCAL_DIO_SetPinDirection(PortNumber PORT, PinNumber PIN, Direction DIR)
{
	if (DIR == DIO_Input)
	{
		switch (PORT)
		{
			case DIO_PortA: CLR_Bit(DDRA , PIN); break;
			case DIO_PortB: CLR_Bit(DDRB , PIN); break;
			case DIO_PortC: CLR_Bit(DDRC , PIN); break;
			case DIO_PortD: CLR_Bit(DDRD , PIN); break;
		}
	}
	else if (DIR == DIO_Output)
	{
		switch (PORT)
		{
			case DIO_PortA : SET_Bit(DDRA,PIN); break;
			case DIO_PortB : SET_Bit(DDRB,PIN); break;
			case DIO_PortC : SET_Bit(DDRC,PIN); break;
			case DIO_PortD : SET_Bit(DDRD,PIN); break;
		}
	}
}

void MCAL_DIO_EnableInternalPullup(PortNumber PORT, PinNumber PIN)
{
	switch (PORT)
	{
		case DIO_PortA: SET_Bit(PORTA,PIN); break;
		case DIO_PortB: SET_Bit(PORTB,PIN); break;
		case DIO_PortC: SET_Bit(PORTC,PIN); break;
		case DIO_PortD: SET_Bit(PORTD,PIN); break;
	}
}


void MCAL_DIO_SetPinValue(PortNumber PORT, PinNumber PIN, Value VAL)
{
	if (VAL == Pin_Low)
	{
		switch (PORT)
		{
			case DIO_PortA: CLR_Bit(PORTA , PIN ); break;
			case DIO_PortB: CLR_Bit(PORTB , PIN ); break;
			case DIO_PortC: CLR_Bit(PORTC , PIN ); break;
			case DIO_PortD: CLR_Bit(PORTD , PIN ); break;
		}
	}
	else if (VAL == Pin_High)
	{
		switch (PORT)
		{
			case DIO_PortA: SET_Bit(PORTA,PIN); break;
			case DIO_PortB: SET_Bit(PORTB,PIN); break;
			case DIO_PortC: SET_Bit(PORTC,PIN); break;
			case DIO_PortD: SET_Bit(PORTD,PIN); break;
		}
	}
}


void MCAL_DIO_TogglePinValue(PortNumber PORT, PinNumber PIN)
{
	switch (PORT)
	{
		case DIO_PortA: TOGGLE_Bit(PORTA,PIN); break;
		case DIO_PortB: TOGGLE_Bit(PORTB,PIN); break;
		case DIO_PortC: TOGGLE_Bit(PORTC,PIN); break;
		case DIO_PortD: TOGGLE_Bit(PORTD,PIN); break;
	}
}


Value MCAL_DIO_ReadPinValue(PortNumber PORT, PinNumber PIN)
{
	Value VAL;
	switch (PORT)
	{
		case DIO_PortA: VAL = GET_Bit(PINA , PIN ); break;
		case DIO_PortB: VAL = GET_Bit(PINB , PIN ); break;
		case DIO_PortC: VAL = GET_Bit(PINC , PIN ); break;
		case DIO_PortD: VAL = GET_Bit(PIND , PIN ); break;
	}
	return VAL;
}


void MCAL_DIO_SetPortDirection(PortNumber PORT, u8 DIR)
{
	switch (PORT)
	{
		case DIO_PortA: DDRA = DIR; break;
		case DIO_PortB: DDRB = DIR; break;
		case DIO_PortC: DDRC = DIR; break;
		case DIO_PortD: DDRD = DIR; break;
	}
}


void MCAL_DIO_SetPortValue(PortNumber PORT, u8 VAL)
{
	switch (PORT)
	{
		case DIO_PortA: PORTA = VAL; break;
		case DIO_PortB: PORTB = VAL; break;
		case DIO_PortC: PORTC = VAL; break;
		case DIO_PortD: PORTD = VAL; break;
	}
}


void MCAL_DIO_TogglePortValue(PortNumber PORT)
{
	switch (PORT)
	{
		case DIO_PortA: PORTA ^= 0xFF; break;
		case DIO_PortB: PORTB ^= 0xFF; break;
		case DIO_PortC: PORTC ^= 0xFF; break;
		case DIO_PortD: PORTD ^= 0xFF; break;
	}
}

Value MCAL_DIO_ReadPortValue(PortNumber PORT)
{
	u8 VAL;
	switch (PORT)
	{
		case DIO_PortA: VAL = PINA; break;
		case DIO_PortB: VAL = PINB; break;
		case DIO_PortC: VAL = PINC; break;
		case DIO_PortD: VAL = PIND; break;
	}
	return VAL;
}
