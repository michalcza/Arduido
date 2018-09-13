#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ethernet.h>
#include <SPI.h>
#include <ArdSim.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
ArdSimUDP;

ArdSimConnect USB;                                    // -- LAN or USB

#define   Gear1            9, 1                       // -- Pin, dataref
#define   Gear2           10, 2                       // -- Pin, dataref
#define   Gear3           11, 3                       // -- Pin, dataref
#define   GearTransit     12, 4                       // -- Pin, dataref

int   RALT=GetData(5);                                //  number of dataref (5) in the out_x.cfg file - radio altitude value (not working)
int   BALT=GetData(6);                                //  number of dataref (6) in the out_x.cfg file - barometric altitude value
int   IAS=GetData(7);                                 //  number of dataref (7) in the out_x.cfg file - indicated airspeed value
int   VS=GetData(8);                                  //  number of dataref (8) in the out_x.cfg file - vertical speed value
int   AP_ALT=GetData(9);                              //  dataref (9) - autopilot altitude setting
int   AP_VS=GetData(19);                              //  dataref (10) - autopilot vertical velocity setting
int   AP_SPEED=GetData(11);                           //  dataref (11) - autopilot airspeed setting
int   AP_HDG=GetData(12);                             //  dataref (12) - autopilot magnetic heading setting
int   HDG=GetData(13);                                //  dataref (13) - flight model magnetic heading
int   AP_STATE=GetData(14);                           //  dataref (14) - AP state flags (http://www.xsquawkbox.net/xpsdk/mediawiki/Sim/cockpit/autopilot/autopilot_state)
boolean   ALT_HOLD=GetData(15);                           //  dataref (15) - int    n	boolean	Altitude is armed, 0 or 1.
//int   NAV_STAT=GetData(21);                             //dataref (22) - int	n	enum	Autopilot Nav Status. 0=off,1=armed,2=captured
int NAV_STAT=GetData(22);                               //sim/cockpit/autopilot/mode_hnav	int	y	enum	Localizer mode (off, armed, engaged). DEPRECATED
//TODO
//-instead of writing a blank space for each character space that is used, I should take and chech the length of the variable
//that I just pulled from the ref and -1 from that number when setting the lcd cursor to write the " " command. This should
//make everything much smaller and simple.

/*----( SETUP: RUNS ONCE )----*/
void setup()
{
  Serial.begin(9600);                                 // Used to type in characters
  lcd.begin(20,4);                                    // initialize the lcd for 20 chars 4 lines, turn on backlight
  lcd.backlight();                                    // backlight on
  BoardNumber 1;                                      // define Arduino board number for ArdSim

{                                                       //flash LED landing gear for a second
    LEDout (9, ON);
    LEDout (10, ON);
    LEDout (11, ON);
    LEDout (12, ON);
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
void loop()/*----( LOOP: RUNS CONSTANTLY )----*/
{

  {
  ArdSimScan;
    LEDout ( Gear1 );
    LEDout ( Gear2 );
    LEDout ( Gear3 );
    LEDout ( GearTransit );

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
                    lcd.print(" ");}
      IAS = GetData(7);
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
      AP_SPEED = GetData(11);                                   //autopilot speed setting Row 3, Column 1
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
                    lcd.print(" ");}
      /*
      else if (10 < VS){
                    lcd.setCursor(4,3);
                    lcd.print(VS);
                    lcd.setCursor(5,3);
                    lcd.print(" ");}
                    */
      AP_VS = GetData(10);                                      //autopilot vertical speed setting Row 3, Column 1
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
                    lcd.print(" ");}
//autopilot status display
      NAV_STAT=GetData(22);
      if (NAV_STAT == 9){
          lcd.setCursor(16,0);
          lcd.print("OFF");
      }
      else if (NAV_STAT == 21){
          lcd.setCursor(16,0);
          lcd.print("ARM");
      }
      else if (NAV_STAT == 22){
          lcd.setCursor(16,0);
          lcd.print("ENG");
      }
  }
}/* ----(end main loop )---- */
