// Costume LED code modified from AdaFruit simple strand test for Dot Star RGB LED strip.  Code will turn blue LEDs on from beginning to end when button is pressed.  One off LED will cycle from beginning to end when button is held to present "flowing" 
//Requires Adafruit Dotstar library
#include <Adafruit_DotStar.h>
#include <SPI.h>       

//Number of LEDs in strip
#define NUMPIXELS 60

//Defining input/output pins
#define DATAPIN    4
#define CLOCKPIN   5
#define BUTTON     8
#define OFF        9

//Declaring strip
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);


void setup() {

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
  val=digitalRead(BUTTON);

  if(val==LOW)
  {
    //strip.setBrightness(155);
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
    //strip.setBrightness(0);
    
    for(i=59;i>=0;i--)
    {
      strip.setPixelColor(i, 0);
      delay(10);
      strip.show();  //Turns off pixels from end to beginning
    }
  }

}
