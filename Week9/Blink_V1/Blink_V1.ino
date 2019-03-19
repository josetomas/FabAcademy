int Led1=2;
int Led2=7;
int Led3=8;
int Button=3;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Button, INPUT);
  
}


void loop() {
  if (digitalRead(Button)==0){
  digitalWrite(Led3, HIGH);  
  delay(500);         
  digitalWrite(Led3, LOW);
  delay(500); 
  }
  else{
  digitalWrite(Led2, HIGH);
  delay(500);
  digitalWrite(Led2, LOW);
  delay(500);
  }
}
