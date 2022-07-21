/**********************************************************************
  Filename    : Temperature and Humidity Sensor
  Description : Use DHT11 to measure temperature and humidity.Print the result to the LCD1602.
  Auther      : www.freenove.com
  Modification: 2021/10/13
**********************************************************************/
#include <LiquidCrystal_I2C.h>
#include <dht.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //initialize the LCD
int dhtPin = 15;                  // the number of the DHT11 sensor pin
dht DHT;

void setup() {
  lcd.init();                     // LCD driver initialization
  lcd.backlight();                // Open the backlight
}

void loop() {
  // read DHT11 data and save it
  int chk = DHT.read11(dhtPin);
  if (chk == DHTLIB_OK) {
    lcd.clear();
    lcd.setCursor(0, 0);              //set the cursor to column 0, line 1
    lcd.print("Temp: ");              //display the Humidity on the LCD1602
    lcd.print(int(DHT.temperature));
    lcd.print(" C");
    lcd.setCursor(0, 1);              //set the cursor to column 0, line 0
    lcd.print("Humi: ");              //display the Humidity on the LCD1602
    lcd.print(int(DHT.humidity));
    lcd.print(" %");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);              //set the cursor to column 0, line 1
    lcd.print("DHT11 Data error");
  }
  delay(2000);
}
