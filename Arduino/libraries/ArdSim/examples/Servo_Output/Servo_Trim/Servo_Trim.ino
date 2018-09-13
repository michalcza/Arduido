/*

ArdSim Library Output demonstration
Servo output, BETA

by Vlad Sychev 2012-2016
Download ARDsim Library on the SimVim Design website:
http://arduino.svglobe.com
 */

//================================ 
#include <SPI.h> 
#include <ArdSim.h>    //  -- ArdSim library 
//================================ 

//================================ 
#include <Ethernet.h>    
ArdSimUDP;
//================================

ArdSimConnect LAN;       // -- if USB interface is used change "LAN" to "USB' 

// define  Servo 

#define TrimR    17, -1, 1, 1160, 2000  


//---------------------
void setup()  { 
 
   BoardNumber 1;
   

EncoderPin (11, 2);  // Encoder for Rudder Trim

 AnalogIn(1, 1000);   // Or analog pot for Rudder trim
 
} 
 
 
//--------------------------
void loop()  { 

ArdSimScan; 
 
servoGauge (29, TrimR);   // Rudder Trim Gauge


} 
//---- End -----
/*
Use test output file  out_N.cfg  included in the ArdRsm Plugin package

In the input config file add these lines:

A1   sim/cockpit2/controls/rudder_trim  -1,1

    // or:

E1+ sim/flight_controls/rudder_trim_right
E1- sim/flight_controls/rudder_trim_left

*/
