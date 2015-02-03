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
int tolerance = 5;
int pressedkey = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //set baud rate for USB serial
  Serial.println("Serial start");
}

void loop() {
  // put your main code here, to run repeatedly:
  pressedkey = analogRead(keyPin);
  if (pressedkey < 1023+tolerance && pressedkey > 1023-tolerance)
    Serial.println("Nothing pressed");
  else if (pressedkey < 738+tolerance && pressedkey > 738-tolerance)
    Serial.println("Button pressed");
  else if (pressedkey < 500+tolerance && pressedkey > 500-tolerance)
    Serial.println("R pressed");
  else if (pressedkey < 325+tolerance && pressedkey > 325-tolerance)
    Serial.println("DOWN pressed");
  else if (pressedkey < 141+tolerance && pressedkey > 141-tolerance)
    Serial.println("UP pressed");
  else if (pressedkey >= 0 && pressedkey < tolerance)
    Serial.println("L pressed");
  else
    Serial.println("Nothing connected to analog input");
  //Serial.println(analogRead(keyPin));
  delay(200);
}
