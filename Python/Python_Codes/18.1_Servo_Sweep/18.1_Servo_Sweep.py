from myservo import Servo
import time

servo=Servo(16)
servo.ServoAngle(0)
time.sleep_ms(1000)

try:
    while True:       
        for i in range(0, 180, 1):
            servo.ServoAngle(i)
            time.sleep_ms(15)
        for i in range(180, 0, -1):
            servo.ServoAngle(i)
            time.sleep_ms(15)        
except:
    servo.deinit()