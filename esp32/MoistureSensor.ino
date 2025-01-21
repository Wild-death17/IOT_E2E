//-----------------------------------
int HandleMoisture()
{
  int MoistureSensor = analogRead(Moisture);
  Serial.print("Moisture Sensor: ");
  Serial.println(MoistureSensor);
  return MoistureSensor;
}
//-----------------------------------
