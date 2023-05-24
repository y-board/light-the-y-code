#include "ybadge.h"

void loop_exploration();
void loop_challenge1();
void loop_challenge2();
void loop_challenge3();

void loop_activity() {
    // This function should call ONE of your functions below.
    // Uncomment or comment the lines so that just the function
    // you want to call is uncommented.

    loop_exploration();
    // loop_challenge1();
    // loop_challenge2();
    // loop_challenge3();
}

void loop_exploration() {
    // Add your code here for exploration activities
    while(true) {
        for(int i = 20; i >= 1; --i) {
            leds_set_color(i, 255, 255, 255);
            delay(100);
            leds_set_color(i, 0, 0, 0);
        }
    }
}

void loop_challenge1() {
    // Add your code here for challenge 1
}

void loop_challenge2() {
    // Add your code here for challenge 2
}

void loop_challenge3() {
    // Add your code here for challenge 3
}