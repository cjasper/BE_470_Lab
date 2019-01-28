int LED1pin = 2; //the pin we choose to connect LED 1 to.
void setup() {
  pinMode(LED1pin, OUTPUT);
  digitalWrite(LED1pin, LOW);
}

int delayTime = 2000;
void loop() {
  while (delayTime >= 0) {
    digitalWrite(LED1pin, HIGH);
    delay(delayTime);
    digitalWrite(LED1pin, LOW);
    delay(delayTime);
    delayTime -= 399;
  }
}
