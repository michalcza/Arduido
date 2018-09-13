/*
  Base code for ArdSim LAN/USB Library.

  Upload and connect buttons / switches to any
  digital inputs accordingly with your input config file to test

  Download ARDsim Library on the SimVim Design website:
  http://arduino.svglobe.com
*/


//================================
#include <SPI.h>
#include <ArdSim.h>    //  -- ArdSim library
#include <Ethernet.h>

ArdSimUDP;
//================================

ArdSimConnect USB;       // -- if USB interface is used change "LAN" to "USB'

#define   Gear1           9,  1                    // -- Pin#5, dataref #1, "on" value  = 1
#define   Gear2           10,  2                    // -- Pin#6, dataref #2
#define   Gear3           11,  3                    // -- Pin#7, dataref #3
#define   GearTransit     12,  4                    // -- Pin#8, dataref #4
//------------------------------------------
void setup()  {
  BoardNumber 1;
}
//------------------------------------------
void loop()   {

  ArdSimScan;
  LEDout ( Gear1 );
  LEDout ( Gear2 );
  LEDout ( Gear3 );
  LEDout ( GearTransit );
}
//===========================================



