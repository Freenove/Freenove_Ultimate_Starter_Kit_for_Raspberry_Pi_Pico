from machine import Pin
import time

led = Pin(15, Pin.OUT)                   
button = Pin(13, Pin.IN, Pin.PULL_UP)    #Create button object from Pin13 , Set GP13 to input

def reverseGPIO():
    if led.value():
        led.value(0)                  #Set led turn on
    else:
        led.value(1)                  #Set led turn off
        
try:
    while True:
        if not button.value():
            time.sleep_ms(20)
            if not button.value():
                reverseGPIO()
                while not button.value():
                    time.sleep_ms(20)
except:
    pass
