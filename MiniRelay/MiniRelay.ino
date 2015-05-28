// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(7, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(7, HIGH);
  delay(10000);
  digitalWrite(7, LOW);
  delay(10000);
}
