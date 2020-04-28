#include <SimpleDHT.h>
int pinDHT = 4;
SimpleDHT11 dht11(pinDHT);
#define pinWater A1
#define pinFotoresistor A2
#define pinIgro A0
int g = 0;
int t=0;
int t1=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  /*Fotoresistor*/
  pinMode(pinFotoresistor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  leggiSensori();
  aumentaCont();
}

void leggiSensori() {
  /*DHT11*/
  if (millis() >= (t + 2000))
  {
    Serial.println("Sample DHT11...");
    float temperature = 0;
    float humidity = 0;
    int err = SimpleDHTErrSuccess;
    if ((err = dht11.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
      Serial.print("Read DHT11 failed, err=");
      Serial.println(err);
      Serial.println("--------------------------------------------");
      return;
    }
    Serial.print("Sample OK: ");
    Serial.print((float)temperature);
    Serial.print(" *C, ");
    Serial.print((float)humidity);
    Serial.println(" RH%");
    /*Water Sensor*/
    int water = 0;
    water = analogRead(pinWater);
    Serial.print("Livello acqua: ");
    Serial.println(water, DEC);
    /*Fotoresistor*/
    Serial.print("Luce(10LumMax-1024Buio): ");
    Serial.println(analogRead(pinFotoresistor));
    /*Igrometro*/
    int igro = analogRead(pinIgro);
    int umdtrr = 0;
    umdtrr = map (igro, 100, 990, 100, 0);
    Serial.print("Umidità del terreno: ");
    Serial.print(umdtrr);
    Serial.println("%");
    Serial.println("--------------------------------------------");
    t=millis();
  }
}
void aumentaCont() {
  if (millis() >= (t1 + 10))
  {
    g++;
    Serial.println(g);
    t1=millis();
  }
}
