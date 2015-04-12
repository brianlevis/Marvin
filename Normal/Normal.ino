#include <Servo.h>
#include "pitches.h"

Servo eyes;

#define PIN_PHOTO 0

#define PIN_IRL   3
#define PIN_IRR   4
#define PIN_RECL  5
#define PIN_RECR  6
#define PIN_PIEZO 7
#define PIN_PIR   8
#define PIN_R     9
#define PIN_B    10
#define PIN_G    11
#define PIN_EYES 12
#define PIN_TEST 13

void startUp() {
  for(int i = 400; i < 1000; i++) {
    tone(PIN_PIEZO, i, 5);
    delay(6);
  }
  for(int i = 700; i < 1200; i++) {
    tone(PIN_PIEZO, i, 5);
    delay(6);
  }
  for(int i = 1000; i < 1500; i++) {
    tone(PIN_PIEZO, i, 5);
    delay(6);
  }
  for(int i = 1500; i > 1000; i--) {
    tone(PIN_PIEZO, i, 5);
    delay(6);
  }
  for(int c = 0; c < 3; c++)
  for(int i = 2000; i < 2500; i += 10){
    tone(PIN_PIEZO, i, 5);
    delay(6);
  }
  for(int c = 0; c < 3; c++)
  for(int i = 3000; i < 3500; i += 10){
    tone(PIN_PIEZO, i, 5);
    delay(6);
  }
  for(int c = 0; c < 3; c++)
  for(int i = 2000; i < 2500; i += 10){
    tone(PIN_PIEZO, i, 5);
    delay(6);
  }
  for(int c = 0; c < 3; c++)
  for(int i = 3000; i < 3500; i += 10){
    tone(PIN_PIEZO, i, 5);
    delay(6);
  }
  tone(PIN_PIEZO, NOTE_A4, 1000);
  /*int melody[] = {NOTE_FS3, NOTE_CS3, NOTE_CS3, NOTE_E3, NOTE_FS3, NOTE_GS3, NOTE_B4, NOTE_C4, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_B5};
  int noteDurations[] = {8, 8, 16, 16, 16, 16, 16, 4, 4, 6, 12, 4, 4};
  
  for (int thisNote = 0; thisNote < 13; thisNote++) {
    int noteDuration = (1000 + 1000) / noteDurations[thisNote];
    tone(PIN_PIEZO, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(PIN_PIEZO);
  }*/
}

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

void IRTest() {
  analogWrite(PIN_R, digitalRead(PIN_IRR) * 255);
  delay(1000);
}

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
  eyes.write(90);
  Serial.begin(9600);
  startUp();
  RGBTest();
  //IRTest();
}

void loop() {
  tone(PIN_IRR, 38000, 8);
  delay(1);
  int value = digitalRead(PIN_RECR);
  analogWrite(PIN_R, 255 * value);
  delay(10);
  tone(PIN_IRL, 38000, 8);
  delay(1);
  value = digitalRead(PIN_RECL);
  analogWrite(PIN_B, 255 * value);
  
  value = digitalRead(PIN_PIR);
  analogWrite(PIN_G, 255 * !value);
  delay(10);
  if(analogRead(PIN_PHOTO) < 100) tone(PIN_PIEZO, NOTE_B4, 30);
  delay(10);
  //eyes.write(90);
}
