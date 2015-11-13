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

  // paint one LED per row. The HT16K33 internal memory looks like
  // a 4x4 bit matrix (4 rows, 4 columns)
  static const uint16_t PROGMEM
      mybitmap[] =
      { B0011110000111100,
        B0100001000111100,
        B1010010100111100,
        B1000000100111100,
        B1010010100111100,
        B1001100100111100,
        B0100001000111100,
        B0011110000111100 };
  
  for (uint8_t i=0; i<4; i++) {
    // draw a diagonal row of pixels
    matrix.displaybuffer[i] = _BV((counter+i) % 4) | _BV((counter+i+4) % 4) ;
  }
  
  // write the changes we just made to the display
  matrix.writeDisplay();
  delay(100);

  counter++;
  if (counter >= 4) counter = 0;  

}
