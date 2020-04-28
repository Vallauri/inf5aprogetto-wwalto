
/*RTC*/
#include <RTClib.h>
#include <Wire.h>
RTC_DS3231 rtc;
/*************************************************/
/*DHT11*/
#include <SimpleDHT.h>
int pinDHT = 4;
SimpleDHT11 dht11(pinDHT);
/*************************************************/
/*Analogic sensors*/
#define pinWater A1
#define pinFotoresistor A2
#define pinIgro A0
/*************************************************/
/*Led*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define nel 12//Num led
#define pinLed 9
Adafruit_NeoPixel pix = Adafruit_NeoPixel (nel, pinLed, NEO_RGB + NEO_KHZ800);
/*************************************************/
/*Relè*/
#define pinPompa 7
#define pinVentola 8
/*************************************************/
/*Variabili stato*/
float temperature = 0;
float humidity = 0;
int water = 0;
int umdtrr = 0;
int luce;
/*************************************************/
/*var Gestione tempi*/
/*Pompa*/
int oraAzionePompa = 0;
int secondoAttivazionePompa = 0;
bool attivaPompaCondizione = false;
/*Ventola*/
bool attivaVentola = false;
/*Led*/
int oraAzioneLed = 0;
bool attivaLed = false;
int secondoDisattivazioneLed = 0;
/*************************************************/
/*lettura e stampa sensori*/
int secondoLettura = 0;
int minutoStampa = 0;
/*************************************************/
/*Gestione e recupero data e ora*/
void recuperaOraEData()
{
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
int ora()
{
  int ora;
  DateTime oraT = rtc.now();
  ora = oraT.hour();
  return ora;
}
int minuto()
{
  int minuto;
  DateTime minutoT = rtc.now();
  minuto = minutoT.minute();
  return minuto;
}
int secondo()
{
  int secondo;
  DateTime secondoT = rtc.now();
  secondo = secondoT.second();
  return secondo;
}
/*************************************************/
void setup()
{
  Serial.begin(9600);
  /*************************************************/
  /*Pompa acqua*/
  pinMode(pinPompa, OUTPUT);
  digitalWrite(pinPompa, LOW);
  /*Ventola*/
  pinMode(pinVentola, OUTPUT);
  digitalWrite(pinVentola, LOW);
  /*Leds*/
  pix.begin();
  int p;
  for (p = 0; p <= nel; p++)
    pix.setPixelColor(p, pix.Color(0, 0, 0)); //255 255 255 bianco
  pix.show();
  /*************************************************/
  /*Fotoresistor*/
  pinMode(pinFotoresistor, INPUT);
  /*************************************************/
  /*RTC*/
  if (!rtc.begin())
  {
    Serial.println("Verifica connessioni");
    while (true);
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//Recupera data e ora
}

/*************************************************/
/*Lettura e stampa sensori*/
void letturaSensori()
{
  if (secondo() >= (secondoLettura + 3))
  {
    /*int err = SimpleDHTErrSuccess;
     if ((err = dht11.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
     Serial.print("Read DHT11 failed, err=");
     Serial.println(err);
     Serial.println("--------------------------------------------");
     return;
     }*/
    dht11.read2(&temperature, &humidity, NULL);
    water = analogRead(pinWater);
    luce = analogRead(pinFotoresistor);
    int igro = analogRead(pinIgro);
    umdtrr = map (igro, 100, 990, 100, 0);
    secondoLettura = secondo();
    //Serial.println(secondoLettura);
  }
  if (secondoLettura >= 57)
    secondoLettura = 0;
}
void stampaSensori()
{
  if (minuto() >= (minutoStampa + 1))
  {
    Serial.println("==========================================");
    Serial.print(ora());
    Serial.print(":");
    Serial.print(minuto());
    Serial.print(":");
    Serial.println(secondo());
    Serial.print("Temperatura: ");
    Serial.print((float)temperature);
    Serial.println("°C");
    Serial.print("Umidita: ");
    Serial.print((float)humidity);
    Serial.println("RH%");
    Serial.print("Luce(0LumMax-1024Buio): ");
    Serial.println(luce);
    Serial.print("Umidità del terreno: ");
    Serial.print(umdtrr);
    Serial.println("%");
    Serial.print("livello acqua: ");
    Serial.println(water);
    Serial.println("==========================================");
    minutoStampa = minuto();
  }
  if (minutoStampa >= 59)
    minutoStampa = 0;
}
/*************************************************/
/*Controllo stati*/
char statoPompa()
{
  char stato;
  if (digitalRead(pinPompa) == HIGH)
    stato = 'O';//acceso
  else
    stato = 'S';//spento
  return stato;
}
char statoVentola()
{
  char stato;
  if (digitalRead(pinVentola) == HIGH)
    stato = 'O';//acceso
  else
    stato = 'S';//spento
  return stato;
}
char statoLed()
{
  char stato;
  if (pix.getPixelColor(0) != 0)
    stato = 'O';//acceso
  else
    stato = 'S';//spento
  return stato;
}
/*************************************************/
/*Gestione elementi manipolazione ambiente*/
void gestionePompa()
{
  if (ora() > 8 && ora() < 20)
  {
    //Serial.println(oraAzionePompa);
    if (ora() > oraAzionePompa)
    {
      attivaPompaCondizione = true;
      oraAzionePompa = ora();
      setup();
    }
    if (secondo() < 57 && attivaPompaCondizione == true)
    {
      digitalWrite(pinPompa, HIGH);
      secondoAttivazionePompa = secondo();
      attivaPompaCondizione = false;
    }
    if (secondo() > secondoAttivazionePompa && digitalRead(pinPompa) == HIGH)
    {
      digitalWrite(pinPompa, LOW);
      secondoAttivazionePompa = 0;
    }
  }
  else
  {
    oraAzionePompa = 0;
    digitalWrite(pinPompa, LOW);
    secondoAttivazionePompa = 0;
  }
}
void gestioneVentola()
{
  if (ora() > 8 && ora() < 20)
  {
    if (temperature > 20 || humidity > 50)
      attivaVentola = true;
    else
      attivaVentola = false;
    if (attivaVentola == true)
    {
      digitalWrite(pinVentola, HIGH);
      //Servo1.write (-180);
    }
    else
    {
      digitalWrite(pinVentola, LOW);
      //Servo1.write (0);
    }
  }
  else {
    attivaVentola = false;
    digitalWrite(pinVentola, LOW);
  }
}
void gestioneLed()
{
  if (ora() > 8 && ora() < 20)
  {
    if (ora() > oraAzioneLed)
    {
      attivaLed = true;
      oraAzioneLed = ora();
    }
    if (attivaLed == true && secondo() < 57)
    {
      int c;
      for (c = 0; c <= nel; c++)
        pix.setPixelColor(c, pix.Color(0, 0, 0));
      secondoDisattivazioneLed = secondo();
    }
    if (secondo() > (secondoDisattivazioneLed+2) && luce > 550)
    {
      recuperaOraEData();
      int p;
      for (p = 0; p <= 5; p++)
        pix.setPixelColor(p, pix.Color(190, 0, 0));
      for (p = 6; p <= nel; p++)
        pix.setPixelColor(p, pix.Color(0, 170, 190));
      pix.show();
      attivaLed = false;
      secondoDisattivazioneLed = 0;
    }
    else
    {
      attivaLed = false;
      secondoDisattivazioneLed = 0;
    }
  }
  else
  {
    int c;
    for (c = 0; c <= nel; c++)
      pix.setPixelColor(c, pix.Color(0, 0, 0));
    attivaLed = false;
    secondoDisattivazioneLed = 0;
    oraAzioneLed = 0;
  }
}
/*************************************************/
void controlloStati()
{
  char pompa;
  char ventola;
  char led;
  pompa = statoPompa();
  ventola = statoVentola();
  led = statoLed();
}
void loop()
{
  letturaSensori();
  stampaSensori();
  gestioneLed();
  gestionePompa();
  gestioneVentola();
  controlloStati();
}

