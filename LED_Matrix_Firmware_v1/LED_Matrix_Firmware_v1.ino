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

struct player{ //player struct to be used for each player (multiplayer support)
  int playerid;
  int score;
  int seg_hit[3]; //array to keep track of what segments have been light during a players turn
};
typedef struct player Player;



void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.setModule(0);// set up output pins to be SCL(0) and SDA (0)
  
  Serial.begin(9600);
  matrix.begin(0x70); //go to first matrix
  matrix.setRotation(1); 
  matrix.setBrightness(1);

}

void loop() {
  
  matrix.clear();
    //Detect data coming in from Kinect. This could be enclosed in a "ready" conditional.
    if(Serial.available()){
      int kinect_data=Serial.read();// retrieve data coming from kinect to determine what to do
      if(kinect_data==300){//single player game
      Player player1; //intializing player 1 and thier starting stats
      player1.playerid=kinect_data;
      player1.score=0;
      for(int i=0; i<=2; i++){
        player1.seg_hit[i]=-1;
      }
      if(Serial.available()){
        int kinect_data=Serial.read();
        if(kinect_data==200){ //200 representing a new players turn (total of 3 throws)
      for(int i=0; i<=2; i++){
        if(Serial.available()){
          int kinect_data=Serial.read();
          int segment=kinect_data;
          PaintSegment(segment);
          player1.seg_hit[i]=segment;
          player1.score+=segment; 
        }
        }
      }
      }
      }

        
    }

    

}

//Custom Function Listing.

