int LED1pin = 2; //the pin we choose to connect LED 1 to.
int LED2pin = 6; //the pin we choose to connect LED 2 to.
void setup() {
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  digitalWrite(LED1pin, LOW);
  digitalWrite(LED2pin, LOW);
}

bool alternate = true;
void loop() {
  if (alternate == true) {
    digitalWrite(LED1pin, HIGH);
    delay(1000);
    digitalWrite(LED1pin, LOW);
    alternate = false;
  }
  else {
    digitalWrite(LED2pin, HIGH);
    delay(1000);
    digitalWrite(LED2pin, LOW);
    alternate = true;
  }
}
