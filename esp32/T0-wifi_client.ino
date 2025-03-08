//-----------------------------------
void WifiSetup() {
  WiFi.begin(SSID);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Wifi conected");
}
//-----------------------------------
void SendData(float temp, int moisture) {
  HTTPClient http;
  String dataURL = "temp=" + String(temp);
  dataURL += "&moisture=" + String(moisture);
  http.begin(client, String(ADMIN) + ":" + String(PORT) + "/esp?" + dataURL);
  http.end();
}
int GetState() {
  HTTPClient http;
  int ret = -1;
  http.begin(client, String(ADMIN) + ":" + String(PORT) + "/esp/state");
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    String res = http.getString();
    ret = res.toInt();
  }
  http.end();
  return ret;
}
String GetTimeOfDay() {
  HTTPClient http;
  String ret = "";
  http.begin(client, String(ADMIN) + ":" + String(PORT) + "/esp/currentTime");
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    ret = http.getString();
  }
  http.end();
  return ret;
}
String GetData(String state) {
  HTTPClient http;
  String ret = "";
  String currentState = "state=" + state;
  http.begin(client, String(ADMIN) + ":" + String(PORT) + "/esp/dataMode?" + currentState);
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    ret = http.getString();
  }
  http.end();
  return ret;
}
//-----------------------------------
