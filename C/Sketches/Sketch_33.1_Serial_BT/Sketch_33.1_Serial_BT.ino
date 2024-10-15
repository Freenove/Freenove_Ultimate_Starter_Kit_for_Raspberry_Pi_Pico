#include <SerialBT.h>

void setup() {
  Serial.begin(115200);
  SerialBT.setName("PicoW_BT");//Bluetooth device name
  SerialBT.begin();
  
  while(!Serial);
  Serial.println("The device started, now you can pair it with bluetooth!");

}

void loop() {
  if(Serial.available()){
    SerialBT.print(Serial.readString());
  }
  if(SerialBT.available()){
    Serial.print(SerialBT.readString());
  }
  delay(5);
}
