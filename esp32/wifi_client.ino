//-----------------------------------
#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h>
//-----------------------------------
const char *ssid = "Kinneret College";
const char *password = "";
//-----------------------------------
WiFiClient client;
//-----------------------------------
void WiFi_SETUP()
{
    WiFi.begin(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Wifi conected");
}

void SEND_DATA(float temp, int light, int moisture)
{
    HTTPClient http;
    String dataURL = "temp=" + String(temp);
    dataURL += "&light=" + String(light);
    dataURL += "&moisture=" + String(moisture);
    http.begin(client, String(ADMIN) + ":" + String(PORT) + "/esp?" + dataURL);
    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK)
    {
        Serial.print("HTTP respond ");
    }
    http.end();
}