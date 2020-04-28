#include <SimpleDHT.h>
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);
void setup() { Serial.begin(9600); }
void loop() {
 Serial.println("=================================");
 Serial.println("Sample DHT11...");
 float temperature = 0;
 float humidity = 0;
 int err = SimpleDHTErrSuccess;
 if((err=dht11.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess){
 Serial.print("Read DHT11 failed, err=");
 Serial.println(err);
 delay(1000);
 return;
 }
 Serial.print("Sample OK: ");
 Serial.print((float)temperature);
 Serial.print(" *C, ");
 Serial.print((float)humidity);
 Serial.println(" RH%");
 delay(3000); // DHT11 sampling rate is 1HZ.
}
