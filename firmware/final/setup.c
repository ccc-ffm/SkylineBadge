#include "setup.h"
#include "ports.h"
#include <avr/io.h>
void
led_port_setup ()
{
	//LED_PORT as Output
    LED_DIR = 0x3F;
    
    //Activate all LEDs
    LED_PORT = 0x3F;
}

void
timer_setup()
{
    OCR0A  = 0xFF;
    /*Compare Match (CTC) mode*/
    TCCR0A = 0x02;
	/*Clear interrupt flag*/
    TIFR |= 0x01; 
    /*TC0 compare match A Interrupt*/
    TIMSK = 0x01;
	/*Clock source CLK/1024, start timer*/
    TCCR0B = 0x05;      
}
