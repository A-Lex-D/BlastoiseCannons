//Code to control two servos in a pan-tilt setup with left, right, up, and down buttons.
//Include standard servo library
#include <Servo.h>

//Defining button input pins
//#define UP  7
//#define DOWN  6
//#define LEFT  5
//#define RIGHT 4

//Creating servo objects
Servo tilt;
Servo pan;

//Joystick pins
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

int panPos = 90;
int tiltPos = 90;

void setup() {

  //Setting servo data pins
  pan.attach(9);
  tilt.attach(8);

  //Setting buttons as inputs
  //pinMode(UP, INPUT);
  //pinMode(DOWN, INPUT);
  //pinMode(LEFT, INPUT);
  //pinMode(RIGHT, INPUT);

  //Begin servos at center
  pan.write(90);
  tilt.write(90);
  
}

//Variables for reading input values
//int upVal;
//int downVal;
//int leftVal;
//int rightVal;

void loop() {
  //Set direction values
  //upVal=digitalRead(UP);
  //downVal=digitalRead(DOWN);
  //leftVal=digitalRead(LEFT);
  //rightVal=digitalRead(RIGHT);

  //Check if up button is pressed
  if (/*upVal==LOW*/analogRead(Y_pin)<250 && tiltPos < 180)
  {
    tiltPos++;
    tilt.write(tiltPos);
    delay(5);
  }
  
  //or if down button is pressed
  else if (/*downVal==LOW*/analogRead(Y_pin)>450 && tiltPos > 0)
  {
    tiltPos--;
    tilt.write(tiltPos);
    delay(5);
  }

  //Check if right button is pressed
  if (/*rightVal==LOW*/analogRead(X_pin)<250 && panPos < 180)
  {
    panPos++;
    pan.write(panPos);
    delay(5);
  }
  
  //or if left button is pressed
  else if (/*leftVal==LOW*/analogRead(X_pin)>450 && panPos > 0)
  {
    panPos--;
    pan.write(panPos);
    delay(10);
  }

  
  

}
