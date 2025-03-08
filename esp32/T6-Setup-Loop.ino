//--setup----------------------------
void setup() {
  Serial.begin(115200);
  WifiSetup();
  WaterPumpSetup();
  TempSetup();
  StateSetup();
}
//--loop-----------------------------
void loop() {
  if (millis() - prevStateCheckTimeStamp >= stateDelayMinutes) {
    prevStateCheckTimeStamp = millis();
    state = GetState();
    timeOfDay = GetTimeOfDay();
  }
  HandleState();
}
//-----------------------------------