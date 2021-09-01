from machine import ADC,Pin
import time

xValue = ADC(28)
yValue = ADC(27)
zValue = Pin(26, Pin.IN, Pin.PULL_UP)

while True:
    print("X, Y, Z :", xValue.read_u16(),
          ",", yValue.read_u16(), ",", zValue.value())
    time.sleep(0.1) 