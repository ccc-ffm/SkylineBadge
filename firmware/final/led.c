#include "led.h"
#include "ports.h"
#include <stdint.h>
#include <avr/io.h>

/*######################################################################
Toggle LEDs
Arguments: No
Return:  No
######################################################################*/
void
led_toggle() {
	
	   static uint8_t c = 0x00;
   
   if (c == 0x00)
		c = 0x01;
	else c <<= 1;
		LED_PORT = ~c;
}



