/**********************************************************************
  Filename    : ADC
  Description : Basic usage of ADC
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#define PIN_ANALOG_IN  26

void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);
  double voltage = adcVal / 1023.0 * 3.3;
  Serial.println("ADC Value: " + String(adcVal) + " --- Voltage Value: " + String(voltage) + "V");
  delay(500);
}
