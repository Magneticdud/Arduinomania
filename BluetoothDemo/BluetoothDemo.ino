//disconnect hc-06 when uploading
//pin LED
const int ledPin = 4;
String message; //string that stores the incoming message
 
void setup()
{
  Serial.begin(9600); //set baud rate
  pinMode(ledPin, OUTPUT);
}
 

void loop() {
  while(Serial.available())
  {//while there is data available on the serial monitor
    message+=char(Serial.read());//store string from serial command
  digitalWrite(ledPin, HIGH);
  }
  if(!Serial.available())
  {
    if(message!="")
    {//if data is available
      Serial.println(message); //show the data
      message=""; //clear the data
    }
  }
  delay(5000); //delay
}
