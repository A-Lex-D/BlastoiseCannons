//Code to control two servos to open and close wings
//Include standard servo library
#include <Servo.h>

//Defining button input pins
#define BUTTON 7

//Creating servo objects
Servo left;
Servo right;

int rightPos = 179;
int leftPos = 0;
int i;

void setup() {

  //Setting servo data pins
  left.attach(9);
  right.attach(8);

  //Setting button as input
  pinMode(BUTTON, INPUT);

  //Begin servos at center
  left.write(leftPos);
  right.write(rightPos);
  
}

//Variables for reading input values
int inVal;

void loop() {
  //Set button value
  inVal=digitalRead(BUTTON);

  //Check if button is pressed
  if (inVal==LOW)
  {
    if (leftPos==0 && rightPos==179)
    {
      for(i=0; i<=135; i++)
      {
        left.write(i);
        right.write(179-i);
        delay(10);
      }

      leftPos=135;
      rightPos=45;
    }
    else if (leftPos==135 && rightPos==45)
    {
      for(i=135; i>=0; i--)
      {
        left.write(i);
        right.write(179-i);
        delay(10);
      }
      leftPos=0;
      rightPos=179;
    }
 }
}
  

  
  
