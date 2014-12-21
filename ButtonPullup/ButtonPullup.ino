void setup() {
  pinMode(13, OUTPUT); // Use Built-In LED for Indication
  pinMode(12, INPUT_PULLUP);   // Push-Button On Bread Board
}
 
void loop() {
  bool buttonState = digitalRead(12);  // store current state of pin 12
  digitalWrite(13, buttonState);
}
