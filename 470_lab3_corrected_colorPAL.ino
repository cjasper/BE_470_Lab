/* ColorPAL corrected by black and white reference */

#include <OldSoftwareSerial.h>
OldSoftwareSerial Color90(2, 3);  // rx = 2, tx = 3

int red; int grn; int blu;
float Cr; float Cg; float Cb;

// Determined experimentally to correct for color inaccuracy:
int Kr = 20; int Kg = 16; int Kb = 32;
int Wr = 297; int Wg = 252; int Wb = 521;

int gotcolor = 0;
int letter;

void setup()
{
  Serial.begin(9600); // Start communication with serial port read value
  Color90.begin(4800); // Send signal to led to read value

  pinMode(2,INPUT); // serial pin out from color pal
  pinMode(3,INPUT); // from same serial pin, signal pulls up, sends, pulls down, reads
  digitalWrite(2,HIGH); // Enable the pull-up resistor
  digitalWrite(3,HIGH); // Enable the pull-up resistor

  pinMode(2,OUTPUT); // send signal out
  pinMode(3,OUTPUT);
  digitalWrite(2,LOW); // turn pin off so pin 3 can go high
  digitalWrite(3,LOW);

  pinMode(2,INPUT); // Input signal to print
  pinMode(3,INPUT);

  Serial.println("Pass 1");
//  delay(20);

  while( digitalRead(2) != HIGH || digitalRead(3) != HIGH ) {
    Serial.println("In the loop");
    delay(50);
  }

  Serial.println("Pass 2");

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  delay(100);     // spec is 80, but not all ColorPAL units work with 80

  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  delay(100); 

}

// This oscillates back and forth on one wire to turn off led, send signal,
// turn on led, read signal. very fast strobe read - arduino is not capable of
// one wire signal communication over digital ports, so this is a way around
// that over 2 wires communicating with 1 pin on the sensor.
//---------------------------------

void loop()
{
  readcolor();
  Serial.print("R");
  Serial.print(Cr);
  Serial.print("   G");
  Serial.print(Cg);
  Serial.print("   B");
  Serial.println(Cb); 
  gotcolor = 0;
  delay(100);

}
void readcolor() {  // Reads ColorPAL, putting results in the red,grn,blu variables

  char rByte[9];
  char dummy[4];

  delay(20);
  Color90.begin(4800);
 Color90.print("= (00 $ m) !");  // set up loop to continuously send color data
  pinMode(3,INPUT);
  gotcolor = 0;
  while (gotcolor == 0) {
    rByte[0] = Color90.read();
    if( rByte[0] == '$' ) {
      gotcolor = 1;
      for(int i=0; i<9; i++) {
        rByte[i] = Color90.read();
//        Serial.print(rByte[i]);
      }
      Serial.println("");
      dummy[0] = rByte[0];
      dummy[1] = rByte[1];
      dummy[2] = rByte[2];
      dummy[3] = 0;

      red = strtol(dummy,NULL,16);
      Cr = (float) (red - Kr) / (Wr - Kr);

      dummy[0] = rByte[3];
      dummy[1] = rByte[4];
      dummy[2] = rByte[5];

      grn = strtol(dummy,NULL,16);
      Cg = (float) (grn - Kg) / (Wg - Kg);

      dummy[0] = rByte[6];
      dummy[1] = rByte[7];
      dummy[2] = rByte[8];

      blu = strtol(dummy,NULL,16); 
      Cb = (float) (blu - Kb) / (Wb - Kb);
    }
  }
}
