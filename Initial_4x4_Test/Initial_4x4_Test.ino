#include <Adafruit_GFX.h>
#include <Wire.h>
#include <Adafruit_LEDBackpack.h>

#ifndef _BV
  #define _BV(bit) (1<<(bit))
#endif

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

uint8_t counter = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  matrix.begin(0x70); 
  matrix.setRotation(1); 
  matrix.setBrightness(1);


}

void loop() {
  // put your main code here, to run repeatedly:

  // paint one LED per row. The HT16K33 internal memory looks like
  // a 4x4 bit matrix (4 rows, 4 columns)
  int a=0;
  int b=0;
  matrix.clear();
//  
//  for(int i=0; i<8; i++){
//    for(int j=0; j<8; j++){
//      matrix.drawPixel(j,i,1);
//      // write the changes we just made to the display
//      matrix.writeDisplay();
//      delay(100);
//      }
//  }
    //matrix.clear;

  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      matrix.drawPixel(i,j, LED_ON);
      delay(100);
      matrix.writeDisplay();
    }
  }
  
  delay(100);

}
