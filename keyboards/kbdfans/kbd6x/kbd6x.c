/* Copyright 2018 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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
#include "kbd6x.h"

#ifdef RGBLIGHT_ENABLE
#   include "rgblight.h"
extern rgblight_config_t rgblight_config;
#endif

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRB |= (1 << 6);
		PORTB &= ~(1 << 6);
    #ifdef RGBLIGHT_ENABLE
      //Set color to purple.
      rgblight_setrgb(153, 51, 255);
      rgblight_enable();

    #endif
	} else {
		DDRB &= ~(1 << 6);
		PORTB &= ~(1 << 6);
    #ifdef RGBLIGHT_ENABLE
      rgblight_disable();
    #endif
	}

	led_set_user(usb_led);
}
