#include <SoftwareSerial.h>
//pins for software serial
const int rxPin = 2;
const int txPin = 3;
//pin LED
const int ledPin = 4;
SoftwareSerial bluetooth(rxPin, txPin);
int message; //string that stores the incoming message
 
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
    Serial.println(message);
    if (message==65){ //capital A
      digitalWrite(ledPin, LOW);
    }
    else if (message==79){ //capital O
      digitalWrite(ledPin, HIGH);
    }
    if (Serial.available()) {
    bluetooth.write(Serial.read());
    }
  }
}
