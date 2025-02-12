//-----------------------------------
void WaterPumpSetup() {
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
}
//-----------------------------------
void HandleWaterPump() {
  switch (pumpState) {

    case OFF:
      digitalWrite(OFF, LOW);
      break;

    case LEFT:
      digitalWrite(LEFT, HIGH);
      break;

    case RIGHT:
      digitalWrite(RIGHT, HIGH);
      break;
  }
}
//-----------------------------------
void ToggleIrrigation() {
  if (pumpState == OFF)
    pumpState = LEFT;
  else
    pumpState = OFF;
}
//-----------------------------------