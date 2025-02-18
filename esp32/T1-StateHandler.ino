//-----------------------------------
void StateSetup() {
  prevStateCheckTimeStamp = millis();
}
//-----------------------------------
void HandleState() {
  String json;
  JsonDocument doc;

  switch (state) {
    case TEMP_MODE:
      {
        json = GetData("tempMode");
        deserializeJson(doc, json);
        float temp = doc["temp"];
        int minTime = doc["minTime"];
        int maxTime = doc["maxTime"];
        break;
      }

    case MOISTURE_MODE:
      {
        json = GetData("moistureMode");
        deserializeJson(doc, json);
        int moisture = doc["moisture"];
        break;
      }

    case SHABAT_MODE:
      {
        json = GetData("shabbatMode");
        deserializeJson(doc, json);
        break;
      }

    case MANUAL_MODE:
      {
        json = GetData("manualMode");
        deserializeJson(doc, json);
        break;
      }
  }
}
//-----------------------------------
