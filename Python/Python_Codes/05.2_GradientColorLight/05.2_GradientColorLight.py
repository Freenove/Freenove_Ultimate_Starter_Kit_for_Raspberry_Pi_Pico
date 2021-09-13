from machine import Pin, PWM
import time

pins = [13, 12, 11]

#set pwm
pwm0 = PWM(Pin(pins[0]))
pwm1 = PWM(Pin(pins[1]))
pwm2 = PWM(Pin(pins[2]))
pwm0.freq(1000)
pwm1.freq(1000)
pwm2.freq(1000)

def setColor(rgb):              
    pwm0.duty_u16(65535 - (rgb >> 4))
    pwm1.duty_u16(65535 - (rgb >> 1))
    pwm2.duty_u16(65535 - (rgb >> 0))

def wheel(pos):
    WheelPos = pos % 65535
    if WheelPos < 21845:
        return (((65535 - WheelPos*3) << 4) | ((WheelPos*3) << 1))
    elif WheelPos >= 21845 and WheelPos < 43690:
        WheelPos -= 21845
        return (((65535 - WheelPos*3) << 1) | (WheelPos*3))
    else :
        WheelPos -= 43690
        return (((WheelPos*3) << 4) | (65535 - WheelPos*3))

try:
    while True:
        for i in range(0, 65535):
            setColor(wheel(i))
            time.sleep_ms(10)
except:
    pwm0.deinit()
    pwm1.deinit()
    pwm2.deinit()