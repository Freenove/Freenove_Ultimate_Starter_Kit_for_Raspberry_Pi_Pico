/**********************************************************************
  Filename    : SoftLight
  Description : Controlling the brightness of LED by potentiometer.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#define PIN_ADC0        26
#define PIN_LED         15

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  int adcVal = analogRead(PIN_ADC0); //read adc
  analogWrite(PIN_LED, map(adcVal, 0, 1023, 0, 255));
  delay(10);
}
