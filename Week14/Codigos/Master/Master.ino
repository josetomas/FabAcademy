#include <SoftwareSerial.h>
#include <TinyWireM.h>
#include <USI_TWI_Master.h>
#define rxPin 0
#define txPin 1

SoftwareSerial mySerial(rxPin,txPin);


void setup() {
  mySerial.begin(9600);
  //Serial.begin(9600);
  TinyWireM.begin();
  delay (300);
}

void loop() {
  mySerial.println("networking week");
  /*TinyWireM.requestFrom(8,1);
  while (TinyWireM.available()) {
    int n = TinyWireM.receive();
    mySerial.println(n);
  }*/
}
