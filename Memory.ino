
void loadMemory() {
  
  // make sure we've written a preference file
  if (EEPROM.read(0) != loadSaveKey) return;
  
  count = EEPROM.read(1);
  duration = EEPROM.read(2);
  
}

void saveMemory() {
  
  // tells program that we've set a preference file
  EEPROM.write(0,loadSaveKey);
  // set count & duration values
  EEPROM.write(1,count);
  EEPROM.write(2,duration);
  
  Serial.print("count=");
  Serial.println(count);
  Serial.print("duration=");
  Serial.println(duration);
  
}
