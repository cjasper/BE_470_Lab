int pin = 4;
int rotationAngle = 0;
float pulseWidth;
float conversion = 180; //to convert from radians to degrees

void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  Serial.println("Begin servo motion!");
  delay(1000);
}

void loop() {
  Serial.println(rotationAngle);
  pulseWidth = 1000 * (1 + rotationAngle/conversion);
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(pin, LOW);
  delayMicroseconds(2000 - pulseWidth);
  if (rotationAngle == 90) {
    rotationAngle = 0;
    //Serial.println("hi");
  }
  else if (rotationAngle == 0) {
    rotationAngle = 90;
    //Serial.println("2");
  }
  delay(500);
}
