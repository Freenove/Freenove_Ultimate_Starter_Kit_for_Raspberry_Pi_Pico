from machine import Pin,PWM
import math
import time
PI = 3.14
button = Pin(16, Pin.IN, Pin.PULL_UP)
passiveBuzzer = PWM(Pin(15))
passiveBuzzer.freq(1000)

def alert():
    for x in range(0, 36):
        sinVal  = math.sin(x * 10 * PI / 180)
        toneVal = 1500+int(sinVal*500)
        passiveBuzzer.freq(toneVal)
        time.sleep_ms(10)
     
try:
    while True:
        if not button.value():
            passiveBuzzer.duty_u16(4092*2)
            alert()   
        else:
            passiveBuzzer.duty_u16(0)
except:
    passiveBuzzer.deinit()
