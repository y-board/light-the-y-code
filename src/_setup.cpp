#include "Arduino.h"

#include "main.h"

#include "yboard.h"

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