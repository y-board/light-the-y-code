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