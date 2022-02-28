import time
from machine import Pin

class DHT11:
    def __init__(self, pin_name):
        self._PinName = pin_name
        self._data = []
        self._status = 0
        self._datas = [0x00, 0x00, 0x00, 0x00, 0x00]
        
    def read_data(self):
        retry = 0
        index = 0
        dhtPin = Pin(self._PinName, Pin.OUT)
        dhtPin.value(0)
        time.sleep_ms(20)
        dhtPin.value(1)
        dhtPin = Pin(self._PinName, Pin.IN)
        time.sleep_us(20)
        
        while dhtPin.value() == 0 and index < 200:
            time.sleep_us(1)
            retry += 1
        retry = 0
        
        while dhtPin.value() == 1 and index < 200:
            time.sleep_us(1)
            retry += 1
        retry = 0
        
        while index < 40:
            retry = 0
            while dhtPin.value() == 0:
                pass
            while dhtPin.value() == 1:
                retry += 1
                if retry > 100:
                    break
            if retry < 3:
                self._data.append(0)        
            else:
                self._data.append(1)
            index = index + 1
        index = 0
        
        for i in range(5): 
            for index in range(8):
                self._datas[i] = (self._datas[i] << 1) | self._data[i*8 + index]
        if self._datas[4] != self._datas[0] + self._datas[1] + self._datas[2] + self._datas[3]:
            self._datas = []
            return self._datas
        return self._datas
    
    def temperature(self):
        temp = self._datas[2] + self._datas[3]/100
        return temp
    
    def humidity(self):
        humi = self._datas[0] + self._datas[1]/100
        return humi
    
    def measure(self):
        self._data = []
        self._datas = [0x00, 0x00, 0x00, 0x00, 0x00]
        self.read_data()
        if self._datas != []:
            return 1
        else:
            return 0