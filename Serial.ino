void setupSerial() {
  
  // turn on serial communication
  Serial.begin(9600);
  // reserve 32 bytes for the inputString:
  input.reserve(32);
  
}

// treat Serial port input for reconfiguring preferences
void serialEvent() {
  
  // keep looping while serial input data is in buffer
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n' || input.length() >= 32) {
      parseInput();
    } else {
      // add it to the inputString:
      input += inChar;
    }
  }
  
}

void parseInput() {
  
  String commandString = getValueString(input, '=', 0);
  String valueString = getValueString(input, '=', 1);
  int value = stringToInt(valueString);
  
  input = "";
  
  value = max(0,min(255,value));
  
  if (commandString == "count") count = value;
  else if (commandString == "duration") duration = value;
  else return; // if not a valid preference key, forget it
  
  saveMemory();
  stopTimer(); // stop countdown
  
}


// convert Arduino String to int
int stringToInt(String string){
  
  char char_string[string.length()+1];
  string.toCharArray(char_string, string.length()+1);
  
  return atoi(char_string);
  
}

 // found at http://stackoverflow.com/questions/9072320/split-string-into-string-array
String getValueString(String data, char separator, int index) {
  
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
  
}
