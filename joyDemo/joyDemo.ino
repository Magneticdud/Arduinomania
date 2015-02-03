//Demo for Arduino PS2 joypad breakout
//$1.66 from here http://bit.ly/1vTY4pa

int xPin = A0;
int yPin = A1;
int buttonPin = 5;
int xpos = 0;
int ypos = 0;
int buttonState = 0;
String outserial = "";
String xtring = "X ";
String ytring = " Y ";

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600); //set baud rate for USB serial
  Serial.println("Serial start");
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    Serial.println("Button pressed!!!!!11");
  }
  xpos=analogRead(xPin);
  ypos=analogRead(yPin);
  outserial = xtring + xpos + ytring + ypos;
  Serial.println(outserial);
  delay(200);
}
