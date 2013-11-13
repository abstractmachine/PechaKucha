
void setupCommands() {
  
  //Keyboard.begin();
  
}

void startSlideshow() {
  
  Serial.println(index);
  
  typeOpen();
  typeFullscreen();
  
}

void nextPage() {
  
  Serial.println(index);
  
  typeNextPage();
  
}

void closeFile() {
  
  Serial.println("ESC");
  digitalWrite(13,LOW);
  
  typeESC();
  typeClose();
  
}

void typeOpen() {
  
  #ifdef USING_LEONARDO
  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('o');
  delay(50);
  Keyboard.releaseAll();
  delay(1000);
  
  #endif
  
}

void typeFullscreen() {
  
  #ifdef USING_LEONARDO
 
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('f');
  delay(50);
  Keyboard.releaseAll();
  
  #endif
  
}


void typeNextPage() {
  
  #ifdef LEONARDO
  
  Keyboard.write(KEY_DOWN_ARROW);
  
  #endif
  
}

void typeESC() {
  
  #ifdef USING_LEONARDO
  
  Keyboard.write(KEY_ESC);
  delay(1000);
  
  #endif
  
}


void typeClose() {
  
  #ifdef USING_LEONARDO
  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('w');
  delay(50);
  Keyboard.releaseAll();
  
  #endif
  
}

