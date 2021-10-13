/**********************************************************************
  Filename    : SerialPrinter
  Description : Use UART send some data to PC, and show them on serial monitor.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("Raspberry Pi Pico initialization completed!");
}

void loop() {
  Serial.println( millis() / 1000 % 60);
  delay(1000);
}
