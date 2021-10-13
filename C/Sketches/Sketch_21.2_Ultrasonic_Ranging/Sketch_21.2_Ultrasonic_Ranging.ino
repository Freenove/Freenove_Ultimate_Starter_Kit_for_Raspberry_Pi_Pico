/**********************************************************************
  Filename    : Ultrasonic Ranging
  Description : Use the ultrasonic module to measure the distance.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#include <UltrasonicSensor.h>

//Attach the trigger and echo pins
UltrasonicSensor ultrasonic(19, 18);

void setup() {
  Serial.begin(115200);
  //set the speed of sound propagation according to the temperature to reduce errors
  int temperature = 22;//Setting ambient temperature
  ultrasonic.setTemperature(temperature);
}

void loop() {
  int distance = ultrasonic.distanceInCentimeters();
  Serial.println(String("Distance: ")+distance+String("cm"));
  delay(300);
}
