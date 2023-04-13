#ifndef _TIMER_H_
#define _TIMER_H_

#include "Timer_Config.h"
#include "Timer_Private.h"


void MCAL_Timer0_Init(Timer_Info* Timer);
void MCAL_Timer0_SetOutputCompare(u8 OC_Value);
void MCAL_Timer0_SetPreloadValue(u8 PL_Value);
void MCAL_Timer0_ClearOutputCompareFlag(void);
void MCAL_Timer0_ClearOverflowFlag(void);

void MCAL_Timer2_Init(Timer_Info* Timer);
void MCAL_Timer2_SetOutputCompare(u8 OC_Value);
void MCAL_Timer2_SetPreloadValue(u8 PL_Value);
void MCAL_Timer2_ClearOutputCompareFlag(void);
void MCAL_Timer2_ClearOverflowFlag(void);

void MCAL_Timer1_InputCaptureEnable(State NoiseCanceller_State, Triggering_Edge Edge);

void MCAL_Timer0_OverFlow_SetCallBackFun(void (*CallBack_Fun)(void));
void MCAL_Timer0_CompareMatch_SetCallBackFun(void (*CallBack_Fun)(void));
void MCAL_Timer2_OverFlow_SetCallBackFun(void (*CallBack_Fun)(void));
void MCAL_Timer2_CompareMatch_SetCallBackFun(void (*CallBack_Fun)(void));
void MCAL_Timer0_OverFlow_SetCallBackFun(void (*CallBack_Fun)(void));
void MCAL_Timer1_InputCap_SetCallBackFun(void (*CallBack_Fun)(void));


#endif
