/*
  DoubleBlink
  Turns on two LEDs and writes stuff over the serial LED on for one second
*/


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 10 and 13 as an output.
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  //enable serial communication
  Serial.begin(9600);
  Serial.println("SERIAL.COMMUNICATION.ENABLED.");
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println("I TURN ON THE LED!!!!1");
  delay(500);              // wait for a second
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  delay(200);              // wait for a second
}
