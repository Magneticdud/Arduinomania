int xPin = A0;
int yPin = A1;
int xpos = 0;
int ypos = 0;
String outserial = "";
String xtring = "X ";
String ytring = " Y ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //set baud rate for USB serial
  Serial.println("Serial start");
}

void loop() {
  // put your main code here, to run repeatedly:
  xpos=analogRead(xPin);
  ypos=analogRead(yPin);
  outserial = xtring + xpos + ytring + ypos;
  Serial.println(outserial);
  delay(100);
}
