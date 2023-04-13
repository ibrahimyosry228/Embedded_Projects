#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_


#define NULL (void*)(0x0)

#define DDRA (*(v_u8*)(0x3A))
#define DDRB (*(v_u8*)(0x37))
#define DDRC (*(v_u8*)(0x34))
#define DDRD (*(v_u8*)(0x31))

#define PORTA (*(v_u8*)(0x3B))
#define PORTB (*(v_u8*)(0x38))
#define PORTC (*(v_u8*)(0x35))
#define PORTD (*(v_u8*)(0x32))

#define PINA (*(v_u8*)(0x39))
#define PINB (*(v_u8*)(0x36))
#define PINC (*(v_u8*)(0x33))
#define PIND (*(v_u8*)(0x30))

typedef enum
{
	DIO_Input,
	DIO_Output,
	DIO_PortInput  = 0x00,
	DIO_PortOutput = 0xFF
}
Direction;


typedef enum
{
	Pin_Low,
	Pin_High,
	Port_Low  = 0x00,
	Port_High = 0xFF
}
Value;


typedef enum
{
	DIO_PortA,
	DIO_PortB,
	DIO_PortC,
	DIO_PortD
}
PortNumber;


typedef enum
{
	DIO_Pin0,
	DIO_Pin1,
	DIO_Pin2,
	DIO_Pin3,
	DIO_Pin4,
	DIO_Pin5,
	DIO_Pin6,
	DIO_Pin7
}
PinNumber;


#endif
