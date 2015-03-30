/*
 * CCCFFM Skylinebadge firmware
 * Copyright (C) 2015  Fabian Stahl <fabian.m.stahl@posteo.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

#include "lcd.h"
#include "led.h"
#include "flags.h"
#include "setup.h"
#include "config.h"

#include "shift.h"

int
main() {
	
	/*Timer setup*/
	timer_setup();
	
	/*LED Port setup*/
	led_port_setup();
	
	/*LCD setup*/
	lcd_init(LCD_DISP_ON);
	_delay_ms(15);

	lcd_gotoxy(0,0);
	lcd_puts(row0);
	lcd_gotoxy(0,1);
	lcd_puts(row1);
	
	/*Enable interrupts*/
    sei();
	
	/*Loop forever*/
	while(1) {
		
		if(toggle_flag == 1) {
			led_toggle();
			toggle_flag=0;
		}
		
		if(scroll_flag == 1) {
			
			if(scroll0 == 1){
				lcd_gotoxy(0,0);
				shift_left(row0);
				lcd_puts(row0);
			}
			
			if(scroll1 == 1){
				lcd_gotoxy(0,1);
				shift_left(row1);
				lcd_puts(row1);
				
			}
			scroll_flag=0;
		}
	}
	
	/* never reached */
	return 0;
}


/*Interrupt Service Routine for T0 Compare match*/
ISR (TIMER0_COMPA_vect) {
   
	timer_tick0++;
	timer_tick1++;
	
	if(timer_tick0 == 7)
	{
		toggle_flag = 1;
		timer_tick0 = 0;
	}
	
	if(timer_tick1 == 3)
	{
		scroll_flag = 1;
		timer_tick1 = 0;
	}
	
}

