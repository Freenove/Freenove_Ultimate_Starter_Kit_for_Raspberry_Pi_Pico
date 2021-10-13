/**********************************************************************
  Filename    : Control_Motor_by_L293D
  Description : Use PWM to control the direction and speed of the motor.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
int in1Pin = 16;      // Define L293D channel 1 pin
int in2Pin = 17;      // Define L293D channel 2 pin
int enable1Pin = 15;  // Define L293D enable 1 pin
int ADC0_PIN = 26;

boolean rotationDir;  // Define a variable to save the motor's rotation direction
int rotationSpeed;    // Define a variable to save the motor rotation speed

void setup() {
  // Initialize the pin into an output mode:
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
}

void loop() {
  int potenVal = analogRead(ADC0_PIN);      // Convert the voltage of rotary potentiometer into digital
  //Compare the number with value 512, 
  //if more than 512, clockwise rotates, otherwise, counter clockwise rotates
  rotationSpeed = potenVal - 512;
  if (potenVal > 512)
    rotationDir = true;
  else
    rotationDir = false;
  // Calculate the motor speed
  rotationSpeed = abs(potenVal - 512);
  //Control the steering and speed of the motor
  driveMotor(rotationDir, constrain(rotationSpeed, 0, 512));
}

void driveMotor(boolean dir, int spd) {
  // Control motor rotation direction
  if (dir) {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  }
  else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
  // Control motor rotation speed
  analogWrite(enable1Pin, spd);
}
