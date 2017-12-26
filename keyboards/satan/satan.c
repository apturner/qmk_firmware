#include "satan.h"
#include "led.h"

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();
	led_init_ports();
};

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)
	matrix_scan_user();
};

#ifdef BACKLIGHT_CAPS
uint8_t backlight_on;
ISR(TIMER1_COMPB_vect)
{
    led_set_kb(~(1 << USB_LED_BL));
}

ISR(TIMER1_OVF_vect)
{
    if (OCR1B != 0)
        led_set_kb(1 << USB_LED_BL);
}
#endif

void led_init_ports(void) {
    // * Set our LED pins as output
    DDRB |= (1<<2);
    #ifdef BACKLIGHT_CAPS
        // register the required ISRs
        TIMSK1 |= _BV(OCIE1B) | _BV(TOIE1);
    #endif
}

void led_set_kb(uint8_t usb_led) {
    #ifndef BACKLIGHT_CAPS
        if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
            // Turn capslock on
            PORTB &= ~(1<<2);
        } else {
            // Turn capslock off
            PORTB |= (1<<2);
        }
    #endif
    #ifdef BACKLIGHT_CAPS
        if (usb_led & (1 << USB_LED_BL)) {
            // Turn capslock on
            PORTB &= ~(1<<2);
        } else {
            // Turn capslock off
            PORTB |= (1<<2);
        }
    #endif
}
