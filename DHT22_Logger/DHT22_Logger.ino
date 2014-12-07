//let's log the temperature!
//SD shield + RTC libs:
#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <RTClib.h>

//how much i wait?
#define LOG_INTERVAL 1000

//how much i wait before writing?
#define SYNC_INTERVAL 10000
uint32_t syncTime = 0; //when it has last synced (never)

#define ECHO_TO_SERIAL 1
#define WAIT_TO_START 0	//wait  for serial input

RTC_DS1307 RTC;

//chip for data logging
const int chipSelect = 10;

//la variabile del file logging
File logfile;

void error(char *str)
{
  Serial.print("Errore: ");
  Serial.println(str);

  //hang forever
  while(1);
}

void setup(void)
{
  Serial.begin(9600);
  Serial.println();

  #if WAIT_TO_START
    Serial.println("Premere un tasto per iniziare");
    while (!Serial.available());
  #endif

  Serial.print("Inizializzazione lettore SD...");
  pinMode(10, OUTPUT);
  if (!SD.begin(chipSelect)) {
    error(" carta non riconosciuta");
  }
  Serial.println(" eseguita con successo");		//continua dal discorso precedente

  //crea un nuovo file
  char filename[] = "MYLOG00.TXT";
  //aggiunge un numero se il file esiste
  //WONT WORK IF MORE THAN 100 FILES!!!
  for (uint8_t i = 0; i < 100; i++){
    filename[5] = i/10 + '0';
    filename[6] = i%10 + '0';
    if (!SD.exists(filename)){
      logfile = SD.open(filename, FILE_WRITE);
      break; //esce dal loop!
    }
  }

  if (!logfile){
    error("Impossibile creare il file - hai più di 100 files?");
  }

  Serial.print("Logging to: ");
  Serial.println(filename);

  // connessione al chip RTC
  Wire.begin();  
  if (!RTC.begin()) {
    logfile.println("RTC failed");
  #if ECHO_TO_SERIAL
      Serial.println("RTC failed");
  #endif  //ECHO_TO_SERIAL
  }

  //prima riga del file CSV
  logfile.println("millis,stamp,datetime");
  #if ECHO_TO_SERIAL
    Serial.println("millis,stamp,datetime");
  #endif
}

void loop(void)
{
  DateTime now;
  //ritardo programmato
  delay((LOG_INTERVAL-1)-(millis()%LOG_INTERVAL));
  
  //log milliseconds since start
  uint32_t m = millis();
  logfile.print(m);
  logfile.print(", ");
  #if ECHO_TO_SERIAL
    Serial.println(m);
    Serial.println(", ");
  #endif
  
  //che ore sono?
  now = RTC.now();
  //scrivi che ore sono
  logfile.print(now.unixtime());  //secondi dal 1/1/1970
  logfile.print(", ");
  logfile.print('"');
  logfile.print(now.year(), DEC);
  logfile.print("/");
  logfile.print(now.month(), DEC);
  logfile.print("/");
  logfile.print(now.day(), DEC);
  logfile.print(" ");
  logfile.print(now.hour(), DEC);
  logfile.print(":");
  logfile.print(now.minute(), DEC);
  logfile.print(":");
  logfile.print(now.second(), DEC);
  logfile.print('"');
  #if ECHO_TO_SERIAL
    Serial.print(now.unixtime());  //secondi dal 1/1/1970
    Serial.print(", ");
    Serial.print('"');
    Serial.print(now.year(), DEC);
    Serial.print("/");
    Serial.print(now.month(), DEC);
    Serial.print("/");
    Serial.print(now.day(), DEC);
    Serial.print(" ");
    Serial.print(now.hour(), DEC);
    Serial.print(":");
    Serial.print(now.minute(), DEC);
    Serial.print(":");
    Serial.print(now.second(), DEC);
    Serial.print('"');
  #endif
  
  //newline
  logfile.println();
  #if ECHO_TO_SERIAL
    Serial.println();
  #endif
  
  //write file
  if ((millis() - syncTime) < SYNC_INTERVAL) return;
    syncTime = millis();
  //close file
  logfile.flush();
}

void shutdownEverything(){
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
