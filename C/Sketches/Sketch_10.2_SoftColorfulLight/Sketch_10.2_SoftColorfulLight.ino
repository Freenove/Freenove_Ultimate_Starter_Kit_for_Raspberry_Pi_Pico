/**********************************************************************
  Filename    : SoftColorfulLight
  Description : Controlling the color of RGBLED by potentiometer.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
const byte ledPins[] = {15, 14, 13};      //define led pins
const byte adcChns[] = {26, 27, 28};    // define the adc channels
int colors[] = {0, 0, 0};               // red, green ,blue values of color.
void setup() {
  for (int i = 0; i < 3; i++) {   //setup the pwm channels
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    colors[i] = map(analogRead(adcChns[i]), 0, 1023, 0, 255); //calculate color value.
    analogWrite(ledPins[i], colors[i]);
  }
  delay(10);
}
