#include "Arduino.h"
#include "pitches.h"
#include "pins.h"

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

// Song: Nobody knows de trouble I've seen
int lonelyMelody[] = {NOTE_A4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_C4, NOTE_A4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_A4,
                      NOTE_C5, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_A4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_C4,
                      NOTE_A4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4,
                      NOTE_A4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_C4, NOTE_A4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_F4
                      };
float lonelyDurations[] = {8, 4, 8, 3, 8, 6, 16, 4, 2, 8, 4, 8, 4, 4, 4, 1.5, 8, 4, 8, 3, 8, 6, 16, 4, 2, 3, 8, 4, 4, 2, 4, 4,
                           4, 4, 4, 4, 4, 4, 2, 2, 2, 1.5, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 1.5, 4, 8, 4, 8, 3, 8, 6, 16, 4, 2, 8, 4, 8, 4, 4, 4, 1.5,
                           8, 4, 8, 3, 8, 6, 16, 4, 2, 4, 6, 16, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 1.5, 4, 8, 8, 4, 4, 4, 8, 3, 2, 2, 2, 1.5, 4,
                           8, 4, 8, 3, 8, 6, 16, 4, 2, 8, 4, 8, 4, 4, 4, 1.5, 8, 4, 8, 3, 8, 16, 6, 4, 2, 4, 6, 16, 4, 4, 2, 4
                           };

void playLonelyMusic() {
  for (int thisNote = 0; thisNote < sizeof(lonelyMelody) / sizeof(int); thisNote++) {
    int noteDuration = (int)((3000.0) / lonelyDurations[thisNote]);
    if(lonelyMelody[thisNote] != 0)
      tone(PIN_PIEZO, lonelyMelody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.10;
    delay(pauseBetweenNotes);
    noTone(PIN_PIEZO);
  }
}
