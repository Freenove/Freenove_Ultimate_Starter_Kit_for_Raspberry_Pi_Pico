/**********************************************************************
  Filename    : BreathingLight
  Description : Make led light fade in and out, just like breathing.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#define PIN_LED   15   //define the led pin

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  for (int i = 0; i < 255; i++) { //make light fade in
    analogWrite(PIN_LED, i);
    delay(5);
  }
  for (int i = 255; i > -1; i--) {  //make light fade out
    analogWrite(PIN_LED, i);
    delay(5);
  }
}
