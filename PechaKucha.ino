/* Pecha Kucha Automator
 * Press the START button to begin the countdown
 *
 * The automator will open a file, place it into fullscreen, flip pages and then quit the slideshow when done
 *
 * Sending the following SERIAL MONITOR commands (followed by "Newline") will reprogram the countdown values:
 *
 * count=20       // defines the number of slides per speaker (max=255)
 * duration=20    // defines the length in second between each slide (max=255)
 *
 * Created for Atelier Temps-réel, Ecole superieure d'art d'Aix en Provence, 14 November 2013
 * http://ecole-art-aix.fr
 * (cc) 2013 BY-SA-NC 3.0 Douglas Edric Stanley
 */
 
#define USING_LEONARDO true

#include <EEPROM.h>

int loadSaveKey = 1;            // change this key to a new value to reset preferences
unsigned int count = 10;        // The number of slides
unsigned int duration = 20;     // The time delay between each slide in seconds
unsigned int durationMillis = duration*1000; // duration represented in millseconds
unsigned int timeMillis = 0;
int index = count;              // The current slide index
long time = 0;                  // The time stamp in millis() of the last slide
String input = "";              // An input string used for defining preferences

void setup() {
  
  loadMemory();
  setupSerial();
  setupCommands();
  startSlideshow();
  setupTimer();
  
}

void loop() {
  
  // get the time in milliseconds
  timeMillis = millis()-time;
  // if any slides are remaining
  if (index > 0) {
    blinky(); // blink the time remaining 
    if (timeMillis > durationMillis) nextTimer(); // next slide
  }          
  
}
