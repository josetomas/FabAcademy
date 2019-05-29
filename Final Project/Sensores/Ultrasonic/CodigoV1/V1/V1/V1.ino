#include <SoftwareSerial.h>
#define rxPin 1
#define txPin 0
SoftwareSerial mySerial(rxPin,txPin);
int PWM=7;
float valor=.0;

void setup() {
  mySerial.begin(9600);
  pinMode(PWM,OUTPUT);

}

void loop() {
  analogWrite(PWM,valor);
  float lectura = analogRead(2);
  float rel=lectura/valor;
  mySerial.println(rel*10.0);
}
