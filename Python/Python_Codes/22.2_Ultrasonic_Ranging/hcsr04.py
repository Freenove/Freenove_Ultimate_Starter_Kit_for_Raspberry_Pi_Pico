from machine import Pin
import time

soundVelocity=340
distance=0

class HCSR04(object):
    def __init__(self, trig: int=19, echo: int=18):
        self._trigPin = Pin(trig,Pin.OUT,0)
        self._echoPin = Pin(echo,Pin.IN,0)

    def distanceCM(self):
        self._trigPin.value(1)
        time.sleep_us(10)
        self._trigPin.value(0)    
        while(self._echoPin.value() == 0):
            pass
        pingStart = time.ticks_us()
        while(self._echoPin.value() == 1):
            pass
        pingStop = time.ticks_us()
        distanceTime = time.ticks_diff(pingStop,pingStart) // 2
        distance = distanceTime * soundVelocity // 10000
        return distance
    
    def distanceMM(self):
        self._trigPin.value(1)
        time.sleep_us(10)
        self._trigPin.value(0)    
        while(self._echoPin.value() == 0):
            pass
        pingStart = time.ticks_us()
        while(self._echoPin.value() == 1):
            pass
        pingStop = time.ticks_us()
        distanceTime = time.ticks_diff(pingStop, pingStart)// 2
        distance = distanceTime * soundVelocity // 10000 * 10
        return distance
    
    def distanceM(self):
        self._trigPin.value(1)
        time.sleep_us(10)
        self._trigPin.value(0)    
        while(self._echoPin.value() == 0):
            pass
        pingStart=time.ticks_us()
        while(self._echoPin.value() == 1):
            pass
        pingStop = time.ticks_us()
        distanceTime = time.ticks_diff(pingStop,pingStart) / 2
        distance = distanceTime * soundVelocity // 10000 / 100
        return distance
    

