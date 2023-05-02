
#include "tests/test_leds.h"

#include "Arduino.h"

int main() {
  delay(1000);
  test_leds();

  while (1) {
    delay(1000);
    Serial.println("hi");
  }
}
