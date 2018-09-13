/*
Servo output, non-linear servo output

(BETA version)

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

ArdSimConnect LAN;    // -- if USB interface is used change "LAN" to "USB' 

// define 3 Servo connections

#define Flap    40, 0, 1, 560, 2100                  // servo on pin #40
#define Amp     41, 0, 100, 560, 2150              // servo on pin #41
#define RPM     42, 600, 2500, 2150, 560          // servo on pin #42



// --- define ONE servo for 3-section gauge:

#define   RPM1      12,   0,    1300,  600,  1067
#define   RPM2      12,   1301, 2000,  1068, 1734
#define   RPM3      12,   2001, 2300,  1735, 2030


//---------------------
void setup()  { 
 
  BoardNumber 1;


} 
 
//--------------------------
void loop()  { 

ArdSimScan; 
 

servoGauge (6, Flap);  // dataref #6 used in "out_1.cfg" file

servoGauge (25, Amp);  // dataref #25 used in "out_1.cfg" file

  // dataref #7 (RPM) - for 3-sector RPM gauge
servoGauge ( 7, RPM1 );
servoGauge ( 7, RPM2 );
servoGauge ( 7, RPM3 );


} 
//---- End -----
/*
Use test output file  out_N.cfg  included in the ArdRsm Plugin package
*/
