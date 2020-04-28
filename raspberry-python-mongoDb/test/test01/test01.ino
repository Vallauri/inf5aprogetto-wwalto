#include <RTClib.h>

/*RTC*/
#include <Wire.h>
RTC_DS3231 rtc;
/*DHT11*/
#include <SimpleDHT.h>
int pinDHT = 4;
SimpleDHT11 dht11(pinDHT);
/*Water Sensor*/
#define pinWater A1
/*Fotoresistor*/
#define pinFotoresistor A2
int luce;
/*Igrometro*/
#define pinIgro A0
/*Ring led*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define nel 12
#define pinLed 9
/*pompa acqua*/
#define pinPompa 7
long int inizioPompa;
int finePompa = 1;
/*ventola*/
#define pinVentola 8
Adafruit_NeoPixel pix = Adafruit_NeoPixel (nel, pinLed, NEO_RGB + NEO_KHZ800);
int minLetturaPrecedente = 0;//secondi
long int tInnaffiamento = 1;//ore
int oraPrecedente = 0;
float temperature = 0;
float humidity = 0;
int water = 0;
int umdtrr = 0;
int oraPrecLed = 0;
void setup()
{
  Serial.begin(9600);
  /*Fotoresistor*/
  pinMode(pinFotoresistor, INPUT);
  /*ring led*/
  pix.begin();
  int p;
  for (p = 0; p <= nel; p++)
    pix.setPixelColor(p, pix.Color(0, 0, 0)); //255 255 255 bianco
  pix.show();
  /*pompa acqua*/
  pinMode(pinPompa, OUTPUT);
  digitalWrite(pinPompa, LOW);
  /*ventola*/
  pinMode(pinVentola, OUTPUT);
  digitalWrite(pinVentola, LOW);
  /*RTC*/
  if (!rtc.begin())
  {
    Serial.println("Verifica connessioni");
    while (true);
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
void loop()
{
  processoRead();
  controlloPompa();
  controlloVentola();
  controlloLed();
}
void readSensors()
{
  /*DHT11*/
  Serial.println("Sample DHT11...");
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err=");
    Serial.println(err);
    Serial.println("--------------------------------------------");
    return;
  }
  stampaOra();
  Serial.print("Sample OK: ");
  Serial.print((float)temperature);
  Serial.print(" *C, ");
  Serial.print((float)humidity);
  Serial.println(" RH%");
  /*Water Sensor*/
  water = analogRead(pinWater);
  Serial.print("Livello acqua: ");
  Serial.println(water, DEC);
  /*Fotoresistor*/
  Serial.print("Luce(10LumMax-1024Buio): ");
  Serial.println(analogRead(pinFotoresistor));
  luce = analogRead(pinFotoresistor);
  /*Igrometro*/
  int igro = analogRead(pinIgro);
  umdtrr = map (igro, 100, 990, 100, 0);
  Serial.print("Umidità del terreno: ");
  Serial.print(umdtrr);
  Serial.println("%");
  Serial.println("--------------------------------------------");
}
void controlloPompa()
{
  DateTime now = rtc.now();
  int ora = now.hour();
  if (ora >= 8 && ora <= 21)
  {
    if (ora > oraPrecedente)
    {
      if (umdtrr < 45)
      {
        inizioPompa = millis();
        digitalWrite(pinPompa, HIGH);
      }
      oraPrecedente = ora;
    }
  }
  if (digitalRead(pinPompa) == HIGH && millis()>=((int)inizioPompa+600))
    digitalWrite(pinPompa, LOW);
  if (ora > 21)
    oraPrecedente = 0;
}
void controlloVentola()
{
  if (humidity >= 60 || temperature >= 22)
    digitalWrite(pinVentola, HIGH);
  else
    digitalWrite(pinVentola, LOW);
}
void controlloLed()
{
  DateTime now = rtc.now();
  int ora = now.hour();
  if (oraPrecLed < ora)
  {
    int p;
    for (p = 0; p <= nel; p++)
      pix.setPixelColor(p, pix.Color(0, 0, 0)); //255 255 255 bianco
    pix.show();
  }
  if (oraPrecLed > 22)
    oraPrecLed = 0;
  if (ora > 8 && ora < 22 && luce > 400)
  {
    int p;
    for (p = 0; p <= nel; p++)
      pix.setPixelColor(p, pix.Color(255, 0, 0)); //255 255 255 bianco
    pix.show();
  }
  else
  {
    int p;
    for (p = 0; p <= nel; p++)
      pix.setPixelColor(p, pix.Color(0, 0, 0)); //255 255 255 bianco
    pix.show();
  }
  oraPrecLed = ora;
}
void processoRead()
{

  DateTime now = rtc.now();
  int minut = now.minute();
  if (minut > minLetturaPrecedente)
  {
    readSensors();
    minLetturaPrecedente = minut;
    if (minut >= 59)
      minLetturaPrecedente = 0;
  }
}
void stampaOra()
{
  DateTime now = rtc.now();
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.println(now.second(), DEC);
}
