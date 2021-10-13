/**********************************************************************
  Filename    : Joystick
  Description : Read data from joystick.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
int xyzPins[] = {28, 27, 26};   //x,y,z pins
void setup() {
  Serial.begin(115200);
  pinMode(xyzPins[2], INPUT_PULLUP);   //z axis is a button.
}

void loop() {
  int xVal = analogRead(xyzPins[0]);
  int yVal = analogRead(xyzPins[1]);
  int zVal = digitalRead(xyzPins[2]);
  Serial.println("X,Y,Z: " + String(xVal) + ", " +  String(yVal) + ", " + String(zVal));
  delay(500);
}
