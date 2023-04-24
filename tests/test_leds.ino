#include <Adafruit_NeoPixel.h>

#define LED_PIN  5
#define LED_COUNT 10

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
    strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  int i = 0;
  for (int i = 0; i < LED_COUNT; i++) {
    int r = i & 4 ? 255 : 0;
    int g = i & 2 ? 255 : 0;
    int b = i & 1 ? 255 : 0;
    strip.setPixelColor(i, r, g, b);
    strip.show(); // This sends the updated pixel color to the hardware.
    
  }

  // printf("Done setup\n");
}

void loop() {}
