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
  playphone();
  delay(50);
  playphone();
  delay(500);
  
  playphone2();
  delay(500);
  playphone3();
  delay(500);
  playphone2();
  delay(500);
  playphone3();
  delay(500);
  
  playphone2();
  delay(500);
  playphone3();
  delay(500);
  playphone2();
  delay(50);
  playphone4();
  delay(50);
  
  playphone5();
  delay(50);
  playphone5();
  delay(50);
  playphone6();
  delay(50);
  playphone5();
  delay(50);
  playphone5();
  playnote(NOTE_G4,quarter);
  digitalWrite(ledPin,LOW);
}

void loop() {

}

void playphone(){
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

void playphone2(){
  /* payphone part 2 */
  
  playnote(NOTE_D4,eighth);
  playnote(NOTE_FS4,quarter);
  playnote(NOTE_A4,quarter);
  playnote(NOTE_A4,dottedquarter);
  playnote(NOTE_A4,quarter);
  playnote(NOTE_FS4,quarter);
  
  playnote(NOTE_E4,dottedquarter);
  playnote(NOTE_E4,quarter);
  playnote(NOTE_E4,quarter);
}

void playphone3(){
  /* payphone part 3 */
  
  playnote(NOTE_D4,eighth);
  playnote(NOTE_FS4,quarter);
  playnote(NOTE_A4,quarter);
  playnote(NOTE_A4,dottedquarter);
  playnote(NOTE_A4,quarter);
  playnote(NOTE_FS4,quarter);
  
  playnote(NOTE_E4,dottedquarter);
  playnote(NOTE_FS4,half);
}

void playphone4(){
  /* payphone part 4 */
  
  playnote(NOTE_G4,dottedquarter);
  playnote(NOTE_FS4,eighth);
  playnote(NOTE_D4,quarter);
  playnote(NOTE_D4,quarter);
  playnote(NOTE_G4,dottedquarter);
  playnote(NOTE_FS4,eighth);
  playnote(NOTE_FS4,quarter);
  playnote(NOTE_E4,quarter);
}

void playphone5(){
  /* payphone part 5 */
  playnote(NOTE_FS4,half);
  playnote(NOTE_FS4,half);
  playnote(NOTE_FS4,dottedquarter);
  playnote(NOTE_FS4,eighth);
  playnote(NOTE_FS4,quarter);
  playnote(NOTE_E4,quarter);
}

void playphone6(){
  /* payphone part 6 */
  playnote(NOTE_FS4,half);
  playnote(NOTE_FS4,half);
  playnote(NOTE_FS4,dottedquarter);
  playnote(NOTE_FS4,eighth);
  playnote(NOTE_FS4,quarter);
  playnote(NOTE_G4,quarter);
  playnote(NOTE_E4,half);
  playnote(NOTE_CS4,half);
  playnote(NOTE_CS4,dottedquarter);
  playnote(NOTE_D4,eighth);
  playnote(NOTE_D4,quarter);
  playnote(NOTE_A4,quarter);
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
