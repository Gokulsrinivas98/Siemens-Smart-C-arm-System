import de.voidplus.leapmotion.*;

import processing.serial.*;

LeapMotion leap;
Serial port;


int angle1 =0 ,angle2 = 0, xpos= 0 ,ypos = 0;

void setup() {
  size(800, 500);
  background(0);
  fill(130);
  // ...

  leap = new LeapMotion(this);
  
  //println("Available serial ports:");
  //println(Serial.list());
  port = new Serial(this,"COM6", 9600);
  
}

void leapOnInit() {
  // println("Leap Motion Init");
}
void leapOnConnect() {
  // println("Leap Motion Connect");
}
void leapOnFrame() {
  // println("Leap Motion Frame");
}
void leapOnDisconnect() {
  // println("Leap Motion Disconnect");
}
void leapOnExit() {
  // println("Leap Motion Exit");
}

void draw() {
  background(255);
  // ...



  int fps = leap.getFrameRate();
  for (Hand hand : leap.getHands ()) {


    // ==================================================
    // 2. Hand

    int     handId             = hand.getId();
    PVector handPosition       = hand.getPosition();
    PVector handStabilized     = hand.getStabilizedPosition();
    PVector handDirection      = hand.getDirection();
    PVector handDynamics       = hand.getDynamics();
    float   handRoll           = hand.getRoll();
    float   handPitch          = hand.getPitch();
    float   handYaw            = hand.getYaw();
    boolean handIsLeft         = hand.isLeft();
    boolean handIsRight        = hand.isRight();
    float   handGrab           = hand.getGrabStrength();
    float   handPinch          = hand.getPinchStrength();
    float   handTime           = hand.getTimeVisible();
    PVector spherePosition     = hand.getSpherePosition();
    float   sphereRadius       = hand.getSphereRadius();

    // --------------------------------------------------
   // println("x position");
   // println(handPosition.x);
    //println("y position  ");
    //println(handPosition.y);
   // println("Roll");
    //println( handRoll);
    //println("Yaw");
    //println( handYaw);
     
     
    if ((handRoll > 0) && (handYaw < 0))
    {
      
      
      float angles = handYaw*2;
      float angless = handRoll*2;
      angle1 = int(angles)*(-1);
      angle2 = int(angless);
      
      if (handPosition.x > 0 && handPosition.x < 226) {
        xpos = 1;
     } 
      else if (handPosition.x < 452 && handPosition.x >226) {
       xpos = 0;
       } 
   
   else if (handPosition.x < 680 && handPosition.x >452){
     xpos = 2;
    }
      
      if (handPosition.y > 50 && handPosition.y < 240) {
        ypos = 1;
     } 
      else if (handPosition.y < 350 && handPosition.y >240) {
       ypos = 0;
       } 
   
   else if (handPosition.y < 440 && handPosition.y >350){
     ypos = 2;
    }
      
        byte out[] = new byte[4];

      out[0] = byte(angle1);
      out[1] = byte(angle2);
      out[2] = byte(xpos);
      out[3] = byte(ypos);
      
      println(out);
      
      port.write(out);
      
      //port.write(angle1);
      //port.write(angle2);
     //println(angle1);
     //println(angle2);
    }
    
    hand.draw();

  }
  
}
