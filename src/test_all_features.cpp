#include "yboard.h"

int get_brightness();
bool check_switches();

/*
 * This function tests all of the features of the badge.
 * It will display different colors depending on which button is pressed.
 * It will also play different notes depending on which button is pressed IF at least one of the two
 * switches is on It will also change the brightness of the LEDs depending on the position of the
 * knob.
 */
void test_all_features() {
    while (true) {
        if (Yboard.get_button(1)) {
            while (Yboard.get_button(1)) {
                Yboard.set_all_leds_color(255, 0, 0);
                Yboard.set_led_brightness(get_brightness());
                if (check_switches()) {
                    Yboard.play_note(NOTE_C4, 10);
                }
            }
        } else if (Yboard.get_button(2)) {
            while (Yboard.get_button(2)) {
                Yboard.set_all_leds_color(255, 255, 0);
                Yboard.set_led_brightness(get_brightness());
                if (check_switches()) {
                    Yboard.play_note(NOTE_D4, 10);
                }
            }
        } else if (Yboard.get_button(3)) {
            while (Yboard.get_button(3)) {
                Yboard.set_all_leds_color(0, 255, 0);
                Yboard.set_led_brightness(get_brightness());
                if (check_switches()) {
                    Yboard.play_note(NOTE_E4, 10);
                }
            }
        } else {
            Yboard.set_all_leds_color(255, 255, 255);
            Yboard.set_led_brightness(get_brightness());
        }
    }
}

// This function converts the knob's output (1-100) to a brightness value (0-255)
int get_brightness() {
    int brightness = 255 * Yboard.get_knob() / 100;
    return floor(brightness);
}

// This function checks if either of the switches are on
bool check_switches() { return Yboard.get_switch(1) || Yboard.get_switch(2); }
