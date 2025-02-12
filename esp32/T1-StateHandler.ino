//-----------------------------------

void StateSetup() {
  prevStateCheckTimeStamp = millis();
}
//-----------------------------------
void HandleState() {
  switch (state) {

    case TEMP_MODE:
      GET_DATA("tempMode");

      break;

    case MOISTURE_MODE:
      GET_DATA("moistureMode");

      break;
    case SHABAT_MODE:
      GET_DATA("shabbatMode");

      break;
    case MANUAL_MODE:
      GET_DATA("manualMode");

      break;
  }
}
//-----------------------------------
