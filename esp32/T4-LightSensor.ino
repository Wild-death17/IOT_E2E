//-----------------------------------
int HandleLight() {
  return map(analogRead(LIGHT), 0, 4095, 0, 100);
}
//-----------------------------------