// Measure how fast you can press down on a pushbutton
// Count the number of presses the user completes in 10 seconds

#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"

Adafruit_LiquidCrystal lcd(0);

int duration = 10000;
int pushCount = 0;
int buttonPin = 2; //the pin we choose to connect the pushbutton to
void setup() {
  Serial.begin(9600);
  lcd.begin(20, 4);
  delay(2000);
  lcd.clear();
  pinMode(buttonPin, INPUT); //pushbutton is an input
}

void loop() {
  lcd.print("Press button now!");
  unsigned long time1 = millis();
  bool started = true;
  while (started) {
    unsigned long time2 = millis(); //to know when our 10 seconds are up
    int buttonState = digitalRead(buttonPin); // buttonState will be 0 when button is pressed, 1 when not
    if (buttonState == 0) {
      pushCount += 1;
      delay(100);
    }
    unsigned long elapsedTime = time2 - time1;
    
    if (elapsedTime >= duration) {
      lcd.clear();
      lcd.print("Button presses");
      delay(700);
      lcd.setCursor(20, 2);
      lcd.print(pushCount);
      pushCount = 0;
      delay(2000);
      lcd.clear();
      started = false;
    }
  }
  //exit(0);
}
