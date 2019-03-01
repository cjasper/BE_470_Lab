int servoPin = 4;
int potPin = 1;
int rotationAngle = 0;
float pulseWidth;
float conversion = 1023;

void setup() {
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.println("Begin servo motion!");
  delay(1000);
}

void loop() {
  int rotationAngle = analogRead(potPin);
  Serial.println(rotationAngle);
  pulseWidth = 1000 * (1 + rotationAngle/conversion);
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);
  delayMicroseconds(2000 - pulseWidth);
  //delay(200);
}
