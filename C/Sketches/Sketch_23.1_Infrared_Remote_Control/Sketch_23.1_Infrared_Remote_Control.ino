  /**********************************************************************
  Filename    : Infrared Remote Control
  Description : Decode the infrared remote control and print it out through the serial port.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#include "IR.h"
#define IR_Pin 16

void setup() {
  Serial.begin(115200);
  IR_Init(IR_Pin);
}

void loop() {
  if(flagCode){
    int irValue = IR_Decode(flagCode);
    Serial.println(irValue, HEX);
    IR_Release();
  }
}
