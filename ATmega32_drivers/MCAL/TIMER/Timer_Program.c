#include "../../Types.h"
#include "../../Bit_Math.h"
#include "../DIO/DIO_Interface.h"
#include "Timer_Interface.h"
#include "Timer_Private.h"

#define Global_Interrupt_Enable()    SET_Bit(SREG, I)

void (*Timer0_OverFlow_CallBackFunction)(void)      = NULL;
void (*Timer2_OverFlow_CallBackFunction)(void)      = NULL;
void (*Timer1_InputCap_CallBackFunction)(void)      = NULL;
void (*Timer0_CompareMatch_CallBackFunction)(void)  = NULL;
void (*Timer2_CompareMatch_CallBackFunction)(void)  = NULL;


void MCAL_Timer0_Init(Timer_Info* Timer)
{
	switch (Timer->Mode)        /*Set timer mode*/
	{
		case Normal:            CLR_Bit(TCCR0, WGM00); CLR_Bit(TCCR0, WGM01); break;
		case PWM_PhaseCorrect:  SET_Bit(TCCR0, WGM00); CLR_Bit(TCCR0, WGM01); break;
		case CTC:               CLR_Bit(TCCR0, WGM00); SET_Bit(TCCR0, WGM01); break;
		case Fast_PWM:          SET_Bit(TCCR0, WGM00); SET_Bit(TCCR0, WGM01); break;
	}

	switch (Timer->OCx)			/*Set Output Compare pin (OC0) behaviour*/
	{
		case Disconnected:      CLR_Bit(TCCR0, COM00); CLR_Bit(TCCR0, COM01); break;
		case Toggle:  			SET_Bit(TCCR0, COM00); CLR_Bit(TCCR0, COM01); break;
		case Clear:             CLR_Bit(TCCR0, COM00); SET_Bit(TCCR0, COM01); break;
		case Set:        	    SET_Bit(TCCR0, COM00); SET_Bit(TCCR0, COM01); break;
	}

	switch (Timer->Source)			/*Set Output Compare pin (OC0) behaviour*/
	{
		case No_Source:         CLR_Bit(TCCR0, CS00); CLR_Bit(TCCR0, CS01); CLR_Bit(TCCR0, CS02); break;
		case No_PS:  			SET_Bit(TCCR0, CS00); CLR_Bit(TCCR0, CS01); CLR_Bit(TCCR0, CS02); break;
		case PS_8:              CLR_Bit(TCCR0, CS00); SET_Bit(TCCR0, CS01); CLR_Bit(TCCR0, CS02); break;
		case PS_64:        	    SET_Bit(TCCR0, CS00); SET_Bit(TCCR0, CS01); CLR_Bit(TCCR0, CS02); break;
		case PS_256:            CLR_Bit(TCCR0, CS00); CLR_Bit(TCCR0, CS01); SET_Bit(TCCR0, CS02); break;
		case PS_1024:        	SET_Bit(TCCR0, CS00); CLR_Bit(TCCR0, CS01); SET_Bit(TCCR0, CS02); break;
		case External_FE:       CLR_Bit(TCCR0, CS00); SET_Bit(TCCR0, CS01); SET_Bit(TCCR0, CS02); break;
		case External_RE:       SET_Bit(TCCR0, CS00); SET_Bit(TCCR0, CS01); SET_Bit(TCCR0, CS02); break;
	}

	Global_Interrupt_Enable();

	switch (Timer->Interrrupt)
	{
		case Disable:           CLR_Bit(TIMSK, TOIE0); CLR_Bit(TIMSK, OCIE0); break;
		case Enable_OF:  		SET_Bit(TIMSK, TOIE0); CLR_Bit(TIMSK, OCIE0); break;
		case Enable_CM:         CLR_Bit(TIMSK, TOIE0); SET_Bit(TIMSK, OCIE0); break;
		case Enable_both:       SET_Bit(TIMSK, TOIE0); SET_Bit(TIMSK, OCIE0); break;
	}
}


void MCAL_Timer0_SetOutputCompare(u8 OC_Value)
{
	OCR0 = OC_Value;
}

void MCAL_Timer0_SetPreloadValue(u8 PL_Value)
{
	TCNT0 = PL_Value;
}

void MCAL_Timer0_ClearOutputCompareFlag(void)
{
	SET_Bit(TIFR, OCF0);
}

void MCAL_Timer0_ClearOverflowFlag(void)
{
	SET_Bit(TIFR, TOV0);
}



