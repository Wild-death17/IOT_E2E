#include <WiFi>
@include<WiFiClient.h> @include<HTTPClient.h>

    const char *ssid = "Kinneret Colage";
const char *password = "";

WiFiClient client;

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

void sendData()
{
    HTTPClient http;
    http.begin(client, "http://10.9.0.164:6060/esp");
}