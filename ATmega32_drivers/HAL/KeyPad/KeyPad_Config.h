#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


typedef struct
{
	PortNumber  Rows_Port;
	PortNumber  Cols_Port;
	PinNumber   row0;
	PinNumber   row1;
	PinNumber   row2;
	PinNumber   row3;
	PinNumber   col0;
	PinNumber   col1;
	PinNumber   col2;
	PinNumber   col3;
}
KeyPad_Info;


#endif
