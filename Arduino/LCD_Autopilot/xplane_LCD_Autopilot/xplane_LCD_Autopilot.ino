#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ethernet.h>
#include <SPI.h>
#include <ArdSim.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
ArdSimUDP;

ArdSimConnect USB;                                    // -- LAN or USB
/*
#define   Gear1            9, 1                       // -- Pin, dataref
#define   Gear2           10, 2                       // -- Pin, dataref
#define   Gear3           11, 3                       // -- Pin, dataref
#define   GearTransit     12, 4                       // -- Pin, dataref
*/
#define   lights_landing     12, 24

                               //sim/cockpit/autopilot/mode_hnav	int	y	enum	Localizer mode (off, armed, engaged). DEPRECATED


/*----( SETUP: RUNS ONCE )----*/
void setup()
{
  lcd.begin(20,4);                                    // initialize the lcd for 20 chars 4 lines, turn on backlight
  lcd.backlight();                                    // backlight on
  BoardNumber 1;                                      // define Arduino board number for ArdSim

                                                       //flash LED landing gear for a second

    lcd.setCursor(0,0);                                 //position 0, line 0
    lcd.print("HDG ");
    lcd.setCursor(0,1);                                 //position 0, line 1
    lcd.print("ALT ");
    lcd.setCursor(0,2);                                 //position 0, line 2
    lcd.print("IAS ");
    lcd.setCursor(0,3);                                 //position 0, line 3
    lcd.print("VS ");
}
void loop()/*----( LOOP: RUNS CONSTANTLY )----*/
{

  {
  ArdSimScan;

      /*
    LEDout ( Gear1 );
    LEDout ( Gear2 );
    LEDout ( Gear3 );
    LEDout ( GearTransit );
*/
LEDout (lights_landing);
/*
//flight dynamics displayed to LCD
      HDG =   GetData(13);                              //Indicated heading Row 0, Column 0
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
      */
  }
}/* ----(end main loop )---- */
