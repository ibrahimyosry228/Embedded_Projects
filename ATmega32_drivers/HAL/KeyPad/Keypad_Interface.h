#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_


#include "KeyPad_config.h"
#include "KeyPad_private.h"

void HAL_KeyPad_Init(KeyPad_Info* KEYPAD);
void HAL_KeyPad_Reverse(KeyPad_Info* KEYPAD);
Reading HAL_KeyPad_Read(KeyPad_Info* KEYPAD);


#endif
