from myservo import Servo
from keypad import KeyPad
from machine import Pin
import time

keyPad = KeyPad(13, 12, 11, 10, 9, 8, 7, 6)
servo = Servo(0)
servo.ServoAngle(0)
activeBuzzer = Pin(15, Pin.OUT)

passWord = "1234"
keyIn = ""
def key():
    keyvalue = keyPad.scan()
    if keyvalue != None:
        print('Your input:', keyvalue)
        time.sleep_ms(200)
        return keyvalue

while True:
    keydata = key()
    if keydata != None:
        activeBuzzer.value(1)
        time.sleep_ms(100)
        activeBuzzer.value(0)
        keyIn += keydata 
        
    if len(keyIn) == 4:
        if keyIn == passWord:
            print("passWord right!")
            servo.ServoAngle(90)
            time.sleep_ms(1000)
            servo.ServoAngle(0)
        else:
            print("passWord error!")
            activeBuzzer.value(1)
            time.sleep_ms(1000)
            activeBuzzer.value(0)
        keyIn = ""
