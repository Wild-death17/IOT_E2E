//-----------------------------------
#include <DHT.h>
//-----------------------------------
#define OFF 0
#define LEFT 16
#define RIGHT 17
#define LIGHT 36
#define TEMP 16
#define Moisture 36
#define DHTTYPE DHT11 
#define ADMIN "http://10.9.2.107"
#define PORT 3214 
//-----------------------------------
  int PumpState = OFF;
  DHT dht(TEMP,DHTTYPE); 
//-----------------------------------

void setup()
{
  Serial.begin(115200);
  WiFi_SETUP();
  WaterPumpSetup();
  TempSetup();
}
void loop()
{
  SEND_DATA( HandleTemp(), HandleLight(), HandleMoisture() );
  HandleWaterPump(PumpState);
  delay(1000);
}
//-----------------------------------

