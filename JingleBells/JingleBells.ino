//inspired by http://blog.pluralsight.com/arduino-jingle-bells

const int ledPin =  13;
int speakerPin = 5;

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
  setuptempo(100);
  playmelody();
}

void loop() {

}

void playmelody(){
  /* jingle bells */
  
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,half);
  
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,half);
  
  playnote(NOTE_E4,quarter);
  playnote(NOTE_G4,quarter);
  playnote(NOTE_C4,dottedquarter);
  playnote(NOTE_D4,eighth);
  
  playnote(NOTE_E4,whole);
  
  playnote(NOTE_F4,quarter);
  playnote(NOTE_F4,quarter);
  playnote(NOTE_F4,quarter);
  playnote(NOTE_F4,quarter);
  
  playnote(NOTE_F4,quarter);
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,half);
  
  playnote(NOTE_E4,quarter);
  playnote(NOTE_D4,quarter);
  playnote(NOTE_D4,quarter);
  playnote(NOTE_E4,quarter);
  
  playnote(NOTE_D4,half);
  playnote(NOTE_G4,half);
  
  /* second verse */
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,half);
  
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,half);
  
  playnote(NOTE_E4,quarter);
  playnote(NOTE_G4,quarter);
  playnote(NOTE_C4,dottedquarter);
  playnote(NOTE_D4,eighth);
  
  playnote(NOTE_E4,whole);
  
  playnote(NOTE_F4,quarter);
  playnote(NOTE_F4,quarter);
  playnote(NOTE_F4,quarter);
  playnote(NOTE_F4,quarter);
  
  playnote(NOTE_F4,quarter);
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,eighth);
  playnote(NOTE_E4,eighth);
  
  playnote(NOTE_G4,quarter);
  playnote(NOTE_G4,quarter);
  playnote(NOTE_F4,quarter);
  playnote(NOTE_D4,quarter);
  
  playnote(NOTE_C4,whole);
}

void playnote(int note, int duration){
  tone(speakerPin,note,duration);
  delay(duration);
}

void setuptempo(int starter)
{
  eighth = starter;
  quarter = quarter*starter;
  dottedquarter = dottedquarter*starter;
  half = half*starter;
  whole = whole*starter;
}
