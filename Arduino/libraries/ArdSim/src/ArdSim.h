/*
	ArdSim input/output interface for cockpit simulator. 
	The latest version of this library, manuals and code samples at SimVimDesign:
	http://arduino.svglobe.com
	Ver 4.01 (7 Sep. 2016)
*/
#ifndef ArdSim_h
#define ArdSim_h
#include "Arduino.h"
#define DIRECT 1
#define STATIC 2
#define ON 255
#define OFF 0
#define MX 222
#define NOINPUT 100
#define ALL 222
#define ArdSimScan sim.SimScan()
#define SGau() servoGauge(byte srv, byte num, byte pin, float min, float max, int smin, int smax)
//-----------------------------------------
#define SlaveInit  Wire.onReceive(ReadMaster)
#define ArdSimSlave  void ReadMaster(int c) 
#define ArdSimStart sim.SimStart()
#define SlaveOUT Wire.beginTransmission(s); \
for (int n=0; n<6; n++) Wire.write(sim.to_slave[n]); Wire.endTransmission();
#define I2C_DATA void SendOUT(byte s)
#define ARDSIM_I2C  for (int n=0;n<6;n++) sim.to_slave[n]= Wire.read(); GetMaster();
//-----------------------------------------
#define BoardNumber sim.ARD=
#define ARDSIM_PORT sim.port=
#define USB_SPD sim.serial=
#define ArdSimUDP EthernetUDP Udp; \
IPAddress ipa (0,0,0,0); \
IPAddress ipx (0,0,0,0);
#define ArdSimConnect  byte xData(byte n, int d) 

#define USB { switch(n) { case 0: START_USB; break; case 1: GET_USB; break; case 2: SEND_USB;  break; \
case 3: VAL_USB; break; case 4: SEND_USB; break; case 6: READ_USB; break;  } }

#define LAN { switch(n) { \
case 0: START_LAN; break; case 1: GET_LAN; break; case 2: SEND_LAN; break; \
case 3: VAL_LAN; break; case 4: P_LAN; break; case 5: S_LAN; break; \
case 6: READ_LAN; break; case 7: PACK_LAN; break; case 8: STR_UDP; break; \
case 9: IP_LAN; break; case 10: IPX_LAN; break; case 11: START_UDP; break; \
case 12: SET_IPX; break; case 13: SET_IP; break; } }

#define START_USB Serial.begin(sim.serial); sim.lan=0
#define GET_USB  sim.ps=Serial.available(); return sim.ps
#define SEND_USB Serial.write(d)
#define READ_USB sim.inx=Serial.read(); return sim.inx
#define VAL_USB Serial.write(sim.value)
//#define PACK_USB Serial.readBytes(sim.db, d) 

#define IP_LAN  Ethernet.begin(sim.mac_ad); ipa=Ethernet.localIP() 
#define IPX_LAN  ipx=Udp.remoteIP()
#define START_UDP  Ethernet.begin(sim.mac_ad, ipa); Udp.begin(sim.port);
#define START_LAN  sim.lan=1
#define GET_LAN  sim.ps=Udp.parsePacket();  return sim.ps
#define SEND_LAN Udp.write(d) 
#define READ_LAN sim.inx=Udp.read(); return sim.inx
#define VAL_LAN Udp.write(sim.value) 
#define P_LAN if (d==62) Udp.beginPacket(ipx, sim.port); else Udp.endPacket() 
#define S_LAN  Udp.beginPacket(ipx, sim.xport) 
#define PACK_LAN Udp.read(sim.db, d);
#define STR_UDP Udp.write(sim.DREF)
#define SET_IPX ipx=sim.ipX
#define SET_IP ipa=sim.ipA

//byte xData(byte n=0, int d=0);

