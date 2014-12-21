int speakerPin = 5;

void setup() {
  pinMode(13, OUTPUT); // Use Built-In LED for Indication
  pinMode(12, INPUT_PULLUP);   // Push-Button On Bread Board
  pinMode(speakerPin, OUTPUT);
}
 
void loop() {
  bool buttonState = digitalRead(12);  // store current state of pin 12
  digitalWrite(13, !buttonState);
  if (!buttonState)
    tone(speakerPin,1500,10);
}
