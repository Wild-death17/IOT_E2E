//-----------------------------------
void WaterPumpSetup() {
  pinMode(PUMP, OUTPUT);
}
//-----------------------------------
void ToggleWaterPump() {
  digitalWrite(PUMP, !digitalRead(PUMP));
}
//-----------------------------------