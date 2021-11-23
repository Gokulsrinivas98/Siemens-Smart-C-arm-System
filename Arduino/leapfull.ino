#include "AFMotor.h"
#include <Servo.h>

AF_Stepper Stepper1(2000,2); // #2  M3,M4 
AF_Stepper Stepper2(2000,1);

Servo myServo1;
Servo myServo2;
//int handPos;

int currentValue = 0;
int values[] = {0,0,0,0};
int angle1 = 0,angle2 = 0;
void setup() {
  myServo1.attach(9);
  myServo2.attach(10);
  Stepper1.setSpeed(900);
  Stepper2.setSpeed(900);
  Serial.begin(9600);
  myServo1.write(0);
  myServo2.write(0);
}
void loop() {
  

  if (Serial.available()) {

    int incomingValue = Serial.read();
    values[currentValue] = incomingValue;

    currentValue++;
    if(currentValue > 3){
      currentValue = 0;
    }

    myServo1.write(values[0]);
    myServo2.write(values[1]);

    if (values[2] == 1)
    {
          Stepper1.onestep(FORWARD,MICROSTEP);

    }
    else if(values[2] == 2)
    {

      Stepper1.onestep(BACKWARD,MICROSTEP);
    }
    else if(values[2] == 0)
    {

      Stepper1.release(); 
    }


    if (values[3] == 1)
    {
         //Stepper2.step(10, FORWARD, DOUBLE);
          Stepper2.onestep(FORWARD,MICROSTEP);

    }
    else if(values[3] == 2)
    {//Stepper2.step(10, FORWARD, DOUBLE);

      Stepper2.onestep(BACKWARD,MICROSTEP);
    }
    else if(values[3] == 0)
    {

      Stepper2.release(); 
    }

    
    
    
   /*angle1 = Serial.read();
    Serial.println(angle1);
    myServo1.write(angle1);
    angle2 = Serial.read();
    Serial.println(angle2);
    myServo2.write(angle2);*/

  }


}
