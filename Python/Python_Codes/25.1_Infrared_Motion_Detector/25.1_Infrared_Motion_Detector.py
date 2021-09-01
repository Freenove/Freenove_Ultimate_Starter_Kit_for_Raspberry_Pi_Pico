from machine import Pin
import time

sensorPin = Pin(15,Pin.IN)
ledPin = Pin(16,Pin.OUT)

try:
    while True:
      if not sensorPin.value():     
        ledPin.value(1)  #Set led turn on
      else:
        ledPin.value(0)  #Set led turn off
except:
    pass