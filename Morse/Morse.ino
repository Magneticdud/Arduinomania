const int ledPin =  13;
int speakerPin = 5;

//tone of long beep
int toneLong = 500;
//tone of short beep
int toneShort = 600;

//duration of short beep
int durationShort = 300;
//duration of long beep
int durationLong = durationShort * 3;

//time between beeps
int delayBeep = 200;
//time between letters
int delayChar = 1000;
//time between words
int delayWords = 3000;
//time between repeats
int delayRepeat = 5000;

void setup() {
    pinMode(speakerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    translate('r');
    translate('o');
    translate('s');
    translate('s');
    translate('o');
    delay(delayRepeat);
}

void shortBeep() {
    tone(speakerPin,toneShort,durationShort);
    digitalWrite(ledPin,HIGH);
    delay(durationShort);
    digitalWrite(ledPin,LOW);
    delay(delayBeep);
}

void longBeep() {
    tone(speakerPin,toneLong,durationLong);
    digitalWrite(ledPin,HIGH);
    delay(durationLong);
    digitalWrite(ledPin,LOW);
    delay(delayBeep);
}

void translate(char character) {
    switch (character) {
        case 'o':
        //___
        longBeep();
        longBeep();
        longBeep();
        break;
        
        case 'r':
        //._.
        shortBeep();
        longBeep();
        shortBeep();
        break;
        
        case 's':
        //...
        shortBeep();
        shortBeep();
        shortBeep();
        break;
    }
    delay(delayChar);
}

