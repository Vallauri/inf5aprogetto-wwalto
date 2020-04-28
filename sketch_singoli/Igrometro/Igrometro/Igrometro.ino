#define pinIgrometro A1
void setup() {
Serial.begin(9600);
}

void loop() {
// Igrometro
int igro = analogRead(A0); 
int umdtrr = 0;
umdtrr = map (igro, 100, 990, 100, 0); 
Serial.print("Umidità del terreno: ");
Serial.print(umdtrr);
Serial.println ("%");

/*if (igro <= valore_limite)
  digitalWrite(9,LOW); // Attiva Relè 1
else
  digitalWrite(9,HIGH); // Spegni Relè 1
delay(2000); // Attende due secondi*/
}
