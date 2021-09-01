import time
from my74HC595 import Chip74HC595
from machine import Pin

comPin = [17, 16, 15, 14]
num = [0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8,
      0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e]

def led_display():
    for i in range(0, 4):
        chns = Pin(comPin[i],Pin.OUT)
        chip.shiftOut(0, num[i])
        chns.value(1)
        time.sleep_ms(1)
        chns.value(0)

# Pico-GP 18: 74HC595-DS(18)
# Pico-GP 20: 74HC595-STCP(20)
# Pico-GP 21: 74HC595-SHCP(21)
chip = Chip74HC595(18, 20, 21)

try:
    while True:
        led_display()
except:
    pass
