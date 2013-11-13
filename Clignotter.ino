
void blinky() {
 
  // etat allume ou eteint
  boolean state = false;

  int reversed = (durationMillis-timeMillis) / 10;

  // alterner entre la valeur int 0 / 1 en fonction du multiplicateur et les secondes
  state = (int)(durationMillis / reversed) % 2;
  
  // control LED
  digitalWrite(13, !state);

}
