from machine import Pin,PWM

class myServo(object):
    def __init__(self, pin: int=15, hz: int=50):
        self._servo = PWM(Pin(pin))
        self._servo.freq(hz)
    
    def myServoWriteDuty(self, duty): 
        if duty <= 1638:              
            duty = 1638
        if duty >= 8190:
            duty = 8190
        self._servo.duty_u16(duty)
        
    def myServoWriteAngle(self, pos): 
        if pos <= 0:
            pos = 0
        if pos >= 180:
            pos = 180
        pos_buffer=(pos/180)*(8190-1638)
        self._servo.duty_u16(int(pos_buffer) + 1638)

    def myServoWriteTime(self, us):
        if us <= 500:
            us = 500
        if us >= 2500:
            us = 2500
        pos_buffer= (us / 1000) * 3276
        self._servo.duty_u16(int(pos_buffer))
        
    def deinit(self):
        self._servo.deinit()
