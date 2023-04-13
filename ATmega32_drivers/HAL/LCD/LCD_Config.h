#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


typedef struct
{
PortNumber  RS_Port;
PortNumber  RW_Port;
PortNumber  E_Port;
PinNumber   RS_Pin;
PinNumber   RW_Pin;
PinNumber   E_Pin;
PortNumber  Data_Port;
}
LCD_Info ;


#endif
