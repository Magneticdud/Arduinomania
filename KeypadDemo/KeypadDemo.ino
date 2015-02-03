//Demo for Arduino analog keypad breakout
//$3.25 from here http://bit.ly/1ysFtHD

int keyPin = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //set baud rate for USB serial
  Serial.println("Serial start");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(keyPin));
  delay(200);
}
