/*
ArdSim Analog input demonstration 
- use analog inputs as additional digital inputs:
by Vlad Sychev 2012-2016
Download ArdSim Library on the SimVim Design website:
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


//---------------------------------------------
void setup()  { 
 
    BoardNumber 1;  //Assign Board Number!  (0...9)
  

  AnalogSwitch(2, 2);   // simple toggle switch (2-positions),  pin A2
  AnalogSwitch(3, 5);  //  5-position switch (or 5-buttons), pin A3
  AnalogSwitch(4, 6);  //  6-position switch, pin A4
   
    /*  !!  Comment or delete lines with unused Analog inputs to prevent 
            scanning open inputs and unintentional sending the input interference data   */

  }
  
//--------------------------
void loop()  { 

ArdSimScan; // scan and send all inputs and read data for output




 } 
 //===== end =============


/* 
input config file sample in_1.cfg:

===================================

    // - simple switch on the inputs A2: 
    
A2/1   sim/electrical/generator_1_on
A2/2   sim/electrical/generator_1_off

	#-- 5-position rotary switch on the A3 input for magneto/starter

A3/1 sim/magnetos/magnetos_off_1
A3/2 sim/magnetos/magnetos_right_1   
A3/3 sim/magnetos/magnetos_left_1
A3/4 sim/magnetos/magnetos_both_1
A3/5 sim/starters/engage_starter_1 

   #--   6-position switch on the A4 input for KT-70 Transponder mode

A4/1  sim/transponder/transponder_off
A4/2  sim/transponder/transponder_standby
A4/3  sim/transponder/transponder_alt   
A4/4  sim/transponder/transponder_test
A4/5  sim/transponder/transponder_on
A4/6  sim/transponder/transponder_ground

===================================
*/



