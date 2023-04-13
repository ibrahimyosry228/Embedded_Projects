#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#include "LCD_private.h"
#include "LCD_Config.h"

void HAL_LCD_Init(LCD_Info* LCD);
void HAL_LCD_SendCommand(u8 Command, LCD_Info* LCD);
void HAL_LCD_SetRamAddress(RAM_TYPE RAM, u8 Address, LCD_Info* LCD);
void HAL_LCD_WriteToRam(u8 Data, LCD_Info* LCD);
void HAL_LCD_SendChar(u8 Char, LCD_Info* LCD);
void HAL_LCD_SendString(u8* String ,LCD_Info* LCD);
void HAL_LCD_StoreSpecial(u8* Special, u8 Offset,  LCD_Info* LCD);
void HAL_LCD_SendSpecial(u8 SpecialOffset,  LCD_Info* LCD);
void HAL_LCD_SendNumber(s32 Number,  LCD_Info* LCD);
void HAL_LCD_GoXY(LCD_Info* LCD ,u8 XLocation ,u8 YLocation );


#endif
