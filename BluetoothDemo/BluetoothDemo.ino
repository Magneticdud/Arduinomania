#include <SoftwareSerial.h>
//pins for software serial
const int rxPin = 2;
const int txPin = 3;
//pin LED
const int ledPin = 4;
SoftwareSerial bluetooth(rxPin, txPin);
char message; //char incoming on serial
//String fullcontent = ""; //string that could contain the whole nesage

 
void setup()
{
  Serial.begin(9600); //set baud rate for USB serial
  bluetooth.begin(9600);
  pinMode(ledPin, OUTPUT);
}
 

void loop() {
  //scrivo e leggo nelle seriali, condividendo i flussi tra le due.
  if (bluetooth.available()) {
    message = bluetooth.read();
    //fullcontent.concat(message); //don't need to do this yet - it's from here http://stackoverflow.com/questions/5697047/convert-serial-read-into-a-useable-string-using-arduino
    
    Serial.println(message);
    if (message=='5'){
      digitalWrite(ledPin, LOW);
    }
    else if (message=='9'){
      digitalWrite(ledPin, HIGH);
    }
    if (Serial.available()) {
    bluetooth.write(Serial.read());
    }
  }
}
