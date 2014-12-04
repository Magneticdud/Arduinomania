//test LEDs

void setup() {
	//LED
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	//onboard LED
	pinMode(13, OUTPUT);
}

void loop() {
	//accende i LED in sequenza
	digitalWrite(3, HIGH);
	delay(200);
	digitalWrite(3, LOW);
	digitalWrite(4, HIGH);
	delay(200);
	digitalWrite(4, LOW);
	digitalWrite(5, HIGH);
	delay(200);
	digitalWrite(5, LOW);
	digitalWrite(6, HIGH);
	delay(200);
	digitalWrite(6, LOW);
	digitalWrite(7, HIGH);
	delay(200);
	digitalWrite(7, LOW);
	digitalWrite(8, HIGH);
	delay(200);
	digitalWrite(8, LOW);
	digitalWrite(13, HIGH);
	delay(200);
	digitalWrite(13, LOW);
}