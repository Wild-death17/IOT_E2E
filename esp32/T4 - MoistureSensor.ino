//-----------------------------------
int HandleMoisture() {
  int MoistureSensor = analogRead(MOISTURE);
  Serial.print("Moisture Sensor: ");
  Serial.println(MoistureSensor);
  return MoistureSensor;
}
//-----------------------------------
