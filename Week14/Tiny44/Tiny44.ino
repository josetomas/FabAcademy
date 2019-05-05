

#include <TinyWireM.h>                  // I2C Master lib for ATTinys which use USI




void setup(){              
  TinyWireM.begin();                    
}

void loop(){
TinyWireM.write(0);
delay(1000);
}



