#include "Arduino.h"

#include "ybadge.h"

int main();

void setup() {
  Serial.begin(9600);
  leds_init();
  timer_init();
  delay(1000);
  main();
  while (1)
    ;
}
void loop() {}
