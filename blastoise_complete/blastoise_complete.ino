//Code to control two servos in a pan-tilt setup with left, right, up, and down buttons.
//Include standard servo library
#include <Servo.h>
#include <Adafruit_DotStar.h>
#include <SPI.h>       

//Number of LEDs in strip
#define NUMPIXELS 60

//Defining input/output pins
#define DATAPIN    4
#define CLOCKPIN   5
#define BUTTON     8
#define OFF        9

//Creating servo objects
Servo tilt;
Servo pan;

//Declaring LED strip
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

//Joystick pins
const int X_pin = 0;
const int Y_pin = 1;

int panPos = 90;
int tiltPos = 90;

void setup() {

  //Setting servo data pins
  pan.attach(9);
  tilt.attach(8);

  //Begin servos at center
  pan.write(90);
  tilt.write(90);

  //Setting button as input
  pinMode(BUTTON, INPUT);

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
    clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
  #endif

  //Initialize LED strip
  strip.begin();
 
  //refresh strip to current data, in this case off
  strip.show();
  
}

int head  = 0, tail = -59;      //Specifying head and tail of moving lighted strip
uint32_t color = 0x0000FF;      // Specifying color, only need blue for costume
int val;                        //Reading value of button
int i;                          //For use in a loop to turn LEDs off when button is released

void loop() {
  
  //Handling LED strip
  val=digitalRead(BUTTON);

  if(val==LOW)
  {
    strip.setPixelColor(head, color);
    strip.setPixelColor(tail, 0);
    strip.show();
    delay(10);
    ++head;
    ++tail;
  
    if(head>=NUMPIXELS)
    {
      head=0;
    }
    
    if(tail>=NUMPIXELS)
    {
      tail=0;
    }
  
  }

  else
  {
    head=0;
    tail=-59;  
    
    for(i=59;i>=0;i--)
    {
      strip.setPixelColor(i, 0);
      delay(10);
      strip.show();  //Turns off pixels from end to beginning
    }
  }

  //Handling servos
  //Check if up
  if (analogRead(Y_pin)<250 && tiltPos < 180)
  {
    tiltPos++;
    tilt.write(tiltPos);
    delay(5);
  }
  
  //or if down 
  else if (analogRead(Y_pin)>450 && tiltPos > 0)
  {
    tiltPos--;
    tilt.write(tiltPos);
    delay(5);
  }

  //Check if right 
  if (analogRead(X_pin)<250 && panPos < 180)
  {
    panPos++;
    pan.write(panPos);
    delay(5);
  }
  
  //or if left 
  else if (analogRead(X_pin)>450 && panPos > 0)
  {
    panPos--;
    pan.write(panPos);
    delay(10);
  }

}
