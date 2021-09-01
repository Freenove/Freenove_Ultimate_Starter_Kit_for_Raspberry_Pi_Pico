from machine import Pin
import time

led = Pin(15, Pin.OUT)                   
button = Pin(13, Pin.IN, Pin.PULL_UP)    #Create button object from Pin13 , Set GP13 to input

try:
    while True:
        if not button.value():
            led.value(1)                #Set led turn on
        else:
            led.value(0)                #Set led turn off
except:
    pass