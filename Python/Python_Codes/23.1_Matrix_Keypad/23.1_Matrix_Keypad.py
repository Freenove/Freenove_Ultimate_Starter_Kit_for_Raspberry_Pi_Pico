from keypad import KeyPad
import time

keyPad = KeyPad(13, 12, 11, 10, 9, 8, 7, 6)

def key():
    keyvalue = keyPad.scan()
    if keyvalue != None:
        print(keyvalue, end="\t")
        time.sleep_ms(300)
        return keyvalue
            
while True:
    key()
