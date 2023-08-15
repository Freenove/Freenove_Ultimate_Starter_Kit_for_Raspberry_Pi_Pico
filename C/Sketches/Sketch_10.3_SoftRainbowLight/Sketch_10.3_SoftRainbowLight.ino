/**********************************************************************
  Filename    : SoftRainbowLight
  Description : Make the strip light up in rainbow colors.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#include <Adafruit_NeoPixel.h>

#define Pin       15
#define NumPixels 8
#define Pin_ADC0  26
int red = 0;
int green = 0;
int blue = 0;
int adcVal = 0;
Adafruit_NeoPixel strip(NumPixels, Pin, NEO_GRB + NEO_KHZ800);

void setup(){
  strip.begin();
  strip.setBrightness(20);
}
void loop(){
  adcVal = map(analogRead(Pin_ADC0), 0, 1023, 0, 255);
  for(int i=0; i< 8; i++) {
    Wheel(((i * 256 / 8) + adcVal) & 255);
    strip.setPixelColor(i, strip.Color(red, green, blue));
  }
  strip.show();
  delay(10);
}

void Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    red = 255 - WheelPos * 3;
    green = 0;
    blue = WheelPos * 3;
  }else if(WheelPos < 170) {
    WheelPos -= 85;
    red = 0;
    green = WheelPos * 3;
    blue = 255 - WheelPos * 3;
  }else{
    WheelPos -= 170;
    red = WheelPos * 3;
    green = 255 - WheelPos * 3;
    blue = 0;
  }
}
