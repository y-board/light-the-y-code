#include "yboard.h"

#include <Adafruit_NeoPixel.h>

////////////////////////////// LEDs ///////////////////////////////////////////

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void leds_init() {
  strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void leds_set_brightness(uint8_t brightness) {
  strip.setBrightness(brightness);
}

void leds_set_color(uint16_t index, uint8_t red, uint8_t green, uint8_t blue) {
  strip.setPixelColor(index - 1, red, green, blue);
  strip.show();
}

hw_timer_t *interrupt_timer = NULL;

void timer_isr() {}
void timer_init() {
  // Prescaler = 80, So timer clock = 80MHZ/80 = 1MHz = 1us period
  interrupt_timer = timerBegin(0, 80, true);

  timerAttachInterrupt(interrupt_timer, &timer_isr, true);

  // Alarm runs every 10 cycles.  1us * 10 = 100us period
  timerAlarmWrite(interrupt_timer, 100, true);
}

void speaker_play_note(unsigned int freq, unsigned long duration) {
  tone(TONE_PIN, freq, duration);
}