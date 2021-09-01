from machine import ADC, Pin, PWM
import time

#set ADC channel
adc0 = ADC(26)
adc1 = ADC(27)
adc2 = ADC(28)

#set PWM
pwm0 = PWM(Pin(13))
pwm0.freq(1000)
pwm1 = PWM(Pin(14))
pwm1.freq(1000)
pwm2 = PWM(Pin(15))
pwm2.freq(1000)

try:
    while True:
        pwm0.duty_u16(65535 - adc0.read_u16())
        pwm1.duty_u16(65535 - adc1.read_u16())
        pwm2.duty_u16(65535 - adc2.read_u16())
        time.sleep(0.1)
except:
    pwm.deinit()
