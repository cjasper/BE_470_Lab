#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"

Adafruit_LiquidCrystal lcd(0);

int buttonPin = 10; //the pin we choose to connect the pushbutton to
int LEDPin = 2;
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); 
}

void loop() {
  int count = 0;
  int minSteps = 10;
  int timePeriod = 5000;
  unsigned long time1 = millis();
  
  while (true) {
    unsigned long time2 = millis();
    unsigned long elapsedTime = time2 - time1;
    int buttonState = digitalRead(buttonPin);
    Serial.print("Count: ");
    Serial.print(count);
    Serial.println();
    if (buttonState == 0) {
      count += 1;
      delay(200);
    }
    if (elapsedTime >= timePeriod && count < minSteps) {
        digitalWrite(LEDPin, HIGH);
        delay(1000);
        time1 = millis();
        count = 0;
        digitalWrite(LEDPin, LOW);
      }
    else if (elapsedTime >= timePeriod) {
      time1 = millis();
      count = 0;
    }
  }
}
