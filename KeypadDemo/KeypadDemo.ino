//Demo for Arduino analog keypad breakout
//$3.25 from here http://bit.ly/1ysFtHD
//readings:
//L 0
//R 500
//UP 141
//DOWN 325-326
//button 738
//nothing = 1023
//allow some tolerance (+-5? or probably it will fail reading when the switch is worn out
//double press doesn't work: it's just a resistor circuit,
//the current flows in the path of less resistance
//the button with the lowest value will always prevail in double press

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
