#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


#include "LED_Private.h"
#include "LED_Config.h"

void HAL_LED_TurnOn(Led_info *LED);
void HAL_LED_TurnOff(Led_info *LED);
void HAL_LED_Toggle(Led_info *LED);


#endif