//Function to map segment to LED.
void PaintSegment(int seg){
  if(seg==82){
    LEDFlash(3,5);
  }
  else if(seg==81){
    LEDFlash(0,9);
  }
  else if(seg==80){
    LEDFlash(0,11);
  }
  else if(seg==79){
    LEDFlash(0,15);
  }
  else if(seg==78){
    LEDFlash(7,15);
  }
  else if(seg==77){
    LEDFlash(4,15);
  }
  else if(seg==76){
    LEDFlash(3,15);
  }
  else if(seg==75){
    LEDFlash(0,10);
  }
  else if(seg==74){
    LEDFlash(7,11);
  }
  else if(seg==73){
    LEDFlash(0,5);
  }
  else if(seg==72){
    LEDFlash(0,4);
  }
   else if(seg==71){
    LEDFlash(3,0);
  }
   else if(seg==70){
    LEDFlash(4,0);
  }
   else if(seg==69){
    LEDFlash(7,0);
  }
  else if(seg==68){
    LEDFlash(0,0);
  }
  else if(seg==67){
    LEDFlash(7,6);
  }
  else if(seg==66){
    LEDFlash(7,10);
  }
  else if(seg==65){
    LEDFlash(7,9);
  }
  else if(seg==64){
    LEDFlash(7,4);
  }
  else if(seg==63){
    LEDFlash(0,6);
  }
  else if(seg==62){
    LEDFlash(6,5);
    LEDFlash(6,4);
  }
  else if(seg==61){
    LEDFlash(7,8);
    LEDFlash(7,7);
  }
  else if(seg==60){
    LEDFlash(3,12);
    LEDFlash(7,13);
  }
  else if(seg==59){
    LEDFlash(6,14);
    LEDFlash(7,14);
  }
  else if(seg==58){
    LEDFlash(6,15);
    LEDFlash(5,15);
  }
  else if(seg==57){
    LEDFlash(1,15);
    LEDFlash(2,15);
  }
  else if(seg==56){
    LEDFlash(1,14);
    LEDFlash(0,14);
  }
  else if(seg==55){
    LEDFlash(0,12);
    LEDFlash(0,12);
  }
  else if(seg==54){
    LEDFlash(1,11);
    LEDFlash(1,10);
  }
  else if(seg==53){
    LEDFlash(0,8);
    LEDFlash(0,7);
  }
  else if(seg==52){
    LEDFlash(0,3);
    LEDFlash(0,2);
  }
  else if(seg==51){
    LEDFlash(1,1);
    LEDFlash(0,1);
  }
  else if(seg==50){
    LEDFlash(2,0);
    LEDFlash(1,0);
  }
  else if(seg==49){
    LEDFlash(6,0);
    LEDFlash(5,0);
  }
  else if(seg==48){
    LEDFlash(1,5);
    LEDFlash(1,4);
  }
  else if(seg==47){
    LEDFlash(1,9);
    LEDFlash(1,6);
  }
  else if(seg==46){
    LEDFlash(6,11);
    LEDFlash(6,10);
  }
  else if(seg==45){
    LEDFlash(6,6);
    LEDFlash(6,9);
  }
  else if(seg==44){
    LEDFlash(7,1);
    LEDFlash(6,1);
  }
  else if(seg==43){
    LEDFlash(7,3);
    LEDFlash(7,2);
  }
  else if(seg==42){
    LEDFlash(6,8);
  }
  else if(seg==41){
    LEDFlash(4,14);
  }
  else if(seg==40){
    LEDFlash(3,14);
  }
  else if(seg==39){
    LEDFlash(2,14);
  }
  else if(seg==38){
    LEDFlash(1,13);
  }
  else if(seg==37){
    LEDFlash(1,12);
  }
  else if(seg==36){
    LEDFlash(5,14);
  }
  else if(seg==35){
    LEDFlash(2,1);
  }
  else if(seg==34){
    LEDFlash(3,1);
  }
  else if(seg==33){
    LEDFlash(4,1);
  }
  else if(seg==32){
    LEDFlash(5,1);
  }
  else if(seg==31){
    LEDFlash(6,2);
  }
  else if(seg==30){
    LEDFlash(1,2);
  }
  else if(seg==29){
    LEDFlash(6,3);
  }
  else if(seg==28){
    LEDFlash(1,3);
  }
  else if(seg==27){
    LEDFlash(6,12);
  }
  else if(seg==26){
    LEDFlash(6,13);
  }
  else if(seg==25){
    LEDFlash(1,8);
  }
  else if(seg==24){
    LEDFlash(1,7);
  }
  else if(seg==23){
    LEDFlash(6,7);
  }
  else if(seg==22){
    LEDFlash(5,10);
    LEDFlash(4,10);
  }
  else if(seg==21){
    LEDFlash(5,11);
    LEDFlash(4,11);
  }
  else if(seg==20){
    LEDFlash(5,12);
    LEDFlash(4,12);
  }
  else if(seg==19){
    LEDFlash(5,13);
    LEDFlash(4,13);
  }
  else if(seg==18){
    LEDFlash(2,13);
    LEDFlash(3,13);
  }
  else if(seg==17){
    LEDFlash(2,12);
    LEDFlash(3,12);
  }
  else if(seg==16){
    LEDFlash(2,11);
    LEDFlash(3,11);
  }
  else if(seg==15){
    LEDFlash(2,10);
    LEDFlash(3,10);
  }
  else if(seg==14){
    LEDFlash(2,9);
    LEDFlash(2,8);
  }
  else if(seg==13){
    LEDFlash(3,3);
    LEDFlash(2,3);
  }
  else if(seg==12){
    LEDFlash(3,2);
    LEDFlash(2,2);
  }
  else if(seg==11){
    LEDFlash(5,2);
    LEDFlash(4,2);
  }
  else if(seg==10){
    LEDFlash(2,6);
    LEDFlash(2,7);
  }
  else if(seg==9){
    LEDFlash(5,3);
    LEDFlash(4,3);
  }
  else if(seg==8){
    LEDFlash(3,4);
    LEDFlash(2,4);
  }
  else if(seg==7){
    LEDFlash(5,4);
    LEDFlash(4,4);
  }
  else if(seg==6){
    LEDFlash(2,5);
    LEDFlash(3,5);
  }
  else if(seg==5){
    LEDFlash(4,5);
    LEDFlash(5,5);
  }
  else if(seg==4){
    LEDFlash(5,7);
    LEDFlash(5,6);
  }
  else if(seg==3){
    LEDFlash(5,9);
    LEDFlash(5,8);
  }
  else if(seg==2){
    LEDFlash(3,9);
    LEDFlash(4,9);
    LEDFlash(4,6);
    LEDFlash(3,6);
  }
  else if(seg==1){ //equivalent to segment 0
    LEDFlash(4,8);
  }
  
}

//Function to check if segment has already been hit. 
void LEDFlash(int r, int c)

    matrix.clear();
    //Detect data coming in from Kinect. This could be enclosed in a "ready" conditional.

    matrix.drawPixel(r,c, LED_ON);
    matrix.writeDisplay();
    delay(400);
  
    matrix.drawPixel(r,c, LED_OFF);
    matrix.writeDisplay();
    delay(400);
   
    matrix.drawPixel(r,c, LED_ON);
    matrix.writeDisplay();
    delay(400);

    matrix.drawPixel(r,c, LED_OFF);
    matrix.writeDisplay();
    delay(400);

    matrix.drawPixel(r,c, LED_ON);
    matrix.writeDisplay();
    
   
}

//Subroutine to indicate to the user that they can throw dart. i.e Light up all LED 2 times. etc.
void ShowReady(){

}

//Function to animate clearing of screen. 
void AnimateClear(){
for(int i=1; i<83; i++){
  
}


