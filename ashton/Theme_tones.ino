
#include "pitches.h" //add Equivalent frequency for musical note
#include "themes.h" //add Note vale and duration 
#include <Adafruit_NeoPixel.h>

#define TONE_PIN 33
#define LED_PIN  5
#define LED_COUNT 10

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void pixel_draw(int adc_value, int tone_value) {
  strip.setBrightness(map(adc_value,0,4095,0,255));
  uint32_t color = strip.ColorHSV(map(tone_value,31,1047,0,65536));
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
//    strip.show();                          //  Update strip to match
//    delay(wait);                           //  Pause for a moment
  }
  strip.show();
}

void Play_Pirates()
{ 
  for (int thisNote = 0; thisNote < (sizeof(Pirates_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / Pirates_duration[thisNote];//convert duration to time delay
    tone(TONE_PIN, Pirates_note[thisNote], noteDuration);
    pixel_draw(analogRead(14),Pirates_note[thisNote]);
    int pauseBetweenNotes = noteDuration * 1.05; //Here 1.05 is tempo, increase to play it slower
    delay(pauseBetweenNotes);
    noTone(TONE_PIN); //stop music on pin 8 
    }
}

void Play_CrazyFrog()
{
  for (int thisNote = 0; thisNote < (sizeof(CrazyFrog_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / CrazyFrog_duration[thisNote]; //convert duration to time delay
    tone(TONE_PIN, CrazyFrog_note[thisNote], noteDuration);
    pixel_draw(analogRead(14),Pirates_note[thisNote]);
    int pauseBetweenNotes = noteDuration * 1.30;//Here 1.30 is tempo, decrease to play it faster
    delay(pauseBetweenNotes);
    noTone(TONE_PIN); //stop music on pin 8 
    }
}

void Play_MarioUW()
{
    for (int thisNote = 0; thisNote < (sizeof(MarioUW_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / MarioUW_duration[thisNote];//convert duration to time delay
    tone(TONE_PIN, MarioUW_note[thisNote], noteDuration);
    pixel_draw(analogRead(14),Pirates_note[thisNote]);
    int pauseBetweenNotes = noteDuration * 1.80;
    delay(pauseBetweenNotes);
    noTone(TONE_PIN); //stop music on pin 8 
    }
}

void Play_Titanic()
{
    for (int thisNote = 0; thisNote < (sizeof(Titanic_note)/sizeof(int)); thisNote++) {

    int noteDuration = 1000 / Titanic_duration[thisNote];//convert duration to time delay
    tone(TONE_PIN, Titanic_note[thisNote], noteDuration);
    pixel_draw(analogRead(14),Pirates_note[thisNote]);
    int pauseBetweenNotes = noteDuration * 2.70;
    delay(pauseBetweenNotes);
    noTone(TONE_PIN); //stop music on pin 8 
    }
}


void setup() {
  pinMode(9, INPUT_PULLUP); //Button 1 with internal pull up
  pinMode(10, INPUT_PULLUP); //Button 2 with internal pull up
  //pinMode(4, INPUT_PULLUP); //Button 3 with internal pull up
  //pinMode(5, INPUT_PULLUP); //Button 4 with internal pull up
  Serial.begin(115200);
  
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
      if (digitalRead(9) == 0 && digitalRead(10) == 0) {
         Serial.println("Selected -> 'He is a Pirate' ");  Play_Pirates();
      }
      if (digitalRead(9) == 0 && digitalRead(10) == 1) {
         Serial.println("Selected -> 'Crazy Frog' ");  Play_CrazyFrog();
      }
      if (digitalRead(9) == 1 && digitalRead(10) == 0) {
         Serial.println("Selected -> 'Mario UnderWorld' ");  Play_MarioUW();
      }
      if (digitalRead(9) == 1 && digitalRead(10) == 1) {
         Serial.println("Selected -> 'Titanic' ");  Play_Titanic();
      }

//    if (digitalRead(2)==0)
//      { Serial.println("Selected -> 'He is a Pirate' ");  Play_Pirates();  }
//    if (digitalRead(3)==0)
//      { Serial.println("Selected -> 'Crazy Frog' ");  Play_CrazyFrog();  }
//    if (digitalRead(4)==0)
//      { Serial.println("Selected -> 'Mario UnderWorld' ");  Play_MarioUW();  }
//    if (digitalRead(5)==0)
//      { Serial.println("Selected -> 'Titanic' ");  Play_Titanic();  }
 
}
