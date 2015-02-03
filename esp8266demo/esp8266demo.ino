//uartwifi.h must be changed according if using MEGA or UNO. I'm using MEGA
#define SSID       "myrealssid"
#define PASSWORD   "mysupersecretpassword"

#include "uartWIFI.h"
#include <SoftwareSerial.h>
WIFI wifi;

void setup() {
  // put your setup code here, to run once:
  wifi.begin();
  bool b = wifi.Initialize(STA, SSID, PASSWORD);
  delay(8000);  //make sure the module can have enough time to get an IP address 
  String ipstring  = wifi.showIP();
  DebugSerial.print("My IP address: ");
  DebugSerial.println(ipstring);
}

void loop() {
  // put your main code here, to run repeatedly:

}
