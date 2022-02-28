#ifndef __IR_H__
#define __IR_H__

#include <Arduino.h>

extern int flagCode;

void IR_Init(int pin);
unsigned long IR_Decode(int &code);
void IR_Release();

void IR_Read();

#endif
