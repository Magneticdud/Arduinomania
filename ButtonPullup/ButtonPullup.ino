int speakerPin = 5;

void setup() {
  pinMode(13, OUTPUT); // Use Built-In LED for Indication
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(speakerPin, OUTPUT);
}
 
void loop() {
  bool buttonState = digitalRead(12);  // store current state of pin 12
  bool buttonState2 = digitalRead(11);
  digitalWrite(13, !buttonState||!buttonState2);
  if (!buttonState||!buttonState2)
    tone(speakerPin,1500,10);
}
