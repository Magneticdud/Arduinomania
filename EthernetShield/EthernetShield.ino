#include <SPI.h>
#include <Ethernet.h>

// the media access control (ethernet hardware) address for the shield:
byte mac[] = { 0xFE, 0xDE, 0x2B, 0x89, 0x93, 0xBE };  
//the IP address for the shield:
byte ip[] = { 192, 168, 10, 177 }; 
byte mydns[] = { 8, 8, 8, 8 }; 
byte gateway[] = { 192, 168, 10, 254 }; 
char server[] = "smtp.mandrillapp.com";
String UserName64 = "XXXXXXX";
String Password64 = "XXXXXXX";
String Sender = "XXXXXXX@x.x";
String Recipient = "XXXXXXX@x.x";    
String Subject = "Arduino!!";
String Body = "Ciao!\nSono Arduino!";
int time = 5000;
int wait = 1000;
String ServerResponse="";
EthernetClient client;

void setup() {
  Serial.begin(9600);
  Serial.println("Program started, waiting for router...");
  delay(time);
  /* allow the router to identify the Arduino before the Arduino connects to the internet */
  Serial.println("Starting network module...");
  Ethernet.begin(mac, ip, mydns, gateway);
  delay(time);
  Serial.println("connecting...");
  if (client.connect(server, 25)) {
     Serial.println("connected");
     SendMsg("EHLO " + ServerName); /* say hello*/
     SendMsg("AUTH LOGIN ");
     SendMsg(UserName64); /* Username*/
     SendMsg(Password64); /* Password */
     SendMsg("MAIL From:<" + Sender +">");
 /* identify sender */
     SendMsg("RCPT To:<" + Recipient + ">");
 /* identify recipient */
     SendMsg("DATA");
     SendMsg("To: " + Recipient); 
/* recipient in message header */

     SendMsg("From: " + Sender); 
/* seder name in message header */

     SendMsg("Subject: "+ Subject);
 /* insert subject */
     SendMsg(""); /* empty line */
     SendMsg(Body); /* insert body */
     SendMsg(""); /* empty line */
     SendMsg("."); /* end mail */
     SendMsg("QUIT"); /* terminate connection */
     client.println();
  } else {
    Serial.println("connection failed");
  }
}

void loop()
 {
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for( ; ; )
      ;
  }
}
 
void GetResponse() {
    if (client.available()) {
         char c = client.read();
         while (client.available()) { // Store command char by char.
           ServerResponse +=c;
           c = client.read();
         }
    Serial.println("<<<" + ServerResponse);
    ServerResponse="";
  }
}
 
void SendMsg(String m) {
   client.println(m);
   Serial.println(">>>" + m);
   delay(wait); /* wait for a response */
   GetResponse();
}
