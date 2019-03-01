#include <EEPROM.h> 

int inputChar;
int arr[] = {0, 2, 4, 6, 8};

void setup() {
  Serial.begin(9600);
  inputChar = Serial.read();
}

void loop() {
  int writeAddress = 0;
  int readAddress = 0;
  if (Serial.available() > 0) {
    inputChar = Serial.read();
    if (inputChar == 'R') {
            int arraySize = sizeof(arr) / sizeof(arr[0]);
        for (int i = 0; i < arraySize; i = i + 1) {
          byte value = EEPROM.read(readAddress);
          Serial.print("Address: "); Serial.print(readAddress);
          Serial.print("\t");
          Serial.print("Value: "); Serial.print(value, DEC);
          Serial.println(); 
          readAddress += 1;
        }
    }
    
    if (inputChar == 'W') {
      int arraySize = sizeof(arr) / sizeof(arr[0]);
      for (int i = 0; i < arraySize; i = i + 1) {
        EEPROM.write(writeAddress, arr[i]);
        Serial.println("saving ");
        Serial.print(arr[i]);
        Serial.print(" at address");
        Serial.println(writeAddress);
        writeAddress += 1;
      }
    }
  }
}
