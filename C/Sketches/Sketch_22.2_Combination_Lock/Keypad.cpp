#include "Keypad.h"

byte rowPin[4] = {13, 12, 11, 10};
byte colPin[4] = { 9,  8,  7,  6};

char keyStrings[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

int lastTime = 0;
int debounceTime = 20;

int pressKeyRow=0;
int pressKeyCol=0;
bool pressState=false;

void keyInit(void){
  for (int r = 0; r < sizeof(rowPin); r++){
    pinMode(colPin[r], OUTPUT);
    digitalWrite(colPin[r], HIGH);
    pinMode(rowPin[r], INPUT_PULLUP);
  }
  for (int c = 0; c < sizeof(colPin); c++){
    pinMode(colPin[c], OUTPUT);
    digitalWrite(colPin[c], HIGH);
  }
}

void keyScan(bool state){
  for (int c = 0; c < sizeof(colPin); c++){
    digitalWrite(colPin[c], LOW);
    for (int r = 0; r < sizeof(rowPin); r++){
      if (digitalRead(rowPin[r]) == LOW){
        while (state == true && digitalRead(rowPin[r]) == LOW);
        digitalWrite(colPin[c], HIGH);
        pressKeyRow=r;
        pressKeyCol=c;
        pressState=true;
      }
    }
    digitalWrite(colPin[c], HIGH);
  }
}

char getKey(bool state){
  if (millis() - lastTime > debounceTime){
    pressState = false;
    keyScan(state);
    lastTime = millis();
    if(pressState==true)
      return keyStrings[pressKeyRow][pressKeyCol];
    else
      return '\0';
  }
}
