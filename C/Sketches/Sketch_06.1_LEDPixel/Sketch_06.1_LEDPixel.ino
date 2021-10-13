/**********************************************************************
  Filename    : NeoPixel
  Description : Basic usage of LEDPixel, 
                Make the strip light up in different colors gradually.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#include <Adafruit_NeoPixel.h>

#define Pin       16
#define NumPixels 8
int setColor[5][3] = { {255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 255}, {0, 0, 0} };

Adafruit_NeoPixel pixels(NumPixels, Pin, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(20);
}

void loop() {
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < NumPixels; i++) {
      pixels.setPixelColor(i, setColor[j][0], setColor[j][1], setColor[j][2]);
      pixels.show();
      delay(100);
    }
    delay(500);
  }
}
