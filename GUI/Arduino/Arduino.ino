char s;   // for incoming mymySerial data

#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1


SoftwareSerial mySerial( rxPin,txPin);
void setup() {   
  mySerial.begin(9600);
        pinMode(3,OUTPUT);
}

void loop() {

        // send data only when you receive data:
        if (mySerial.available() > 0) {
                // read the incoming byte:
                s = mySerial.read();
                
        }
        if(s=='O'){
          digitalWrite(3,HIGH);
          mySerial.println(s);
        }
        else{
          digitalWrite(3,LOW); 
        }

}
