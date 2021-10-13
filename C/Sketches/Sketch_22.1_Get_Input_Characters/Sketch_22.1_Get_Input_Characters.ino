/**********************************************************************
  Filename    : Get Input Characters
  Description : Get the value for the matrix keyboard
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#include "Keypad.h"

void setup(){
  Serial.begin(115200);
  keyInit();
}

void loop(){
  char keyValue = getKey(0);
  if (keyValue != '\0')
    Serial.println(keyValue);
  delay(50);
}
