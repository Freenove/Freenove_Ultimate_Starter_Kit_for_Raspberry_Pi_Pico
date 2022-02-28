from myservo import Servo
from machine import ADC,Pin
import time

servo=Servo(15)
adc=ADC(26)
servo.ServoAngle(0)

try:
    while True:
        adcValue = adc.read_u16()
        angle = (adcValue * 180) / 65535
        servo.ServoAngle(int(angle))
        time.sleep_ms(50)
except:
    servo.deinit()