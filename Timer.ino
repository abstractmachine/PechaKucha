
void setupTimer() {
  
  index = count;
  time = millis();
  
  durationMillis = duration*1000;
  
}

void nextTimer() {

  time = millis();
  index--; 

  if (index > 0) {
    nextPage();
  } 
  else {
    closeFile(); 
  }

}

void stopTimer() {
  
  digitalWrite(13,LOW);
  index = 0;
  
}

