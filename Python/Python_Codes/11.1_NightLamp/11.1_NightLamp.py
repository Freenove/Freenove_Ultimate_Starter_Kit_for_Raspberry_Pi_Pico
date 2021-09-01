from machine import Pin, ADC, PWM
import time

adc = ADC(26)
pwm = PWM(Pin(15))
pwm.freq(10000)
try:
    while True:
        pwm.duty_u16(adc.read_u16())
        time.sleep(0.1)
except:
    pwm.deinit()