//library from https://github.com/enternoescape/Arduino-IRremote-Due
#include <IRremote2.h>
#include "Keyboard.h"
#include "keys.h"

const int RECV_PIN = 11;

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
    switch (results.value) {
      case leftarrowR:
        Keyboard.write(leftarrowT);
        break;
      case rightarrowR:
        Keyboard.write(rightarrowT);
        break;
      case uparrowR:
        Keyboard.write(uparrowT);
        break;
      case downarrowR:
        Keyboard.write(downarrowT);
        break;
      case enterR:
        Keyboard.write(enterT);
        break;
      case pauseR:
        Keyboard.write(pauseT);
        break;
      case stopR:
        Keyboard.write(stopT);
        break;
      default: 
        // do something when no case? Don't need
        break;
    }
    delay(100);
    irrecv.resume(); // Receive the next value
  }
}
