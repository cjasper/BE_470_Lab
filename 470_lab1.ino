#include "Wire.h"
#include "i2cLCD.h"
Adafruit_LiquidCrystal lcd(0);

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   lcd.begin(20, 4);
   lcd.print("Hello BE470 Student!");
   delay(2000);
   lcd.clear();
}

int x = 9;
void loop() {
    if (x >= 0) {
      lcd.print(x);
      delay(1000);
      lcd.setCursor(0, 0); //we will see
      x -= 1;
  }
  else {
    lcd.print("Blast off!");
    delay(1000);
    break;
  }

  
}
