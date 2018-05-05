//show a key according to a ps2 analog nub connected
const int ledPin =  13;
int speakerPin = 5;
int analogxPin = A0;
int analogyPin = A1;

int valueX = 0;
int valueY = 0;

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
    Serial.begin(9600);
    pinMode(speakerPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    Serial.print("Hello. Ready.");
}

void loop() {
    /*translate('r');
    translate('o');
    translate('s');
    translate('s');
    translate('o');
    delay(delayRepeat);*/
    //TODO: switch between morse and code revealing
    readAnalogForCode();
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

void readAnalogForCode() {
    //code: 6732
    valueX = analogRead(analogxPin);
    valueY = analogRead(analogyPin);
    if (valueX==0) {
        Serial.print("6\t_\t_\t_\n");
    }
    if (valueX==1023) {
        Serial.print("_\t7\t_\t_\n");
    }
    if (valueY==0) {
        Serial.print("_\t_\t3\t_\n");
    }
    if (valueY==1023) {
        Serial.print("_\t_\t_\t2\n");
    }
    /*Serial.print("x: ");
    Serial.print(valueX);
    Serial.print('\n');*/
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
