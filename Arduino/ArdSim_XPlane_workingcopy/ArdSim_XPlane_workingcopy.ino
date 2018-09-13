#include <SPI.h>
#include <ArdSim.h>
#include <Ethernet.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
ArdSimUDP;
ArdSimConnect USB;

//(name, pin number, line in the out_1.cfg file)
#define   Gear1           41,  25
#define   Gear2           39,  26
#define   Gear3           38,  27
#define   GearTransit     40,  4

int   IAS=GetData(28);                   //  number of dataref (5) in the out_x.cfg file
int   ALT=GetData(29);                   //  number of dataref (6) in the out_x.cfg file

void setup()
{
    Serial.begin(9600);                                 // Used to type in characters
    lcd.begin(20,4);                                    // initialize the lcd for 20 chars 4 lines, turn on backlight
    lcd.backlight();                                    // backlight on
    BoardNumber 1;                                      // define Arduino board number for ArdSim
{
    //AnalogIn ( APin, Prec )
    //precision is 1-1023 steps
AnalogIn (0, 100 );
AnalogIn (1, 100 );
AnalogIn (2, 100 );
AnalogIn (3, 100 );
AnalogIn (4, 100 );
AnalogIn (5, 100 );
AnalogIn (6, 100 );
AnalogIn (7, 100 );
EncoderPin (22);
EncoderPin (23);
EncoderPin (24);
EncoderPin (25);
EncoderPin (27);
InputPin (28);
InputPin (29);
InputPin (30);
InputPin (31);
InputPin (32);
InputPin (33);
InputPin (34);
InputPin (35);
InputPin (36);

LEDout (38, ON);        // gear no 3 LED
LEDout (39, ON);        // gear no 2 LED
LEDout (40, ON);        // gear transit LED
LEDout (41, ON);        // gear no 1 LED
InputPin (42);
InputPin (44);
InputPin (45);
InputPin (46);
InputPin (47);
InputPin (48);
InputPin (49);
InputPin (50);
InputPin (51);
}
    {
        delay (1000);
    }
    lcd.setCursor(0,0);                                 //position 0, line 0
    lcd.print("HDG ");
    lcd.setCursor(0,1);                                 //position 0, line 1
    lcd.print("ALT ");
    lcd.setCursor(0,2);                                 //position 0, line 2
    lcd.print("IAS ");
    lcd.setCursor(0,3);                                 //position 0, line 3
    lcd.print("VS ");
}

