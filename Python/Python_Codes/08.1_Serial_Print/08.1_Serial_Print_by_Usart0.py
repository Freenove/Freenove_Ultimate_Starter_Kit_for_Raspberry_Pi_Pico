from machine import UART, Pin
import time

#uart0
#tx = Pin(0),Pin(12) or Pin(16)
#rx = Pin(1),Pin(13) or Pin(17)



myUsart0 = UART(0, baudrate=115200, bits=8, tx=Pin(12), rx=Pin(13), timeout=10) 
myUsart0.write("Raspberry Pi Pico initialization completed!\r\n")

while True:
    myUsart0.write("Running time : ")
    a=str(time.ticks_ms()/1000)
    myUsart0.write(a)
    myUsart0.write(" s\r\n")
    time.sleep(1)