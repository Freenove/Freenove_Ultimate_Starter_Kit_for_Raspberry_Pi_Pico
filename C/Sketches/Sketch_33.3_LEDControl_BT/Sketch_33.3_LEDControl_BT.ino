#include <SerialBT.h>

#define LED 15                //LED pin
bool led_status = false;  

void setup() {
  pinMode(LED, OUTPUT);

  SerialBT.setName("PicoW_BT");//Bluetooth device name
  SerialBT.begin();
  
  Serial.begin(115200);
  delay(2000);
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if(SerialBT.available()){
    String myString = SerialBT.readString();      //read String
    myString.trim();                              //Clear the front and back blank spaces
    Serial.println(myString);
    if(myString.equals("led_on") == true){        //on
      led_status = true;
      digitalWrite(LED, led_status);              
    }
    if(myString.equals("led_off") == true){       //off
      led_status = false;
      digitalWrite(LED, led_status);
    }
    if(myString.equals("led_toggle") == true){    //toggle
      led_status = !led_status;
      digitalWrite(LED, led_status);
    }
  }
}
