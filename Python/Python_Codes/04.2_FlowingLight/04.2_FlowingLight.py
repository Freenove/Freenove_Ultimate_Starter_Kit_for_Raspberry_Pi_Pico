from machine import Pin,PWM
from pwm import myPWM
import time

mypwm = myPWM(16, 17, 18, 19, 20, 21, 22, 26, 27, 28)
chns = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
dutys = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65535, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
delayTimes = 50

try:
    while True:
        for i in range(0, 20):
            for j in range(0, 10):
                mypwm.ledcWrite(chns[j], dutys[i+j])
            time.sleep_ms(delayTimes)
            
        for i in range(0, 20):
            for j in range(0, 10):
                mypwm.ledcWrite(chns[9 -j], dutys[i+j])
            time.sleep_ms(delayTimes)
except:
    mypwm.deinit()
