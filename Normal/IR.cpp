#include "Arduino.h"
#include "pins.h"

bool detectLeft() {
  tone(PIN_IRL, 38000, 8);
  delay(1);
  return digitalRead(PIN_RECL);
}

bool detectRight() {
  tone(PIN_IRR, 38000, 8);
  delay(1);
  return digitalRead(PIN_RECR);
}
