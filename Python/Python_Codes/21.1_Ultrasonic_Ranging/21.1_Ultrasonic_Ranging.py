from machine import Pin
import time

Trig = Pin(19, Pin.OUT, 0)
Echo = Pin(18, Pin.IN, 0)

distance = 0
soundVelocity = 340

def getDistance():
    Trig.value(1)
    time.sleep_us(10)
    Trig.value(0)
    while not Echo.value():
        pass
    pingStart = time.ticks_us()
    while Echo.value():
        pass
    pingStop = time.ticks_us()
    distanceTime = time.ticks_diff(pingStop, pingStart) // 2
    distance = int(soundVelocity * distanceTime // 10000)
    return distance

time.sleep(2)
while True:
    time.sleep_ms(500)
    distance = getDistance()
    print("Distance: ", distance, "cm")
    
