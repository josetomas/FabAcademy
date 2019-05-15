
#include <Wire.h>
char c;
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  pinMode(7,OUTPUT);
}

void loop() {
  delay(100);
  //digitalWrite(7,HIGH);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    digitalWrite(7,HIGH);
    delay(100);
    digitalWrite(7,LOW);
    delay(1000);
  }
  }
