//-----------------------------------
void TempSetup() {
  dht.begin();
}
float HandleTemp() {
  return dht.readTemperature();
}
//-----------------------------------
