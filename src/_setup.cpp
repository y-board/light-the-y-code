#include "Arduino.h"

#include "main.h"

void setup() {
  Serial.begin(9600);

  main();
  while (1)
    ;
}
void loop() {}