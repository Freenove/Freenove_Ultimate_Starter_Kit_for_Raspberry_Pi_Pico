from machine import ADC, Pin, PWM
import time
import math

in1Pin = Pin(15, Pin.OUT)
in2Pin = Pin(16, Pin.OUT)
pwm = PWM(Pin(17)) #enable(GP17)
pwm.freq(1000)
pwm.duty_u16(512)
adc = ADC(26)

def driveMotor(dir, spd):
    if dir:
        in1Pin.value(1)
        in2Pin.value(0)
    else :
        in1Pin.value(0)
        in2Pin.value(1)
    pwm.duty_u16(spd)
    
try:
    while True:
        potenVal = adc.read_u16()
        rotationSpeed = potenVal - 32767
        if (potenVal > 32767):
            rotationDir = 1;
        else:
            rotationDir = 0;
        rotationSpeed = int(math.fabs((potenVal-32767) * 2) - 1)
        driveMotor(rotationDir,rotationSpeed)
        time.sleep_ms(10)
except:
    pwm.deinit()