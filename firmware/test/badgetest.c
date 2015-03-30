#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

#define LED_DIR DDRB
#define LED_PORT PORTB

int main() {
	
	//LED_PORT als Ausgänge setzen
    LED_DIR = 0x3F;
    
    //Alle LEDs anschalten
    LED_PORT = 0x3F;
	
	_delay_ms(100);
	lcd_init();
	_delay_ms(100);
	while(1) {
		lcd_print("#*#*#*#*");
		lcd_goto(2,0);
		lcd_print("#*#*#*#*");
		while(1);
	}

	return 0;
	
	/*never reached*/
	return 0;
}