void InputMatrix(byte X1, byte X2, byte Y1, byte Y2);
void EncoderPort(byte port);
void EncoderPin(byte pin,  byte btn=0);
void EncModeBtn(byte pin, byte enc, byte id, byte mx=0);
byte EncMode(byte enc);
void EncModeLED(byte pin, byte enc, byte mod);
void RepeatBtn(byte num, byte mx=0);  
void AnalogIn(byte pin, word pre, word min=0, word max=1023); 
void AnalogSwitch(byte pin, word pos);
boolean ReadInput (byte pin, byte act=STATIC, byte mx=0);
byte CountButton (byte pin, byte mode,  byte mx=0);
void SimInput(byte id);
float GetData(byte idx);
boolean NewData(byte idx);
void LEDout(byte pin, byte dref, float val=1, float val1=-999, boolean inv=0);
void Gauge ( byte num, byte pin, float min, float max, int smin=0, int smax=100);
void servoGauge (byte num, byte pin, float min, float max, int smin, int smax);
void OutputPin(byte pin, byte last=0);
void InputPin(byte pin=222, byte last=0);
void SendToSlave(byte s, byte d0, byte d1=0, byte d2=0, byte d3=0, byte d4=0);
void GetMaster();
void SendOUT(byte s);
void SetData(byte idx, float val);
//----test -------------
void StepPos (byte st, int pos);
void StepGauge (byte A, byte B, byte mid, byte dref, float min, float max );
void StepperGauges();
void ARDUINO_IP(byte a1,byte a2,byte a3,byte a4);
void XPLANE_IP(byte a1,byte a2,byte a3,byte a4);
void MAC_ADDR(byte a1,byte a2,byte a3,byte a4,byte a5,byte a6);
//---------------- 	//XPD
void XPDref (char* DRef, float Val);
void XPCmnd (char* Com);
void XPMenu (int MenuNum); 
class ARDsim
{
public:
ARDsim();
void SimScan();
void SimStart();  //  setup
void Comm();
void SClr();
void ArdInit();
boolean ToSlave(byte data);
void SendPack(char* str, byte num);
void Scan();
void EncIn();
void MxIn();
void DirIn();
void AnIn();
void PinSet(byte pin, byte in=0); // 0 - in, 1 - out 
void AIn(byte num,  int val, byte type);
void Send(byte type, int num, byte dir=0, byte mode=0);
char inits; 	
word tscan;		

void Cmnd(char Data_com[]);								 	//XPD 
void Dref(char* dref, float Data);							//XPD 
void Menu(int mnum);									 	//XPD 
char* DREF;

char to_slave[6];
boolean start=0;
long serial=115200;
int ps;
byte db[128];
byte inx;
char value[5];
int lan=1;
unsigned int port=5080;
unsigned int xport=49000;
byte ipX[4]={0,0,0,0};
byte ipA[4]={0,0,0,0};
byte is_mac=0;
byte mac_ad[6]={ 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEC };
char ardn[5] = {'|','A','R','1','-'};

byte ARD;
byte w_pin;        // wire
boolean in_pin; 
unsigned long atime;     // timer ( 25 ms )
unsigned long inscan; 
float Dget[50];  
byte conf[10];
#if not (defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__))
byte flags[14]; 
word mxflag[5];
word mxhold[5];
byte d_pins=14;
byte brd=0;
#endif
#if (defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__))
int A_pos[16];    		 // prev pos (0-1000)
byte a_min[16];	byte a_max[16];		 // 0-100%
word aflags[16];	     // 2-50 pos + 100,200...1000 (2-110) +bit 127 if switch
word a_set[16];
byte d_pins=54; 
byte a_pins=16;
byte flags[54];  
word mxflag[16];
word mxhold[16];
byte brd=1;
#elif (defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega328__))
int A_pos[8]; 
byte a_min[8]; byte a_max[8];	 // 0-100%
word aflags[8];
word a_set[8];
byte a_pins=8;
#elif (defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__))
int A_pos[6];   
byte a_min[6]; byte a_max[6];	 // 0-100%
word aflags[6];	
word a_set[6];
byte a_pins=6;
#endif

byte mxa; 
byte cbtn;
byte Act; 
boolean active;
boolean tabu;
byte iscan=2;
byte Emem[25];			//  enc+btn last state 
byte Etyp[25];			//  enc+btn type
byte Emode[25];				//  mode 0, 1.... 8, A, B, C...
byte Epins[28];   		// (0-24 -enc pins) +flags: 25-enab/type; 26-port, 27- enc number
int edel;
int espd;
byte Bx1;
byte Bx2;
byte By1;
byte By2;
//------------------------
void ServoSet();
byte snum; //srv count
byte srp; // prev srv pin
int sGau[20];
byte srvpin[20];
unsigned long stime;    // servo timer
//-----------
void stp_dn(byte st, int val);
void stp_up(byte st, int val);
void StepGau (byte st, int phase, int dir);
void StepRes();
byte A_coil[10];
byte mid[10];
byte B_coil[10]; 
byte sdref[10];
float stmin[1];
float stmax[10];
int mstep[10]; 
int abspos[10];
byte stn;
private:
};
extern ARDsim sim; 
extern byte xData(byte n=0, int d=0);
#endif
