from machine import Pin
import time
from dht11 import DHT11, InvalidChecksum

pin = Pin(15, Pin.OUT, Pin.PULL_DOWN)
dht = DHT11(pin)
time.sleep(1)

while True:
    try:
        temperature = dht.temperature
        humidity = dht.humidity
        print("temperature: {:.02f}C  humidity: {:.02f}".format(temperature, humidity) + "%")    
        time.sleep(2)
    except InvalidChecksum:
        print("DHT11 data error!")