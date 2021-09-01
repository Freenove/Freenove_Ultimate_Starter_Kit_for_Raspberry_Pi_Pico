import time
from machine import I2C, Pin
from I2C_LCD import I2CLcd
import dht11

DHT = dht11.DHT11(15)

DEFAULT_I2C_ADDR = 0x27 
i2c = I2C(0, scl=Pin(9), sda=Pin(8), freq=400000)
lcd = I2CLcd(i2c, DEFAULT_I2C_ADDR, 2, 16)
time.sleep(1)

try:
    while True:
        if DHT.measure() == 0:
            print("DHT11 data error")
            break
        temp = int(DHT.temperature())
        humi = int(DHT.humidity())
        lcd.move_to(0, 0)
        lcd.putstr("Temp: ")
        lcd.putstr(str(temp))
        lcd.putstr(" C")
        lcd.move_to(0, 1)
        lcd.putstr("Humi: ")
        lcd.putstr(str(humi))
        lcd.putstr(" %")
        time.sleep(1)
except:
    pass













