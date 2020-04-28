#define pinLed 13
#define pinFoto A2

void setup() {
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  pinMode(pinFoto, INPUT);
}

void loop() {
  Serial.println((analogRead(pinFoto)));
  if (analogRead(pinFoto) > 700)
  {
    digitalWrite(pinLed, HIGH);
  }
  else if (analogRead(pinFoto) < 500)
  {
    digitalWrite(pinLed, LOW);
  }
  /*analogWrite(pinLed,(analogRead(pinFoto)/4));*/
  delay(1);
}
