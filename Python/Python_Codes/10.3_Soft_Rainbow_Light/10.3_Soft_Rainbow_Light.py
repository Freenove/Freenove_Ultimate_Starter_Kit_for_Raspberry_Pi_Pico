from machine import Pin, ADC
from neopixel import myNeopixel
import time

red=0                  #red
green=0                #green
blue=0                 #blue
np = myNeopixel(8, 15)     
adc0=ADC(26)

def wheel(pos):
    global red, green, blue
    WheelPos = pos%255
    if WheelPos < 85:
        red = (255 - WheelPos*3)
        green = (WheelPos*3)
        blue = 0
    elif WheelPos >= 85 and WheelPos < 170:
        WheelPos -= 85
        red = 0
        green = (255 - WheelPos*3)
        blue = (WheelPos*3)
    else :
        WheelPos -= 170
        red = (WheelPos*3)
        green = 0
        blue  =(255 - WheelPos*3)
        
np.brightness(20)        
while True:
        adcValue = adc0.read_u16()//257
        for j in range(0,8):
            wheel(adcValue + j*255 // 8)
            np.set_pixel(j, red, green, blue)
            np.show()
        time.sleep_ms(100)