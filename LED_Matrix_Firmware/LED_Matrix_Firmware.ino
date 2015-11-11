#include <Adafruit_GFX.h>
#include <Wire.h>
#include <Adafruit_LEDBackpack.h>

#ifndef _BV
  #define _BV(bit) (1<<(bit))
#endif

Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();

uint8_t counter = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  matrix.begin(0x70); 

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // write the changes we just made to the display
  matrix.writeDisplay();
  



}
