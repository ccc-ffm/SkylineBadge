/*Firmware for hardware testing.
 *Enable all LEDs
 *Print '*cccffm*' on LCD
 *LCD Libraries from Peter Fleury http://homepage.hispeed.ch/peterfleury/avr-software.html#libs
 */

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

#define F_CPU = 8000000
#define LED_DIR DDRB
#define LED_PORT PORTB

int main() {

	/*Set Direction - Output*/
	LED_DIR = 0x3F;
    
	/*Turn on all LEDs*/
	LED_PORT = 0x3F;

	/*LCD init*/
	lcd_init(LCD_DISP_ON);
	
	/*Just to be sure*/
	_delay_ms(10);
        
	/*Display something*/
	lcd_puts("*cccffm*");
	lcd_gotoxy(0,1);
	lcd_puts("*cccffm*");   
     
    /* loop forever */ 
	while(1){}
return 0;
}
