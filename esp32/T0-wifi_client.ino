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
    Serial.print("HTTP respond: ");
    String res = http.getString();
    ret = res.toInt();
  }
  http.end();
  return ret;
}
String GetTime(){
    HTTPClient http;
  String res = "";
  http.begin(client, String(ADMIN) + ":" + String(PORT) + "/esp/currentTime");
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    Serial.print("HTTP respond: ");
    String res = http.getString();
    Serial.println(res);
  }
  http.end();
  return res;
}
String GetData(String state) {
  HTTPClient http;
  String res = "";
  String currentState = "state=" + state;
  http.begin(client, String(ADMIN) + ":" + String(PORT) + "/esp/dataMode?" + currentState);
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    Serial.print("HTTP respond: ");
    String res = http.getString();
    Serial.println(res);
  }
  http.end();
  return res;
}
//-----------------------------------
