const int ledPin =  13;
int speakerPin = 8;

#include "tone.h"

//tempo
int eighth = 0;
int quarter = 2;
int dottedquarter = 3;
int half = 4;
int whole = 8;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,HIGH);
  setuptempo(150);
  playmelody();
  digitalWrite(ledPin,LOW);
}

void loop() {

}

void playmelody(){
  /* payphone */
  
  playnote(NOTE_FS4,quarter);
  playnote(NOTE_G4,quarter);
  playnote(NOTE_A4,quarter);
  playnote(NOTE_E5,dottedquarter);
  playnote(NOTE_E5,quarter);
  playnote(NOTE_D5,half);
  
  playnote(NOTE_D5,quarter);
  playnote(NOTE_CS5,quarter);
  playnote(NOTE_A4,quarter);
  playnote(NOTE_G4,dottedquarter);
  playnote(NOTE_G4,quarter);
  
  playnote(NOTE_G4,half);
  playnote(NOTE_G4,quarter);
  playnote(NOTE_FS4,quarter);
  playnote(NOTE_D4,quarter);
  playnote(NOTE_G4,dottedquarter);
  playnote(NOTE_G4,quarter);
  
  playnote(NOTE_FS4,half);
  playnote(NOTE_E4,eighth);
  playnote(NOTE_E4,quarter);
  playnote(NOTE_D4,quarter);
  playnote(NOTE_FS4,quarter);
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,half);
}

void playnote(int note, int duration){
  tone(speakerPin,note,duration);
  delay(duration+10);
}

void setuptempo(int starter)
{
  eighth = starter;
  quarter = quarter*starter;
  dottedquarter = dottedquarter*starter;
  half = half*starter;
  whole = whole*starter;
}
