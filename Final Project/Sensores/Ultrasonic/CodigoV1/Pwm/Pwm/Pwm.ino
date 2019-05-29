int PWM=7;
int valor=10;
void setup() {
  pinMode(PWM,OUTPUT);

}

void loop() {
  analogWrite(PWM,valor);
  valor++;

}
