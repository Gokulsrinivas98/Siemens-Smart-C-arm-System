# Siemens-Smart-C-arm-System

- the processing code has the leap motion hand coordinates
 - through its java library  processing ide  has the both hands gestures registered and then it uses few built it algorithm to calculate the yaw pitch and roll of hand / palm / fore arm
- from the calculated gestures it gives out the featured actions and the motor actions which basically controls the motor actions
- and these commands are transferred in a byte array
 - after getting the direction mapping from the gestures to the motor controller
- special arduino adafruit libreries are used to connect four motors
 - two motor servo tower prp
 - two cd drive stepper motor
 
 - and therefore these motors act as base for the c arm model which is 3d printed in nature
 and mimic the motions C arm device



 - Thank you
 
 
 

