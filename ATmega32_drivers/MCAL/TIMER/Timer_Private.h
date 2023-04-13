#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/*Status register*/
#define SREG  (*(v_u8*)(0x5F))

#define C       0
#define Z       1
#define N       2
#define V       3
#define S       4
#define H       5
#define T       6
#define I       7

/*Timer general registers*/
#define TIFR  (*(v_u8*)(0x58))

#define TOV0    0
#define OCF0    1
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF1    5
#define TOV2    6
#define OCF2    7

#define TIMSK (*(v_u8*)(0x59))

#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7

/*Timer0 registers*/
#define TCCR0 (*(v_u8*)(0x53))

#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

#define TCNT0 (*(v_u8*)(0x52))

#define OCR0  (*(v_u8*)(0x5C))

/*Timer1 registers*/
#define TCCR1A (*(v_u8*)(0x4F))

#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define TCCR1B (*(v_u8*)(0x4E))

#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define RES     5
#define ICES1   6
#define ICNC1   7

#define TCNT1H (*(v_u8*)(0x4D))
#define TCNT1L (*(v_u8*)(0x4C))
#define OCR1AH (*(v_u8*)(0x4B))
#define OCR1AL (*(v_u8*)(0x4A))
#define OCR1BH (*(v_u8*)(0x49))
#define OCR1BL (*(v_u8*)(0x48))
#define ICR1H  (*(v_u8*)(0x47))
#define ICR1L  (*(v_u8*)(0x46))

/*Timer2 registers*/
#define TCCR2 (*(v_u8*)(0x45))

#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM20   4
#define COM21   5
#define WGM20   6
#define FOC2    7

#define TCNT2 (*(v_u8*)(0x44))

#define OCR2  (*(v_u8*)(0x43))


typedef enum
{
	Normal,
	PWM_PhaseCorrect,
	CTC,
	Fast_PWM
}
Timer_Mode;

typedef enum
{
	Disconnected,     /*Normal port operation, OCx disconnected*/
	Toggle,           /*Toggle OCx on compare match (Non PWM). Reserved (PWM)*/
	Clear,            /*Clear OCx on compare match (Non PWM). Clear OC0 on compare match, set OC0 at BOTTOM (PWM)*/
	Set               /*Set OCx on compare match (Non PWM). Set OC0 on compare match, clear OC0 at BOTTOM (PWM)*/
}
OC_Pin_Behaviour;

typedef enum
{
	No_Source,        /*No clock source (Timer/Counter stopped)*/
	No_PS,            /*Clk/1 (No prescaling)*/
	PS_8,             /*Clk/8 (From prescaler)*/
	PS_32,            /*Clk/32 (From prescaler)*/
	PS_64,            /*Clk/64 (From prescaler)*/
	PS_128,           /*Clk/128 (From prescaler)*/
	PS_256,           /*Clk/256 (From prescaler)*/
	PS_1024,          /*Clk/1024 (From prescaler)*/
	External_FE,      /*External clock source on T0 pin. Clock on falling edge*/
	External_RE       /*External clock source on T0 pin. Clock on rising edge*/
}
Clock_Source;

typedef enum
{
	Disable,          /*Disable all timer interrupts*/
	Enable_OF,        /*Timer overflow interrupt enable*/
	Enable_CM,        /*Timer compare match interrupt enable*/
	Enable_both       /*Both timer overflow and compare match interrupt enable*/
}
Timer_Interrupt;

typedef enum
{
	Falling,
	Rising
}
Triggering_Edge;

typedef enum
{
	Disabled,
	Enabled
}
State;

typedef struct
{
	Timer_Mode           Mode;
	OC_Pin_Behaviour     OCx;
	Clock_Source         Source;
	Timer_Interrupt      Interrrupt;
}
Timer_Info;


#endif
