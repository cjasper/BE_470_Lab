// RCTime -- modified version
int sensorPin = 4; // 220 or 1k resistor connected to this pin
long result = 0;
int LEDPin = 8;
void setup() // run once, when the sketch starts
{
  Serial.begin(9600);
  Serial.println("Testing RCTime");
  pinMode(LEDPin, HIGH);
}

void loop() // run over and over again
{
  Serial.println( RCtime(sensorPin) );
  delay(10);
  pinMode(LEDPin, HIGH);
  //analogWrite(LEDPin, result / 10);
}

long RCtime(int sensorPin) {
  long result = 0;
  pinMode(sensorPin, OUTPUT); // make pin OUTPUT
  digitalWrite(sensorPin, HIGH); // make pin HIGH to discharge capacitor - study the schematic
  delay(1); // wait a ms to make sure cap is discharged
  pinMode(sensorPin, INPUT); // turn pin into an input and time till pin goes low
  digitalWrite(sensorPin, LOW); // turn pullups off - or it won't work
  while (digitalRead(sensorPin)) { // wait for pin to go low
    result++;
    if (result == 100000) break; // don't wait forever for pin to go low
    // if result reaches 100,000 stop waiting.
    // this means that if RCTime returns 100,000, it really
    // means that RCTime is >= 100,000.
    // you can change this value of 100,000 to something else.
    // there is nothing magic about the number, 100,000.
  }
  
  return result; // report results
}
