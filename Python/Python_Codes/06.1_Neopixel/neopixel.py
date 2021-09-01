import array, time
from machine import Pin
import rp2



@rp2.asm_pio(sideset_init=rp2.PIO.OUT_LOW, out_shiftdir=rp2.PIO.SHIFT_LEFT, autopull=True, pull_thresh=24)
def ws2812():
    T1 = 2
    T2 = 5
    T3 = 8
    wrap_target()
    label("bitloop")
    out(x, 1)              .side(0)    [T3 - 1]
    jmp(not_x, "do_zero")  .side(1)    [T1 - 1]
    jmp("bitloop")         .side(1)    [T2 - 1]
    label("do_zero")
    nop()                  .side(0)    [T2 - 1]
    wrap
    
    
class myNeopixel:
    def __init__(self, num_leds, pin, delay_ms=1):
        self.pixels = array.array("I", [0 for _ in range(num_leds)])
        self.state_machine = 0
        self.sm = rp2.StateMachine(self.state_machine, ws2812, freq=8000000, sideset_base=Pin(pin))
        self.sm.active(1)
        self.num_leds = num_leds
        self.delay_ms = delay_ms
        self.brightnessvalue = 255

    def brightness(self, brightness = None):
        if brightness == None:
            return self.brightnessvalue
        else:
            if (brightness < 1):
                brightness = 1
        if (brightness > 255):
            brightness = 255
        self.brightnessvalue = brightness

    def set_pixel_line_gradient(self, pixel1, pixel2, left_r, left_g, left_b, right_r, right_g, right_b):
        if pixel2 - pixel1 == 0: return
    
        right_pixel = max(pixel1, pixel2)
        left_pixel = min(pixel1, pixel2)
        
        for i in range(right_pixel - left_pixel + 1):
            fraction = i / (right_pixel - left_pixel)
            red = round((right_r - left_r) * fraction + left_r)
            green = round((right_g - left_g) * fraction + left_g)
            blue = round((right_b - left_b) * fraction + left_b)
            
            self.set_pixel(left_pixel + i, red, green, blue)
    
    def set_pixel_line(self, pixel1, pixel2, r, g, b):
        for i in range(pixel1, pixel2+1):
            self.set_pixel(i, r, g, b)

    def set_pixel(self, pixel_num, r, g, b):
        blue = round(b * (self.brightness() / 255))
        red = round(r * (self.brightness() / 255))
        green = round(g * (self.brightness() / 255))

        self.pixels[pixel_num] = blue | red << 8 | green << 16
    
    def rotate_left(self, num_of_pixels):
        if num_of_pixels == None:
            num_of_pixels = 1
        self.pixels = self.pixels[num_of_pixels:] + self.pixels[:num_of_pixels]

    def rotate_right(self, num_of_pixels):
        if num_of_pixels == None:
            num_of_pixels = 1
        num_of_pixels = -1 * num_of_pixels
        self.pixels = self.pixels[num_of_pixels:] + self.pixels[:num_of_pixels]

    def show(self):
        for i in range(self.num_leds):
            self.sm.put(self.pixels[i],8)
        time.sleep_ms(self.delay_ms)
            
    def fill(self, r, g, b):
        for i in range(self.num_leds):
            self.set_pixel(i, r, g, b)
        time.sleep_ms(self.delay_ms)
