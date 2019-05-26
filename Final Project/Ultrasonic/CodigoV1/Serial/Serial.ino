//Comunicación Serial, usar baudratede 1200 en el terminal. 

#include <SoftwareSerial.h>
#define rxPin 0
#define txPin 1

SoftwareSerial mySerial(rxPin,txPin);


void setup() {
  mySerial.begin(9600);
}

void loop() {
  mySerial.println("Holi! :*");
}