void MCAL_Timer2_Init(Timer_Info* Timer)
{
	switch (Timer->Mode)        /*Set timer mode*/
	{
		case Normal:            CLR_Bit(TCCR2, WGM20); CLR_Bit(TCCR2, WGM21); break;
		case PWM_PhaseCorrect:  SET_Bit(TCCR2, WGM20); CLR_Bit(TCCR2, WGM21); break;
		case CTC:               CLR_Bit(TCCR2, WGM20); SET_Bit(TCCR2, WGM21); break;
		case Fast_PWM:          SET_Bit(TCCR2, WGM20); SET_Bit(TCCR2, WGM21); break;
	}

	switch (Timer->OCx)			/*Set Output Compare pin (OC0) behaviour*/
	{
		case Disconnected:      CLR_Bit(TCCR2, COM20); CLR_Bit(TCCR2, COM21); break;
		case Toggle:  			SET_Bit(TCCR2, COM20); CLR_Bit(TCCR2, COM21); break;
		case Clear:             CLR_Bit(TCCR2, COM20); SET_Bit(TCCR2, COM21); break;
		case Set:        	    SET_Bit(TCCR2, COM20); SET_Bit(TCCR2, COM21); break;
	}

	switch (Timer->Source)			/*Set Output Compare pin (OC0) behaviour*/
	{
		case No_Source:         CLR_Bit(TCCR2, CS00); CLR_Bit(TCCR2, CS01); CLR_Bit(TCCR2, CS02); break;
		case No_PS:  			SET_Bit(TCCR2, CS00); CLR_Bit(TCCR2, CS01); CLR_Bit(TCCR2, CS02); break;
		case PS_8:              CLR_Bit(TCCR2, CS00); SET_Bit(TCCR2, CS01); CLR_Bit(TCCR2, CS02); break;
		case PS_32:        	    SET_Bit(TCCR2, CS00); SET_Bit(TCCR2, CS01); CLR_Bit(TCCR2, CS02); break;
		case PS_64:             CLR_Bit(TCCR2, CS00); CLR_Bit(TCCR2, CS01); SET_Bit(TCCR2, CS02); break;
		case PS_128:        	SET_Bit(TCCR2, CS00); CLR_Bit(TCCR2, CS01); SET_Bit(TCCR2, CS02); break;
		case PS_256:            CLR_Bit(TCCR2, CS00); SET_Bit(TCCR2, CS01); SET_Bit(TCCR2, CS02); break;
		case PS_1024:           SET_Bit(TCCR2, CS00); SET_Bit(TCCR2, CS01); SET_Bit(TCCR2, CS02); break;
	}

	Global_Interrupt_Enable();

	switch (Timer->Interrrupt)
	{
		case Disable:           CLR_Bit(TIMSK, TOIE2); CLR_Bit(TIMSK, OCIE2); break;
		case Enable_OF:  		SET_Bit(TIMSK, TOIE2); CLR_Bit(TIMSK, OCIE2); break;
		case Enable_CM:         CLR_Bit(TIMSK, TOIE2); SET_Bit(TIMSK, OCIE2); break;
		case Enable_both:       SET_Bit(TIMSK, TOIE2); SET_Bit(TIMSK, OCIE2); break;
	}
}


void MCAL_Timer2_SetOutputCompare(u8 OC_Value)
{
	OCR2 = OC_Value;
}

void MCAL_Timer2_SetPreloadValue(u8 PL_Value)
{
	TCNT2 = PL_Value;
}

void MCAL_Timer2_ClearOutputCompareFlag(void)
{
	SET_Bit(TIFR, OCF2);
}

void MCAL_Timer2_ClearOverflowFlag(void)
{
	SET_Bit(TIFR, TOV2);
}

void MCAL_Timer1_InputCaptureEnable(State NoiseCanceller_State, Triggering_Edge Edge)
{
	switch (NoiseCanceller_State)
	{
		case Disabled: CLR_Bit(TCCR1B, ICNC1); break;
		case Enabled:  SET_Bit(TCCR1B, ICNC1); break;
	}

	switch (Edge)
	{
		case Falling: CLR_Bit(TCCR1B, ICES1); break;
		case Rising:  SET_Bit(TCCR1B, ICES1); break;
	}
}


void MCAL_Timer0_OverFlow_SetCallBackFun(void (*CallBack_Fun)(void))
{
	if (CallBack_Fun != NULL)
	{
		Timer0_OverFlow_CallBackFunction = CallBack_Fun;
	}
}

void MCAL_Timer0_CompareMatch_SetCallBackFun(void (*CallBack_Fun)(void))
{
	if (CallBack_Fun != NULL)
	{
		Timer0_CompareMatch_CallBackFunction = CallBack_Fun;
	}
}

void MCAL_Timer2_OverFlow_SetCallBackFun(void (*CallBack_Fun)(void))
{
	if (CallBack_Fun != NULL)
	{
		Timer2_OverFlow_CallBackFunction = CallBack_Fun;
	}
}

void MCAL_Timer2_CompareMatch_SetCallBackFun(void (*CallBack_Fun)(void))
{
	if (CallBack_Fun != NULL)
	{
		Timer2_CompareMatch_CallBackFunction = CallBack_Fun;
	}
}

void MCAL_Timer1_InputCap_SetCallBackFun(void (*CallBack_Fun)(void))
{
	if (CallBack_Fun != NULL)
	{
		Timer1_InputCap_CallBackFunction = CallBack_Fun;
	}
}


void __vector_4(void)  __attribute__((signal));
void __vector_4(void)
{
	if (Timer2_CompareMatch_CallBackFunction != NULL)
	{
		Timer2_CompareMatch_CallBackFunction();
	}
}

void __vector_5(void)  __attribute__((signal));
void __vector_5(void)
{
	if (Timer2_OverFlow_CallBackFunction != NULL)
	{
		Timer2_OverFlow_CallBackFunction();
	}
}

void __vector_6(void)  __attribute__((signal));
void __vector_6(void)
{
	if (Timer1_InputCap_CallBackFunction != NULL)
	{
		Timer1_InputCap_CallBackFunction();
	}
}

void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	if (Timer0_CompareMatch_CallBackFunction != NULL)
	{
		Timer0_CompareMatch_CallBackFunction();
	}
}

void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
	if (Timer0_OverFlow_CallBackFunction != NULL)
	{
		Timer0_OverFlow_CallBackFunction();
	}
}
