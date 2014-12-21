const int ledPin =  13;
int speakerPin = 5;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  playmelody();
}

void loop() {

}

void playmelody(){
  //
}

void playnote(int note, int duration){
  tone(speakerPin,note,duration);
  delay(duration);
}
