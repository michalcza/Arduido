



//================================ 
#include <SPI.h> 
#include <ArdSim.h>    //  -- ArdSim library 
//================================ 

//================================ 
//#include <Ethernet.h>       // you can comment these two lines
//ArdSimUDP;						//   if USB interface is used
//================================

ArdSimConnect USB;


void setup()  { 
  
BoardNumber 1;   // - board number from 1  to 9


//USB_SPD 115200;      // chabge USB serial speed (change in the config.ini file too)
//XPLANE_IP (192,168,0,104);  // set IP address of X-Plane PC
//ARDUINO_IP (192,168,0,3);   //  set IP address of Arduino
//ARDSIM_PORT 5080;				// change port number if nedeed (in the config.ini file too)

//MAC_ADDR ( 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xFF );  // If you have label with MAX address on your Ethernet shield 

} 

//------------------------------------------
void loop()   { 
  
     ArdSimScan; 
   
    

}      
//========================================


