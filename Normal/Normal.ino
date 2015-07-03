#include <Servo.h>

#include "pitches.h"
#include "pins.h"

#include "RGB.h"
#include "Speaker.h"
#include "IR.h"


byte R;  byte G; byte B;
int happiness;
int lonliness;
int alertness;

//void startUp();
void playLonelyMusic();

// ***** SERVO CONTROLS *****
/* I couldn't figure out how
 * to use Servo.h in a
 * separate file.
 */
Servo eyes;

#define LEFT     -1
#define CENTER    0
#define RIGHT     1

const int servoDelay = 100;
const int servoRange = 20;
const int servoCenter = 100;
int servoPosition = servoCenter;
int servoDirection = CENTER;

void look(int dir) {
  if(servoPosition != servoCenter + dir * servoRange) {
    servoPosition += dir;
    if(dir == 0) {
      int disc = servoCenter - servoPosition;
      servoPosition += disc / abs(disc);
    }
    eyes.write(servoPosition);
  }
}
// **************************

void setup() {
  pinMode(PIN_IRR, INPUT);
  pinMode(PIN_PIR, INPUT);
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  eyes.attach(PIN_EYES);
  pinMode(PIN_TEST, OUTPUT);
  analogWrite(PIN_B, 255);
  analogWrite(PIN_G, 255);
  analogWrite(PIN_R, 255);
  look(servoDirection);
  Serial.begin(9600);
  //startUp();
  //RGBTest();
  playLonelyMusic();
  //IRTest();
}

void updateMood() {
  
}

void loop() {
  //playLonelyMusic();
  look(servoDirection);
  updateMood();
  
  //if(
  
  tone(PIN_IRR, 38000, 8);
  delay(1);
  int value = digitalRead(PIN_RECR);
  analogWrite(PIN_R, 255 * value);
  delay(10);
  tone(PIN_IRL, 38000, 8);
  delay(1);
  servoDirection = -value;
  value = digitalRead(PIN_RECL);
  analogWrite(PIN_B, 255 * value);
  servoDirection += value;
  
  
  value = digitalRead(PIN_PIR);
  analogWrite(PIN_G, 255 * !value);
  delay(10);
  if(analogRead(PIN_PHOTO) < 100) tone(PIN_PIEZO, NOTE_B4, 30);
  delay(8);
  //eyes.write(90);
}
