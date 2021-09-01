from machine import Pin,PWM


class myPWM():
    def __init__(self, pwm0: int=16, pwm1: int=17, pwm2: int=18, pwm3: int=19, pwm4: int=20, pwm5: int=21, pwm6: int=22, pwm7: int=26, pwm8: int=27, pwm9: int=28, freq_num: int=10000):
        self._pwm0 = PWM(Pin(pwm0))
        self._pwm0.freq(freq_num)
        self._pwm1 = PWM(Pin(pwm1))
        self._pwm1.freq(freq_num)
        self._pwm2 = PWM(Pin(pwm2))
        self._pwm2.freq(freq_num)
        self._pwm3 = PWM(Pin(pwm3))
        self._pwm3.freq(freq_num)
        self._pwm4 = PWM(Pin(pwm4))
        self._pwm4.freq(freq_num)
        self._pwm5 = PWM(Pin(pwm5))
        self._pwm5.freq(freq_num)
        self._pwm6 = PWM(Pin(pwm6))
        self._pwm6.freq(freq_num)
        self._pwm7 = PWM(Pin(pwm7))
        self._pwm7.freq(freq_num)
        self._pwm8 = PWM(Pin(pwm8))
        self._pwm8.freq(freq_num)
        self._pwm9 = PWM(Pin(pwm9))
        self._pwm9.freq(freq_num)
        
    def ledcWrite(self,chn,value):
        if chn == 0:
            self._pwm0.duty_u16(value)
        elif chn == 1:
            self._pwm1.duty_u16(value)
        elif chn == 2:
            self._pwm2.duty_u16(value)
        elif chn == 3:
            self._pwm3.duty_u16(value)
        elif chn == 4:
            self._pwm4.duty_u16(value)
        elif chn == 5:
            self._pwm5.duty_u16(value)
        elif chn == 6:
            self._pwm6.duty_u16(value)
        elif chn == 7:
            self._pwm7.duty_u16(value)
        elif chn == 8:
            self._pwm8.duty_u16(value)
        elif chn == 9:
            self._pwm9.duty_u16(value)
    

    
    def deinit(self):
        self._pwm0.deinit()
        self._pwm1.deinit()
        self._pwm2.deinit()
        self._pwm3.deinit()
        self._pwm4.deinit()
        self._pwm5.deinit()
        self._pwm6.deinit()
        self._pwm7.deinit()
        self._pwm8.deinit()
        self._pwm9.deinit()


