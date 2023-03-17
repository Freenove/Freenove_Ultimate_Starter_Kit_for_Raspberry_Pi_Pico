import time
from machine import I2C, Pin
from I2C_LCD import I2CLcd
import dht11

DHT = dht11.DHT11(5)

i2c = I2C(1, sda=Pin(14), scl=Pin(15), freq=400000)
devices = i2c.scan()
lcd = I2CLcd(i2c, devices[0], 2, 16)
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
        time.sleep(2)
except:
    pass













