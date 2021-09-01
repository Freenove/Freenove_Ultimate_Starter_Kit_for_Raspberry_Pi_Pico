from machine import Pin
import time

button=Pin(16,Pin.IN,Pin.PULL_UP)
activeBuzzer=Pin(15,Pin.OUT)
activeBuzzer.value(0)

while True:
    if not button.value():
        activeBuzzer.value(1)
    else:
        activeBuzzer.value(0)