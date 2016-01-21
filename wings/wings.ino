//Code to control two servos to open and close wings
//Include standard servo library
#include <Servo.h>

//Defining button input pins
#define BUTTON 7

//Creating servo objects
Servo left;
Servo right;

int leftPos = 180;
int rightPos = 0;

void openWings() {
  while (leftPos != 45 && rightPos != 135)
  {
    leftPos-1;
    rightPos+1;
    left.write(leftPos);
    right.write(rightPos);
    delay(5);
  }
}
void closeWings() {
  while (leftPos != 180 && rightPos != 0)
  {
    leftPos+1;
    rightPos-1;
    left.write(leftPos);
    right.write(rightPos);
    delay(5);
  }
}

void setup() {

  //Setting servo data pins
  left.attach(9);
  right.attach(8);

  //Setting button as input
  pinMode(BUTTON, INPUT);

  //Begin servos at center
  left.write(180);
  right.write(0);
  
}

//Variables for reading input values
int inVal;

void loop() {
  //Set button value
  inVal=digitalRead(BUTTON);

  //Check if up button is pressed
  if (inVal==LOW)
  {
    if (leftPos==180 && rightPos==0)
    {
      openWings();
    }
    else if (leftPos==45 && rightPos==135)
    {
      closeWings();
    }
   }
  }
  

  
  
