/*
 * based on IRremote: IRrecvDemo by Ken Shirriff
 * now it will be more bloated
 */

#include <IRremote2.h>
#include "Keyboard.h"

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Keyboard.begin(); //initialize keyboard mode
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);
    Serial.println(results.value);
    Keyboard.print(results.value);
    Keyboard.write(176); //press enter because i dunno why, println doesnt send it
    //if red button on my remote is pressed
    if (String(results.value)=="3298349655") {
      Keyboard.write('R');
      Serial.println("RED pressed!");
    }
    irrecv.resume(); // Receive the next value
  }
}
