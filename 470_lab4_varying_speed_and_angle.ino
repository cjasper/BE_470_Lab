int pin = 4;
int rotationAngle = 90;
float pulseWidth;
float conversion = 180; //to convert from radians to degrees
int delayValue = 200;
int input;

void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  Serial.println("Begin servo motion!");
  delay(1000);
}

void loop() {
  input = Serial.parseFloat();
  Serial.println(input);
  if (input >= 200) {
    delayValue = input;
  }
  else {
    rotationAngle = input;
  }


  for (int i = 0; i < 10; i++) {
    pulseWidth = 1000 * (1 + rotationAngle * i / (conversion * 10));
    digitalWrite(pin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(pin, LOW);
    delayMicroseconds(2000 - pulseWidth);
    delay(delayValue);
  }


  if (rotationAngle == 90) {
    rotationAngle = 0;
  }
  else if (rotationAngle == 0) {
    rotationAngle = 90;
  }
  if (delayValue == 0) {
    delayValue = 200;
  }
}
