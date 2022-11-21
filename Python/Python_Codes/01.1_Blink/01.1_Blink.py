from machine import Pin
import time

led = Pin(25, Pin.OUT)   # Pico LED
#led = Pin("LED", Pin.OUT) # Pico W LED

try:
    while True:
        led.value(1)    # Set led turn on
        time.sleep(0.5) # Sleep 0.5s
        led.value(0)    # Set led turn off
        time.sleep(0.5) # Sleep 0.5s
except:
    pass