#include "AFMotor.h"
#include <Servo.h>

AF_Stepper Stepper1(20,2); // #2  M3,M4 

Servo myServo1;
Servo myServo2;
//int handPos;

int currentValue = 0;
int values[] = {0,0};
int angle1 = 0,angle2 = 0;
void setup() {
  myServo1.attach(9);
  myServo2.attach(10);
  Stepper1.setSpeed(960);
  Serial.begin(9600);
  myServo1.write(0);
  myServo2.write(0);
}
void loop() {
  

  if (Serial.available()) {

    int incomingValue = Serial.read();
    values[currentValue] = incomingValue;

    currentValue++;
    if(currentValue > 1){
      currentValue = 0;
    }

    myServo1.write(values[0]);
    myServo2.write(values[1]);
    
    
   /*angle1 = Serial.read();
    Serial.println(angle1);
    myServo1.write(angle1);
    angle2 = Serial.read();
    Serial.println(angle2);
    myServo2.write(angle2);*/

  }


}
