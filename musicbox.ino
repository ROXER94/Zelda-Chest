#include "pitches.h"

// Speaker connected to digital D0
const int Speaker = D0;

const int RangeFinder = A0;

const int Light1 = D1;
const int Light2 = D2;
const int Light3 = D3;

//chest melody song from The Legend of Zelda Series
int melody[] = {
  NOTE_G3,NOTE_A3,NOTE_B3,NOTE_CS4,
  NOTE_G3,NOTE_A3,NOTE_B3,NOTE_C4,
  NOTE_GS3,NOTE_AS3,NOTE_C4,NOTE_D4,
  NOTE_A3,NOTE_B3,NOTE_C4,NOTE_D4,
  NOTE_A3,NOTE_B3,NOTE_CS4,NOTE_DS4,
  NOTE_A3,NOTE_B3,NOTE_C4,NOTE_D4,
  NOTE_AS3,NOTE_C4,NOTE_D4,NOTE_E4,
  NOTE_B3,NOTE_C4,NOTE_D4,NOTE_E4,
  NOTE_B3,NOTE_CS4,NOTE_DS4,NOTE_E4,
  NOTE_C4,NOTE_D4,NOTE_E4,NOTE_FS4,
  NOTE_CS4,NOTE_DS4,NOTE_F4,NOTE_G4,
  NOTE_D4,NOTE_E4,NOTE_FS4,NOTE_GS4,
  0, NOTE_A3,NOTE_AS3,NOTE_B3,NOTE_C4
};

int noteDurations[] = {
  8,8,8,8,
  8,8,8,8,
  8,8,8,8,
  8,8,8,8,
  8,8,8,8,
  8,8,8,8,
  8,8,8,8,
  8,8,8,8,
  8,8,8,8,
  8,8,8,8,
  8,8,8,8,
  8,8,8,8,
  2,4,4,4,4
};

void setup() {
// initialize the Speaker pin as an output:
pinMode(Speaker, OUTPUT);
// initialize the Light pin as an output:
pinMode(Light1,OUTPUT);
pinMode(Light2,OUTPUT);
pinMode(Light3,OUTPUT);

// Set up serial communication
Serial.begin(9600);
}

void Zelda() {
  for (int thisNote = 0; thisNote < 53; thisNote++) {

    int noteDuration = 1000/noteDurations[thisNote];
    tone(Speaker, melody[thisNote], noteDuration);
    //tone(Speaker2, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(Speaker);
  }
  digitalWrite(Light1, LOW);
  digitalWrite(Light2, LOW);
  digitalWrite(Light3, LOW);
}

void loop() {

digitalWrite(Light1, LOW);
digitalWrite(Light2, LOW);
digitalWrite(Light3, LOW);

int value = analogRead(RangeFinder);
float volts = (value/4095.0)*2.3;
long IN = ((70.0/volts)-6.0)*0.393701;//Hand position
Serial.println(IN);

if (IN > 50 && IN < 125) {
  digitalWrite(Light1, HIGH);
  digitalWrite(Light2, HIGH);
  digitalWrite(Light3, HIGH);
  Zelda();
}

delay(1250);

}
