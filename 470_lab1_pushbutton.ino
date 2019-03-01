//a program to read the state of the pin (whether it is HIGH or LOW)

int buttonPin = 2; //the pin we choose to connect the pushbutton to
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); //pushbutton is an input
}

void loop() {
  int buttonState = digitalRead(buttonPin); // buttonState will be 0 when button is pressed, 1 when not
  if (buttonState == 0) {
    Serial.println("Button is pressed!");
  }
  else {
    Serial.println("Button is not pressed!");
  }
}