void loop()
{
    {
ArdSimScan;
  LEDout ( Gear1 );
  LEDout ( Gear2 );
  LEDout ( Gear3 );
  LEDout ( GearTransit );

}
//flight dynamics displayed to LCD
      /*HDG =   GetData(13);                              //Indicated heading Row 0, Column 0
      if ((10 < HDG) && (HDG <= 99)){       //we only need to worry about 3 character slots to clean up
                    lcd.setCursor(4,0);
                    lcd.print(HDG);
                    lcd.setCursor(6,0);
                    lcd.print(" ");}
      else if (10 < HDG){
                    lcd.setCursor(4,0);
                    lcd.print(AP_HDG);
                    lcd.setCursor(5,0);
                    lcd.print(" ");}
      AP_HDG = GetData(12);                                         //Autopilot heading setting Row 0, Column 1
      if ((10 < AP_HDG) && (AP_HDG <= 99)){             //we only need to worry about 3 character slots to clean up
                    lcd.setCursor(10,0);
                    lcd.print(AP_HDG);
                    lcd.setCursor(12,0);
                    lcd.print(" ");}
      else if (10 < AP_HDG){
                    lcd.setCursor(10,0);
                    lcd.print(AP_HDG);
                    lcd.setCursor(11,0);
                    lcd.print(" ");}
      BALT = GetData(6)*3.281;                                    //values reported in meters converting to feet by multiplying 3.281
      if(BALT >= 10000){
                    lcd.setCursor(4,1);
                    lcd.print(AP_ALT);
                    lcd.setCursor(9,1);
                    lcd.print(" ");}
      else if ((1000 < BALT) && (BALT <= 9999)){
                    lcd.setCursor(4,1);
                    lcd.print(BALT);
                    lcd.setCursor(8,1);
                    lcd.print(" ");}
      else if ((100 < BALT) && (BALT <= 999)){
                    lcd.setCursor(4,1);
                    lcd.print(BALT);
                    lcd.setCursor(7,1);
                    lcd.print(" ");}
      else if ((10 < BALT) && (BALT <= 99)){
                    lcd.setCursor(4,1);
                    lcd.print(BALT);
                    lcd.setCursor(6,1);
                    lcd.print(" ");}
      else if (10 < BALT){
                    lcd.setCursor(4,1);
                    lcd.print(BALT);
                    lcd.setCursor(5,1);
                    lcd.print(" ");}
      AP_ALT = GetData(9);
      if(AP_ALT >= 10000){
                    lcd.setCursor(10,1);
                    lcd.print(AP_ALT);
                    lcd.setCursor(15,1);
                    lcd.print(" ");}
      else if ((1000 < AP_ALT) && (AP_ALT <= 9999)){
                    lcd.setCursor(10,1);
                    lcd.print(AP_ALT);
                    lcd.setCursor(14,1);
                    lcd.print(" ");}
      else if ((100 < AP_ALT) && (AP_ALT <= 999)){
                    lcd.setCursor(10,1);
                    lcd.print(AP_ALT);
                    lcd.setCursor(13,1);
                    lcd.print(" ");}
      else if ((10 < AP_ALT) && (AP_ALT <= 99)){
                    lcd.setCursor(10,1);
                    lcd.print(AP_ALT);
                    lcd.setCursor(12,1);
                    lcd.print(" ");}
      else if (10 < AP_ALT){
                    lcd.setCursor(10,1);
                    lcd.print(AP_ALT);
                    lcd.setCursor(11,1);
                    lcd.print(" ");}*/
IAS = GetData(28);
      if (IAS >= 10000){
                    lcd.setCursor(4,2);
                    lcd.print(IAS);
                    lcd.setCursor(9,2);
                    lcd.print(" ");}
      else if ((1000 < IAS) && (IAS <= 9999)){
                    lcd.setCursor(4,2);
                    lcd.print(IAS);
                    lcd.setCursor(8,2);
                    lcd.print(" ");}
      else if ((100 < IAS) && (IAS <= 999)){
                    lcd.setCursor(4,2);
                    lcd.print(IAS);
                    lcd.setCursor(7,2);
                    lcd.print(" ");}
      else if ((10 < IAS) && (IAS <= 99)){
                    lcd.setCursor(4,2);
                    lcd.print(IAS);
                    lcd.setCursor(6,2);
                    lcd.print(" ");}
      else if (10 < IAS){
                    lcd.setCursor(4,2);
                    lcd.print(IAS);
                    lcd.setCursor(5,2);
                    lcd.print(" ");}
     /* AP_SPEED = GetData(11);                                   //autopilot speed setting Row 3, Column 1
      if(AP_SPEED >= 10000){
                    lcd.setCursor(10,2);
                    lcd.print(AP_SPEED);
                    lcd.setCursor(15,2);
                    lcd.print(" ");}
      else if ((1000 < AP_SPEED) && (AP_SPEED <= 9999)){
                    lcd.setCursor(10,2);
                    lcd.print(AP_SPEED);
                    lcd.setCursor(14,2);
                    lcd.print(" ");}
      else if ((100 < AP_SPEED) && (AP_SPEED <= 999)){
                    lcd.setCursor(10,2);
                    lcd.print(AP_SPEED);
                    lcd.setCursor(13,2);
                    lcd.print(" ");}
      else if ((10 < AP_SPEED) && (AP_SPEED <= 99)){
                    lcd.setCursor(10,2);
                    lcd.print(AP_SPEED);
                    lcd.setCursor(12,2);
                    lcd.print(" ");}
      else if (10 > AP_SPEED){
                    lcd.setCursor(10,2);
                    lcd.print(AP_SPEED);
                    lcd.setCursor(11,2);
                    lcd.print(" ");}
      VS =  GetData(8);                                         //indicated vertical speed Row 3, Column 1
      if (VS >= 10000){
                    lcd.setCursor(4,3);
                    lcd.print(VS);
                    lcd.setCursor(9,3);
                    lcd.print(" ");}
      else if ((1000 < VS) && (VS <= 9999)){
                    lcd.setCursor(4,3);
                    lcd.print(VS);
                    lcd.setCursor(8,3);
                    lcd.print(" ");}
      else if ((100 < VS) && (VS <= 999)){
                    lcd.setCursor(4,3);
                    lcd.print(VS);
                    lcd.setCursor(7,3);
                    lcd.print(" ");}
      else if ((10 < VS) && (VS <= 99)){
                    lcd.setCursor(4,3);
                    lcd.print(VS);
                    lcd.setCursor(6,3);
                    lcd.print(" ");}*/
      /*
      else if (10 < VS){
                    lcd.setCursor(4,3);
                    lcd.print(VS);
                    lcd.setCursor(5,3);
                    lcd.print(" ");}
                    */
      /*AP_VS = GetData(10);                                      //autopilot vertical speed setting Row 3, Column 1
      if(AP_VS >= 10000){
                    lcd.setCursor(10,3);
                    lcd.print(AP_VS);
                    lcd.setCursor(15,3);
                    lcd.print(" ");}
      else if ((1000 < AP_VS) && (AP_VS <= 9999)){
                    lcd.setCursor(10,3);
                    lcd.print(AP_VS);
                    lcd.setCursor(14,3);
                    lcd.print(" ");}
      else if ((100 < AP_VS) && (AP_VS <= 999)){
                    lcd.setCursor(10,3);
                    lcd.print(AP_VS);
                    lcd.setCursor(13,3);
                    lcd.print(" ");}
      else if ((10 < AP_VS) && (AP_VS <= 99)){
                    lcd.setCursor(10,3);
                    lcd.print(AP_VS);
                    lcd.setCursor(12,3);
                    lcd.print(" ");}
      else if (10 < AP_VS){
                    lcd.setCursor(10,3);
                    lcd.print(AP_VS);
                    lcd.setCursor(11,3);
                    lcd.print(" ");}*/
    }
}


