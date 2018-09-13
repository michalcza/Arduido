/*
Stepper code for ArdSim Library.
For X25 alike steppers with the limiter 
and linear scale  (BETA version)

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



//------ define parameters: (1 - number of dataref, 2 - minimum dataref value, 3 - max dataref value )

#define RPM1   7, 0, 2600     // RPM #1 , dataref #7, range  0...2600 RPM
#define Flaps  6, 0,1          // Flaps position, dref #6, range   0 - 1.0


//----------------------1---------
void setup()  {  

 BoardNumber 1;

InputPin(NOINPUT);
  
/* Assign steppers: 1 pin number for stepper input #1
                    2 - pin number for stepper input #4   
                    3 - pin number for stepper inputs #2 and #3
                    4 - defined parameter.
                                                      */
  StepGauge(5, 6, 7, RPM1);
  StepGauge(22, 23, 24, Flaps );

 }
  
//--------------------------
void loop() { 

  ArdSimScan;  // scan and send all inputs and read data for output

 

 } 
//---------





