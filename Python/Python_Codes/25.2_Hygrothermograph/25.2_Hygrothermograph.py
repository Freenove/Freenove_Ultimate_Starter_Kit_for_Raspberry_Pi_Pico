import time
from machine import I2C, Pin
from I2C_LCD import I2CLcd
from dht11 import DHT11, InvalidChecksum

pin = Pin(5, Pin.OUT, Pin.PULL_DOWN)
dht = DHT11(pin)

i2c = I2C(1, sda=Pin(14), scl=Pin(15), freq=400000)
devices = i2c.scan()
lcd = I2CLcd(i2c, devices[0], 2, 16)
time.sleep(1)

try:
    while True:
        temp = int(dht.temperature)
        humi = int(dht.humidity)
        lcd.move_to(0, 0)
        lcd.putstr("Temp: ")
        lcd.putstr(str(temp))
        lcd.putstr(" C")
        lcd.move_to(0, 1)
        lcd.putstr("Humi: ")
        lcd.putstr(str(humi))
        lcd.putstr(" %")
        time.sleep(2)
except InvalidChecksum:
    print("DHT11 data error!")














