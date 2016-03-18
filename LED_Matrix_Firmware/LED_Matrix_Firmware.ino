//----------------------HOWTO----------------------------------------
/*  
    matrix.displaybuffer[i] : directly access display buffer. check if node has been hit.
    matrix.drawPixel() : draw to a pixel.
    matrix.drawBitmap(0, 0,  mybitmap, 8, 16, LED_ON); outputs "mybmp" to buffer
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

int dart_count[2];
int player[2]; //potential multiplayer support.


 static const uint8_t PROGMEM
      All_ON[] =
      { B11111111,
        B11111111,
        B11111111,
        B11111111,
        B11111111,
        B11111111,
        B11111111,
        B11111111 };
  


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  matrix.begin(0x70); //go to first matrix
  dart_count=0; 
  player[0]=0;
  player[1]=0;

}

void loop() {

    //Detect data coming in from Kinect. This could be enclosed in a "ready" conditional.
  if(Serial.available()){
    int seg= Serial.read();  //retreive location of incoming dart. set 0 for miss

    if(seg<130 && dart_count<3){
      PaintSegment(seg);
      dart_count++;
    }else{
      //turns are over reset the game board. 
      
    }

  }
   

}

//----------------------------------FunctionListing---------------------------------------



//Function to map segment to LED.

void PaintSegment(int seg){

  if(CheckSegment(seg)){
    //paint segment

  }
  else{
    //reflash segment

  }
}

//Function to check if segment has already been hit. 
bool CheckSegment(int seg){
  
  if(matrix.displaybuffer[seg]){
    return true;
  }

  return false;
}

//Subroutine to indicate to the user that they can throw dart. i.e Light up all LED 2 times. etc.
void ShowReady(){

}

//Function to animate clearing of screen. 
void Clear(){
  
  matrix.clear();      // clear display
  matrix.drawPixel(0, 0, LED_ON);  
  matrix.writeDisplay();  // write the changes we just made to the display

}




