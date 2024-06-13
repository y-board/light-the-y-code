#include "Arduino.h"

#include "yboard.h"

int main();

void setup() {
    Serial.begin(9600);
    Yboard.setup();
    delay(1000);
    main();
    while (1)
        ;
}
void loop() {}
