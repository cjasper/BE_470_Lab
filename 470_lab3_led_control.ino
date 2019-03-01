int inputChar;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;

void setup() {
  Serial.begin(9600);
  inputChar = Serial.read();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    inputChar = Serial.read();
    if (inputChar == 'a') {
        digitalWrite(LED1, HIGH);
        delay(1000);
        digitalWrite(LED1, LOW);
    }
    if (inputChar == 's') {
      digitalWrite(LED2, HIGH);
      delay(1000);
      digitalWrite(LED2, LOW);
    }
    if (inputChar == 'd') {
      digitalWrite(LED3, HIGH);
      delay(1000);
      digitalWrite(LED3, LOW);
    }
  }
}
