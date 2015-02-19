#include "SIM900.h"
#include <SoftwareSerial.h>

int numdata;
char inSerial[40];
int i=0;

void setup() {
   Serial.begin(9600);
   Serial.println("GSM Shield testing.");
   //Start configuration of shield with baudrate.
   //For http uses is raccomanded to use 4800 or slower.
   if (gsm.begin(9600))
     Serial.println("\nstatus=READY");
   else Serial.println("\nstatus=IDLE");
}

void loop() {
     //Read for new byte on serial hardware,
     //and write them on NewSoftSerial.
     serialhwread();
     //Read for new byte on NewSoftSerial.
     serialswread();
}

void serialhwread()
{
     i=0;
     if (Serial.available() > 0) {
          while (Serial.available() > 0) {
               inSerial[i]=(Serial.read());
               delay(10);
               i++;
          }

          inSerial[i]='\0';
          if(!strcmp(inSerial,"/END")) {
               Serial.println("_");
               inSerial[0]=0x1a;
               inSerial[1]='\0';
               gsm.SimpleWriteln(inSerial);
          }
          //Send a saved AT command using serial port.
          if(!strcmp(inSerial,"TEST")) {
               Serial.println("SIGNAL QUALITY");
               gsm.SimpleWriteln("AT+CSQ");
          } else {
               Serial.println(inSerial);
               gsm.SimpleWriteln(inSerial);
          }
          inSerial[0]='\0';
     }
}

void serialswread()
{
     gsm.SimpleRead();
}
