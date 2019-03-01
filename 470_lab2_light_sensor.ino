
//int ledPin = 3;
int photoresistor = 3;
int val = 0;
void setup() {
  Serial.begin(9600);
  //pinMode(ledPin, HIGH);
  pinMode(photoresistor, INPUT);
}

void loop() {
  val = digitalRead(photoresistor);
  Serial.println(val);
  //analogWrite(ledPin, val / 4);
}
