#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_


typedef struct
{
	PortNumber       LED_Port;
	PinNumber        LED_Pin;
	LED_Connection   ConnectionType;
}
Led_info;


#endif
