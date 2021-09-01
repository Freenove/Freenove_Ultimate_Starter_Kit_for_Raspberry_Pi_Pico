from machine import UART, Pin
import time

myUsart0 = UART(0, baudrate=9600, bits=8, tx=Pin(0), rx=Pin(1), timeout=10)
myUsart1 = UART(1, baudrate=9600, bits=8, tx=Pin(8), rx=Pin(9), timeout=10)

while True:
    rxData = bytes()
    input_cnt = str(input("myUsart1: "))
    myUsart1.write(input_cnt)
    time.sleep(0.1)
    while myUsart0.any() > 0:
        rxData += myUsart0.read(1)
    print("myUsart0: " , rxData.decode('utf-8'))
    