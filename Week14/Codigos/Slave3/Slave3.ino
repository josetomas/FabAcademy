#include <Wire.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  pinMode(7,OUTPUT);
}

void loop() {
  delay(100);
}


void requestEvent() {
  Wire.write("Aleza "); 
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(100);
}
