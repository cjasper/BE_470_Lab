#include <EEPROM.h>

int photoresistor = 4;

int value;
void setup() {
  Serial.begin(9600);
  pinMode(photoresistor, INPUT);
}

int duration = 3000;
unsigned long totalTime = 0;
int address = 0;

void loop() {
  int currTime = millis();

  if (totalTime < 60000) {
      value = analogRead(photoresistor);
      EEPROM.write(address, value);
      Serial.println("Stored data: " + String(value) + "in address " + String(address));
      address += 1;
  }

  totalTime += duration;

  delay(duration);
}
