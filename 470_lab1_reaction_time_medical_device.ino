// Make a reaction-time measuring device.
// Have the microcontroller turn an LED on, and measure and display
// how long it takes for a subject to press a pushbutton.
// Display the reaction time on the LCD.

#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"
//#include "i2cLCD.h"

Adafruit_LiquidCrystal lcd(0);

int buttonPin = 10; //the pin we choose to connect the pushbutton to
void setup() {
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.print("Hello BE470 Student!");
  delay(2000);
  lcd.clear();

  pinMode(buttonPin, INPUT); //pushbutton is an input
}

void loop() {
  lcd.print("Press button now!");
  unsigned long time1 = millis();
  while (true) {
    int buttonState = digitalRead(buttonPin); // buttonState will be 0 when button is pressed, 1 when not
    if (buttonState == 0) {
      //Serial.println("Button is pressed");
      unsigned long time2 = millis();
      unsigned long elapsedTime = time2 - time1;
    }
  }
}
