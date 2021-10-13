/**********************************************************************
  Filename    : ColorfulLight
  Description : Use RGBLED to show random color.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
int ledPins[] = {13, 12, 11};    //define red, green, blue led pins
int red, green, blue;
void setup() {
  for (int i = 0; i < 3; i++) {   //setup the pwm channels,1KHz,8bit
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  red = random(0, 255);
  green = random(0, 255);
  blue = random(0, 255);
  setColor(red, green, blue);
  delay(200);
}

void setColor(byte r, byte g, byte b) {
  analogWrite(ledPins[0], 255-r); //Common anode LED, low level to turn on the led.
  analogWrite(ledPins[1], 255-g);
  analogWrite(ledPins[2], 255-b);
}
