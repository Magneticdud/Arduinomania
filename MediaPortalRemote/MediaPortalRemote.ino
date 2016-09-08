//library from https://github.com/enternoescape/Arduino-IRremote-Due
#include <IRremote2.h>
#include "Keyboard.h"
#include "keys.h"

const int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  //We have to wait for Windows loading, or sometimes the keyboard doesn't work.
  Serial.begin(9600);
  Serial.println("Loading...");
  digitalWrite(13, HIGH);   // turn the LED on, meaning LOADING
  delay(5000);              // wait for 5 seconds
  irrecv.enableIRIn(); // Start the receiver
  Keyboard.begin(); //initialize keyboard mode
  Serial.println("Ready");
}

void loop() {
  digitalWrite(13, LOW);    // turn the LED off
  if (irrecv.decode(&results)) {
    Serial.println(results.value,HEX);
    switch (results.value) {
      case leftarrowR:
        Keyboard.write(leftarrowT);
        digitalWrite(13, HIGH);
        break;
      case rightarrowR:
        Keyboard.write(rightarrowT);
        digitalWrite(13, HIGH);
        break;
      case uparrowR:
        Keyboard.write(uparrowT);
        digitalWrite(13, HIGH);
        break;
      case downarrowR:
        Keyboard.write(downarrowT);
        digitalWrite(13, HIGH);
        break;
      case enterR:
        Keyboard.write(enterT);
        digitalWrite(13, HIGH);
        break;
      case pauseR:
        Keyboard.write(pauseT);
        digitalWrite(13, HIGH);
        break;
      case stopR:
        Keyboard.write(stopT);
        digitalWrite(13, HIGH);
        break;
      case showinfoR:
        Keyboard.write(showinfoT);
        digitalWrite(13, HIGH);
        break;
      case ESCR:
        Keyboard.write(ESCT);
        digitalWrite(13, HIGH);
        break;
      case key1R:
        Keyboard.write(key1T);
        digitalWrite(13, HIGH);
        break;
      case key2R:
        Keyboard.write(key2T);
        digitalWrite(13, HIGH);
        break;
      case key3R:
        Keyboard.write(key3T);
        digitalWrite(13, HIGH);
        break;
      case key4R:
        Keyboard.write(key4T);
        digitalWrite(13, HIGH);
        break;
      case key5R:
        Keyboard.write(key5T);
        digitalWrite(13, HIGH);
        break;
      case key6R:
        Keyboard.write(key6T);
        digitalWrite(13, HIGH);
        break;
      case key7R:
        Keyboard.write(key7T);
        digitalWrite(13, HIGH);
        break;
      case key8R:
        Keyboard.write(key8T);
        digitalWrite(13, HIGH);
        break;
      case key9R:
        Keyboard.write(key9T);
        digitalWrite(13, HIGH);
        break;
      case key0R:
        Keyboard.write(key0T);
        digitalWrite(13, HIGH);
        break;
      case playpreviousR:
        Keyboard.write(playpreviousT);
        digitalWrite(13, HIGH);
        break;
      case playnextR:
        Keyboard.write(playnextT);
        digitalWrite(13, HIGH);
        break;
      case windowskeyR:
        Keyboard.write(windowskeyT);
        digitalWrite(13, HIGH);
        break;
      case showcontextR:
        Keyboard.write(showcontextT);
        digitalWrite(13, HIGH);
        break;
      case PIPR:
        Keyboard.write(PIPT);
        digitalWrite(13, HIGH);
        break;
      case redR:
        Keyboard.write(redT);
        digitalWrite(13, HIGH);
        break;
      case greenR:
        Keyboard.write(greenT);
        digitalWrite(13, HIGH);
        break;
      case yellowR:
        Keyboard.write(yellowT);
        digitalWrite(13, HIGH);
        break;
      case blueR:
        Keyboard.write(blueT);
        digitalWrite(13, HIGH);
        break;
      case subsR:
        Keyboard.write(subsT);
        digitalWrite(13, HIGH);
        break;
      case audioR:
        Keyboard.write(audioT);
        digitalWrite(13, HIGH);
        break;
      case zoomR:
        Keyboard.write(zoomT);
        digitalWrite(13, HIGH);
        break;
      case recR:
        Keyboard.write(recT);
        digitalWrite(13, HIGH);
        break;
      case ffR:
        Keyboard.write(ffT);
        digitalWrite(13, HIGH);
        break;
      case rewindR:
        Keyboard.write(rewindT);
        digitalWrite(13, HIGH);
        break;
      case nextpageR:
        Keyboard.write(nextpageT);
        digitalWrite(13, HIGH);
        break;
      case previouspageR:
        Keyboard.write(previouspageT);
        digitalWrite(13, HIGH);
        break;
      case auto3dswitchR:
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press('auto3dswitchT');
        delay(100);
        Keyboard.releaseAll();
        digitalWrite(13, HIGH);
        break;
      default: 
        // do something when no case? Don't need
        break;
    }
    delay(100);
    irrecv.resume(); // Receive the next value
  }
}
