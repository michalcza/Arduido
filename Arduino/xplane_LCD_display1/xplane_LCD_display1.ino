#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Ethernet.h>
#include <SPI.h>
#include <ArdSim.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
ArdSimUDP;

ArdSimConnect USB;                                    // -- LAN or USB
#define   Gear1           9,  1                       // -- Pin, dataref, "on" value  = 1
#define   Gear2           10, 2                       // -- Pin, dataref
#define   Gear3           11, 3                       // -- Pin, dataref
#define   GearTransit     12, 4                       // -- Pin, dataref
int   IAS=GetData(28);                   //  number of dataref (5) in the out_x.cfg file
//int   ALT=GetData(6);                  //  number of dataref (6) in the out_x.cfg file
//int   IAS2=GetData(7);                   //  number of dataref (7) in the out_x.cfg file
//int   VS=GetData(8);                   //  number of dataref (8) in the out_x.cfg file
/*----( SETUP: RUNS ONCE )----*/
void setup()
{
  Serial.begin(9600);                                 // Used to type in characters
  lcd.begin(20,4);                                    // initialize the lcd for 20 chars 4 lines, turn on backlight
  lcd.backlight();                                    // backlight on
  BoardNumber 1;                                      // define Arduino board number for ArdSim

  {
    lcd.setCursor(0,0);                                 //position 0, line 0
      lcd.print("IAS ");
    lcd.setCursor(0,1);                                 //position 0, line 1
      lcd.print("ALT ");
    lcd.setCursor(0,2);                                 //position 0, line 2
      lcd.print("IAS2 ");
    lcd.setCursor(0,3);                                 //position 0, line 3
      lcd.print("VS ");

    }
}
void loop()/*----( LOOP: RUNS CONSTANTLY )----*/
 {

  {
  ArdSimScan;
  //Should add NewData condition to the gear status
    LEDout ( Gear1 );
    LEDout ( Gear2 );
    LEDout ( Gear3 );
    LEDout ( GearTransit );

   if (NewData(5)) {
          IAS = GetData(5);
                 lcd.setCursor(5,0);
                 lcd.print (IAS);
         delay(10);
 }
    if (NewData(6)) {
          ALT = GetData(6);
                 lcd.setCursor(5,1);
                 lcd.print (ALT);
         delay(10);
 }
     if (NewData(7)) {
          IAS2 = GetData(7);
                 lcd.setCursor(5,2);
                 lcd.print (IAS2);
         delay(10);
 }
     if (NewData(8)) {
          VS = GetData(8);
                 lcd.setCursor(5,3);
                 lcd.print (VS);
         delay(10);
 }



  }
}/* ----(end main loop )---- */
