#include <SoftwareSerial.h>
#define rxPin 0
#define txPin 1
SoftwareSerial mySerial(rxPin,txPin);
int PWM=7;
int valor=250;

void setup() {
  mySerial.begin(9600);
  pinMode(PWM,OUTPUT);

}

void loop() {
  analogWrite(PWM,valor);
  int lectura = analogRead(2);
  mySerial.println(lectura);
  delay(10);

}
