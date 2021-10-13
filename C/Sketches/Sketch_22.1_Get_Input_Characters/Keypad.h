#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include <Arduino.h>

void keyInit(void);
void keyScan(bool state);
char getKey(bool state);

#endif
