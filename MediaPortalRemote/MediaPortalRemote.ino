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
      case showinfoR:
        Keyboard.write(showinfoT);
        break;
      case ESCR:
        Keyboard.write(ESCT);
        break;
      case key1R:
        Keyboard.write(key1T);
        break;
      case key2R:
        Keyboard.write(key2T);
        break;
      case key3R:
        Keyboard.write(key3T);
        break;
      case key4R:
        Keyboard.write(key4T);
        break;
      case key5R:
        Keyboard.write(key5T);
        break;
      case key6R:
        Keyboard.write(key6T);
        break;
      case key7R:
        Keyboard.write(key7T);
        break;
      case key8R:
        Keyboard.write(key8T);
        break;
      case key9R:
        Keyboard.write(key9T);
        break;
      case key0R:
        Keyboard.write(key0T);
        break;
      case playpreviousR:
        Keyboard.write(playpreviousT);
        break;
      case playnextR:
        Keyboard.write(playnextT);
        break;
      default: 
        // do something when no case? Don't need
        break;
    }
    delay(100);
    irrecv.resume(); // Receive the next value
  }
}
