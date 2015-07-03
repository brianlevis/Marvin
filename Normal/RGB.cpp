#include "Arduino.h"
#include "pitches.h"
#include "pins.h"

void RGBTest() {
  analogWrite(PIN_R, 0);
  delay(1000);
  analogWrite(PIN_R, 255);
  analogWrite(PIN_G, 0);
  tone(PIN_PIEZO, NOTE_A7, 1000);
  delay(1000);
  analogWrite(PIN_G, 255);
  analogWrite(PIN_B, 0);
  tone(PIN_PIEZO, NOTE_A6, 1000);
  delay(1000);
  analogWrite(PIN_B, 255);
}
