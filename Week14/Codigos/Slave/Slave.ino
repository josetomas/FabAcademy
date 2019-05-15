#include <TinyWireS.h>


void setup() 
{
TinyWireS.begin(8); //IC2 Communication
TinyWireS.onRequest (test);
}

void loop() 
{
TinyWireS_stop_check();
}

void test () //Master calls the slave and the latter one send to data 
{

TinyWireS.send(3);  

}
