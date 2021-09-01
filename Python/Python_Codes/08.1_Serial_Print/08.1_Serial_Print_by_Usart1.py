from machine import UART, Pin
import time

#tx = Pin(4) or Pin(7)
#rx = Pin(5) or Pin(8)
myUsart1 = UART(1, baudrate=115200, bits=8, tx=Pin(4), rx=Pin(5), timeout=10) 
myUsart1.write("Raspberry Pi Pico initialization completed!\r\n")

while True:
    myUsart1.write("Running time : ")
    a=str(time.ticks_ms() / 1000)
    myUsart1.write(a)
    myUsart1.write(" s\r\n")
    time.sleep(1)