#ifndef YBOARD_H
#define YBOARD_H


// Buzzer pin: 33
// LEDs pin: 5
// Switch1 pin: 9
// Switch2 pin: 10
// Button1 pin: 11
// Button2 pin: 12
// Button3 pin: 13

#define LED_PIN 5
#define LED_COUNT 20

////////////////////////////// LEDs ///////////////////////////////////////////
void leds_init();
void leds_set_brightness(uint8_t brightness);
void leds_set_color(uint16_t index, uint8_t red, uint8_t green, uint8_t blue);

#endif /* YBOARD_H */
