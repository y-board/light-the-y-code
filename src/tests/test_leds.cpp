#include "yboard.h"

void test_leds() {
  Serial.println("Running LED test.");

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  int i = 0;
  int led_val = 0;
  for (int i = 0; i < LED_COUNT; i++, led_val++) {
    if (!(led_val & 0x07))
      led_val++;
    int r = led_val & 4 ? 255 : 0;
    int g = led_val & 2 ? 255 : 0;
    int b = led_val & 1 ? 255 : 0;
    strip.setPixelColor(i, r, g, b);
    strip.show(); // This sends the updated pixel color to the hardware.
  }
  Serial.println("LED test complete.");
}