//----------------------HOWTO----------------------------------------
/*  
    matrix.displaybuffer[i] : directly access display buffer. 
    matrix.drawBitmap(0, 0,  mybitmap, 16, 32, LED_ON); outputs "mybmp" to buffer
    matrix.drawLine(0,0, 7,15, Mat1); 

  //INITIALLIZING BUFFER
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
  
  
   write the changes we just made to the display. display buffer to LED. 
   matrix.writeDisplay();
  */

//-----------------------ENDHOWTO---------------------------------------


#include <Adafruit_GFX.h>
#include <Wire.h>
#include <Adafruit_LEDBackpack.h>


Adafruit_8x16matrix matrix = Adafruit_8x16matrix();  //specify your display buffer

uint8_t counter = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  matrix.begin(0x70); 

}

void loop() {
  // put your main code here, to run repeatedly:

}
