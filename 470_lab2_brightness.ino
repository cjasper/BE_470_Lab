/*Write a piece of Arduino code that works as a
“brightness function.” For this code, use a variable called “brightness.” When
brightness = 0, your LED should be off all the time. When brightness = 100, your LED
should be on all the time. And intermediate values of brightness should give
intermediate LED intensity (i.e., brightness = % full intensity). */

//you will need to connect your LED to pins 3,5,6,9, 10, or 11 to use analogWrite
int ledPin = 3;
int analogPin = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, HIGH);
}

void loop() {
  int val = analogRead(analogPin);
  Serial.println(val);
  delay(100);  
  analogWrite(ledPin, val / 4); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
}
