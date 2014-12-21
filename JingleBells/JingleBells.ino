//inspired by http://blog.pluralsight.com/arduino-jingle-bells

const int ledPin =  13;
int speakerPin = 5;

//tempo
int eighth = 0;
int quarter = 2;
int dottedquarter = 3;
int half = 4;
int whole = 8;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  setuptempo(250);
  playmelody();
}

void loop() {

}

void playmelody(){
  playnote(NOTE_E4,quarter);
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
