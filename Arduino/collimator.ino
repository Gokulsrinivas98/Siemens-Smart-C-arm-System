//2-Way motor control




int motorPin1 =  5;    // One motor wire connected to digital pin 5
int motorPin2 =  6;    // One motor wire connected to digital pin 6

int currentValue = 0;
int values[] = {0,0};

// The setup() method runs once, when the sketch starts

void setup()   {                
  // initialize the digital pins as an output:

  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT); 
  pinMode(motorPin2, OUTPUT);  
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()                     
{

 if (Serial.available()) {


int incomingValue = Serial.read();
    values[currentValue] = incomingValue;

    currentValue++;
    if(currentValue >= 1){
      currentValue = 0;
    }

    


  if (values[0] == 1)
  {
    rotateRightFull( 10);
  }

  else if(values[0] == 2)
  {
    rotateLeftFull(10);
  }
 /* rotateLeft(150, 1000);
  rotateRight(50, 1000);
  rotateRight(150, 1000);
  rotateRight(200, 1000);
  rotateLeft(255, 1000);
  rotateRight(10, 1500);*/

 }
}

void rotateLeft(int speedOfRotate, int length){
  analogWrite(motorPin1, speedOfRotate); //rotates motor
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  delay(length); //waits
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
}

void rotateRight(int speedOfRotate, int length){
  analogWrite(motorPin2, speedOfRotate); //rotates motor
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  delay(length); //waits
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
}

void rotateLeftFull(int length){
  digitalWrite(motorPin1, HIGH); //rotates motor
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  delay(length); //waits
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
}

void rotateRightFull(int length){
  digitalWrite(motorPin2, HIGH); //rotates motor
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  delay(length); //waits
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
}
