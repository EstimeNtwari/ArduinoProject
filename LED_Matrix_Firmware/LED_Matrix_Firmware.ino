//----------------------HOWTO----------------------------------------
/*  
    matrix.displaybuffer[i] : directly access display buffer. check if node has been hit.
    matrix.drawPixel() : draw to a pixel.
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

int dart_counter;
int player; //potential multiplayer support.

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  matrix.begin(0x70); //go to first matrix
  dart_count=0; 

}

void loop() {

  if(dart_count<=2){ //

    //Detect data coming in from Kinect. This could be enclosed in a "ready" conditional.
    if(Serial.available()){
      int sengment= Serial.read();  //retreive location of incoming dart. set 0 for miss
    }
    switch (segment){

      //case i
      //matrix.drawPixel(i,j, LED_ON); //write to segment i
      //enumerate segments. and write to buffer.

    }

    //write buffer to Dartboard LEDs. 
    matrix.writeDisplay();
    }else{
      //clear Dartboard
      matrix.clear();
      
    }
    

}

//Custom Function Listing.

//Function to map segment to LED.

void PaintSegment(int seg){

}

//Function to check if segment has already been hit. 
bool CheckSegment(int seg){

}

//Subroutine to indicate to the user that they can throw dart. i.e Light up all LED 2 times. etc.
void ShowReady(){

}

//Function to animate clearing of screen. 
void AnimateClear(){

}


