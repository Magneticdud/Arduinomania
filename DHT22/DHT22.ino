#include <DHT.h>

#define DHTPIN 2          // what pin we're connected to
#define DHTTYPE DHT22

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

//6 LEDs = 6 temp ranges
// pin 3 = 35+ C
// pin 4 = 30-35 C
// pin 5 = 25-30 C
// pin 6 = 20-25 C
// pin 7 = 15-20 C
// pin 8 = 15- C

void setup() {
  Serial.begin(9600); 
  Serial.println("Welcome to DHT22!");
  //LED
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  
  digitalWrite(13, HIGH);   // turn the LED on when starts reading
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println(" *C ");
  digitalWrite(13, LOW);   // turn the LED off when no reading.
  shutdownEverything();
  if (t<15) {
    digitalWrite(8, HIGH);
  }
  if (t>=15 && t<20) {
    digitalWrite(7, HIGH);
  }
  if (t>=20 && t<25) {
    digitalWrite(6, HIGH);
  }
  if (t>=25 && t<30) {
    digitalWrite(5, HIGH);
  }
  if (t>=30 && t<35) {
    digitalWrite(4, HIGH);
  }
  if (t>=35) {
    digitalWrite(3, HIGH);
  }
}

void shutdownEverything(){
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
