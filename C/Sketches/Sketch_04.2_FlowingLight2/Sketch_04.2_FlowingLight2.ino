/**********************************************************************
  Filename    : FlowingLight2
  Description : More cool flowing light.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
const byte ledPins[] = {16, 17, 18, 19, 20, 21, 22, 26, 27, 28};    //define led pins

const int dutys[] = {0,    0,    0,    0,   0,   0,   0,  0,  0,  0,
                     4095, 2047, 1023, 512, 256, 128, 64, 32, 16, 8,
                     0,    0,    0,    0,   0,   0,   0,  0,  0,  0};      //define the pwm dutys
                     
int ledCounts;        //the number of leds
int delayTimes = 50;  //flowing speed ,the smaller, the faster
void setup() {
  ledCounts = sizeof(ledPins);    //get the led counts
  for (int i = 0; i < ledCounts; i++) {   //setup the pwm channels
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 20; i++) {        //flowing one side to other side
    for (int j = 0; j < ledCounts; j++) {
      analogWrite(ledPins[j], map(dutys[i+j], 0, 4095, 0, 255));
    }
    delay(delayTimes);
  }
  for (int i = 0; i < 20; i++) {        //flowing one side to other side
    for (int j = 0; j < ledCounts; j++) {
      analogWrite(ledPins[ledCounts - j - 1], map(dutys[i+j], 0, 4095, 0, 255));    
    }
    delay(delayTimes);
  }
}
