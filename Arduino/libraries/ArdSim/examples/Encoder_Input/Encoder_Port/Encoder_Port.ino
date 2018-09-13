/*
Encoder Port (matrix) inputs for ArdSim library
For thids demo use the input config file below on this page.

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

//-----------------------
void setup() {

BoardNumber 1;

        // assign 3 pins for encoder input port:
        
EncoderPort(14); // Port input pins : #14,15,16; 


        // assign encoder pins (one for each encoder E1...E4):

EncoderPin (8);   // Encoder #1 (E1), NO button  
EncoderPin (9);   // Encoder #2 (E2),  NO button  
EncoderPin (2, 4); // Encoder #3 (E3),  button mode =4 (4-click mode)
EncoderPin (3, 1); // Encoder #4 (E4),  button mode =1 (hold mode) 


  }
  
//--------------------------
void loop()   { 
  
ArdSimScan;


 } 
//--- End -------------------

/* input test config file in_1.cfg:

===================================
  //  Encoder #1 has no internal button, single mode
  
E1+ sim/radios/obs_HSI_up
E1- sim/radios/obs_HSI_down

   //  Encoder #2 has no internal button, single mode

E2+ sim/instruments/barometer_up
E2- sim/instruments/barometer_down
 
   //  Encoder #3 has internal button, 4-mode clicked
   
E3/1+ sim/transponder/transponder_ones_up
E3/1- sim/transponder/transponder_ones_down
E3/2+ sim/transponder/transponder_tens_up
E3/2- sim/transponder/transponder_tens_down
E3/3+ sim/transponder/transponder_hundreds_up
E3/3- sim/transponder/transponder_hundreds_down
E3/4+ sim/transponder/transponder_thousands_up
E3/4- sim/transponder/transponder_thousands_down

   //  Encoder #4 has internal button, mode=1 "press&hold"

E4/1+ sim/radios/stby_nav1_coarse_up
E4/1- sim/radios/stby_nav1_coarse_down
E4/2+ sim/radios/stby_nav1_fine_up
E4/2- sim/radios/stby_nav1_fine_down

===================================

You will get:

1) Encoder #1 simply changes the HSI OBS course (no mode buttons)

2) Encoder #2  changes the Barometer value  (no mode buttons)

3) Encoder #3 changes transponder "ones-tens-hundreds-thousands 
  changing mode in cycle when its buil-in button is clicked
  
4) Encoder #4 set Nav1 "coarse" frequency when its built-in button is not pressed,
    and Nav1 "fine"  frequency when its  button is  pressed and held
    
*/

