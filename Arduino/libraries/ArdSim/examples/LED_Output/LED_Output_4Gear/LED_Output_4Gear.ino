/*
ArdSim Library Output demonstration
4 LED outputs controlled with gear datarefs. 

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

ArdSimConnect LAN;  

  // define 4 LED connections ( first number - Arduino pin, second is dataref number

#define  Gear1   5, 1     // { 5 = LED pin number 1 = dataref number (can be found in you out_1,cfg list)
#define  Gear2   6, 2  				
#define  Gear3   7, 3  
#define  GearTransit   8, 4 

//---------------------
void setup()  { 
 
  BoardNumber 1;


}
//--------------------------
void loop()  { 

ArdSimScan; 


   LEDout(Gear1);  
   LEDout(Gear2);    
   LEDout(Gear3); 
   LEDout(GearTransit);    
   
   
} 

//--- End -------------------

/* output config file out_1.cfg:

===================================

1 1 sim/flightmodel2/gear/deploy_ratio 1
2 1 sim/flightmodel2/gear/deploy_ratio 2
3 1 sim/flightmodel2/gear/deploy_ratio 3
4 0 sim/cockpit2/annunciators/gear_unsafe
===================================

You should see:
1) LED on pin #5 will be On when the 1st gear is full down
2) LED on pin #6 will be On when the 2nd gear is full down   
3) LED on pin #7 will be On when the 3rd gear is full down 
4) LED on pin #8 will be On while all gear unsafe 

*/




