//-----------------------------------
void TempSetup(){
  	dht.begin(); 
}
void HandleTemp(){
  float Humidity = dht.readHumidity();
  float Temp = dht.readTemperature(); 

  Serial.print("Temp Sensor: ");
  Serial.print("Humidity: ");
  Serial.print(Humidity);
  Serial.print("Temp: ");
  Serial.println(Temp);
}
//-----------------------------------
