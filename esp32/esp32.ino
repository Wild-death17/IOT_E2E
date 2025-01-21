//-----------------------------------
#include <DHT.h>
//-----------------------------------
#define OFF 0
#define LEFT 16
#define RIGHT 17
#define LIGHT 36
#define TEMP 16
 #define DHTTYPE DHT11  
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
  // SEND_DATA();
  HandleWaterPump(PumpState);
  HandleLight();
  HandleTemp();
  delay(1000);
}
//-----------------------------------

