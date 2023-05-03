

#include "Arduino.h"
#include "tests/test_leds.h"
#include "yboard.h"

void ex1() {
  leds_set_color(1, 255, 0, 0);
  leds_set_color(13, 0, 255, 0);
  leds_set_color(17, 0, 0, 255);
  while (1)
    ;
}

void ex2() {
  leds_set_color(5, 255, 0, 0);
  delay(2000);
  leds_set_color(5, 0, 0, 0);
  leds_set_color(6, 255, 0, 0);
  delay(2000);
  leds_set_color(6, 0, 0, 0);
  leds_set_color(7, 255, 0, 0);
  delay(2000);
  leds_set_color(7, 0, 0, 0);
  leds_set_color(8, 255, 0, 0);
  delay(2000);
  leds_set_color(8, 0, 0, 0);
  leds_set_color(9, 255, 0, 0);
  delay(2000);
  leds_set_color(9, 0, 0, 0);
  while (1)
    ;
}

void ex3() {}

int main() {
  // ex1();
  // ex2();
  ex3();

  test_leds();

  while (1) {
    delay(1000);
    Serial.println("hi");
  }
}
