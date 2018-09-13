

//================================ 
#include <SPI.h> 
#include <ArdSim.h>    //  -- ArdSim library 
//================================ 
#include <Wire.h> 

//================================ 
#include <Ethernet.h>    
ArdSimUDP;
//================================

ArdSimConnect LAN;

I2C_DATA {SlaveOUT} 

//------------------------------------------
void setup()  { 

 BoardNumber 1;
 
 
} 



//------------------------------------------
void loop()   { 
 
     ArdSimScan; 

GetData(15);
SendToSlave (3, 6); 


}      

//=====================================================

