#include <SPI.h>
#include <Ethernet.h>

// the media access control (ethernet hardware) address for the shield:
byte mac[] = { 0xFE, 0xDE, 0x2B, 0x89, 0x93, 0xBE };  
//the IP address for the shield:
byte ip[] = { 192, 168, 10, 177 }; 
byte mydns[] = { 8, 8, 8, 8 }; 
byte gateway[] = { 192, 168, 10, 254 }; 

void setup() {
  // put your setup code here, to run once:
  Ethernet.begin(mac, ip, mydns, gateway);
}

void loop() {
  // put your main code here, to run repeatedly:

}
