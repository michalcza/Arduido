// I2C Scanner
// Written by Nick Gammon
// Date: 20th April 2011

//You can scan for the I2C address used by your display.
//Connect your display (See connection info at top of this page).
//Then upload the following sketch to your Arduino.
//Click on "Serial Monitor at upper right.
//Set the Speed (lower right pulldown) to 115200.
//Push the Reset button on your Arduino and see the results.

#include <Wire.h>

void setup() {
  Serial.begin (115200);

  // Leonardo: wait for serial port to connect
  while (!Serial)
    {
    }

  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;

  Wire.begin();
  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
      {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);  // maybe unneeded?
      } // end of good response
  } // end of for loop
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}  // end of setup

void loop() {}

