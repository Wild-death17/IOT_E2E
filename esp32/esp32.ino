//--Library--------------------------
#include <DHT.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#define DHTTYPE DHT11
//--WaterPump------------------------
#define PUMP 16
//--SensorPin------------------------
#define TEMP 16
#define MOISTURE 36
//--StateModes-----------------------
#define TEMP_MODE 61
#define MOISTURE_MODE 62
#define SHABAT_MODE 63
#define MANUAL_MODE 64
//--Config---------------------------
#define ADMIN "http://10.9.2.118"
#define PORT 3214
#define SSID "Kinneret College"
#define PASSWORD ""
//--Global-Variables-----------------
DHT dht(TEMP, DHTTYPE);
WiFiClient client;
JsonDocument json;
int state = MANUAL_MODE;
unsigned long prevStateCheckTimeStamp;
int stateDelayMinutes = 1000 * 60 * 1;
//-----------------------------------