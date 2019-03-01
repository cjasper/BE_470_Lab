 /* Write a program that generates a ramp output. A ramp increases in value with time
suddenly drops back down to zero and then starts increasing again. Display the values
on the Serial Monitor  */

void setup() {
  Serial.begin(9600);
}

void loop() {
  int output = 0;
  int duration = 5000;
  unsigned long time1 = millis();
  while (true) {
    unsigned long time2 = millis();
    unsigned long elapsedTime = time2 - time1;
    if (elapsedTime >= timePeriod) {
        output = 0;
      }
    }
    else {
      output += 1;
  }
}
