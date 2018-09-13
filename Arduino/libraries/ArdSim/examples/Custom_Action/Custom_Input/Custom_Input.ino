/*
Use your custom code conditions 
to send  commands for input

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

//---------------------


void setup() {

BoardNumber 1;


}
  
//--------------------------
void loop() { 
  
 ArdSimScan; 

// Send commans/datarefs to X-Plane from your custom code 
   
      {  // your custom code here

          // you can check some code conditions and send  command C7:
  
          SimInput(7);                                       
      }


} 
//--- End -------------------

/* input config file in_1.cfg:
===================================

C7 sim/radios/nav1_standy_flip
===================================

*/
