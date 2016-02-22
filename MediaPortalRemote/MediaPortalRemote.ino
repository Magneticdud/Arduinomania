#include <IRremote2.h>
#include "Keyboard.h"
#include "keys.h"

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
    Serial.println(results.value,HEX);
    Keyboard.print(results.value,HEX);
    Keyboard.write(0xB0); //press enter because i dunno why, println doesnt send it
    //if red button on my remote is pressed
    if (results.value==0xC498D257) {
      Keyboard.write('R');
      Serial.println("RED pressed!");
    }
    irrecv.resume(); // Receive the next value
  }
}
