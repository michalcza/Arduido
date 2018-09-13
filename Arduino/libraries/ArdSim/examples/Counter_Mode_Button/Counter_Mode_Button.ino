

//================================ 
#include <SPI.h> 
#include <ArdSim.h>    //  -- ArdSim library 
//================================ 

//================================ 
#include <Ethernet.h>    
ArdSimUDP;
//================================

ArdSimConnect LAN;       // -- if USB interface is used change "LAN" to "USB' 

int cbtn=1;
int DMEspd;
int DMEdist;
int DMEtime;
int dmeData;

//----------------------
void setup() {

BoardNumber 1;


}
  
//--------------------------
void loop() { 
  

 ArdSimScan;

// first you get needed data (always use getdata with NewData function!):

if ( NewData (9) )     DMEspd = GetData (9);    // get new DME speed
if ( NewData (10) )    DMEdist = GetData (10);	// get new DME distance
if ( NewData (11) )    DMEtime = GetData (11);	// get new DME time

// Then you check if the button was clicked (cbtn - modes 1,2, 3,   if cbtn=0 nothing happens):
 
   int cb = CountButton (5, 3);   // button on the pin #5  has 3 switchable modes

	if (cb!=0) { cbtn=cb;

if (cbtn==1)   dmeData =  DMEspd ;              //if mode = 1 indicate speed 
if (cbtn==2)   dmeData =  DMEdist ;             //if mode = 2 indicate distance 
if (cbtn==3)   dmeData =  DMEtime ;             //if mode = 3 indicate time 
			}

        // here your output function of GSpeed or distance or time

} 
//--- End -------------------

/*
Datarefs used for output:

9  1  sim/cockpit2/radios/indicators/nav1_dme_distance_nm
10 0  sim/cockpit2/radios/indicators/nav1_dme_speed_kts
11 0  sim/cockpit2/radios/indicators/nav1_dme_time_min

*/

