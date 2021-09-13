from machine import UART, Pin, ADC
import time

#Start sign and End sign
#in processing unhex("80") = 128, hex(128) = "0x80"
transStart = "80"  #hex
transEnd = "81"    #hex

#request send
#Handshake signal
requestEcho = "0"  
Echo = "1"         #hex

#Request content
#An ADC data
requestAnalog = "10"
Analog = "b"       #hex
#Multiple ADC data
requestAnalogs = "12"
Analogs = "d"      #hex
#Key signal
requestDigital = "14"
Digital = "f"      #hex

ADC0 = ADC(26)
ADC1 = ADC(27)
ADC2 = ADC(28)
ADC_all = [ADC0, ADC1, ADC2]
Key1 = Pin(18, Pin.IN, Pin.PULL_UP)
Key2 = Pin(19, Pin.IN, Pin.PULL_UP)
Key3 = Pin(20, Pin.IN, Pin.PULL_UP)
Key4 = Pin(21, Pin.IN, Pin.PULL_UP)
Led = Pin(25, Pin.OUT)
keyValue = 0

def keyScan():
    if Key1.value() == 0 or Key2.value() == 0 or Key3.value() == 0 or Key4.value() == 0:
        time.sleep_ms(20)
        if Key1.value() == 0:
            return "1"
        elif Key2.value() == 0:
            return "2"
        elif Key3.value() == 0:
            return "3"
        elif Key4.value() == 0:
            return "4"
    return "0"

def Signal_lamp():
    Ledvalue = time.time()%60%2
    Led.value(Ledvalue)

while True:
    sendData = ""
    Signal_lamp()
    keyValue = keyScan()
    acceptData = input()    #acceptData: "128/.../129" is string
    if len(acceptData) > 0: 
        acceptData = acceptData.split('/') # acceptData: ["128", ..., "129"]
        acceptData_length = len(acceptData)
        if acceptData[0] == "128" and acceptData[acceptData_length-1] == "129" and acceptData_length >= 3:
            if acceptData[1] == "0":  #Judge the first flag data
                sendData = Echo
            
            if acceptData[1] == "10":
                adc0_value = hex(ADC0.read_u16()) #Convert data to hexadecimal as：adc0_value = "0xffff"
                #adc0_value.split("x") --> ["0", "ffff"]
                sendData =  Analog + "/" + adc0_value.split("x")[1]
                
            if acceptData[1] == "12":
                adc_values = ""
                if acceptData[2] == "3": #Judge the second flag data
                    num = 3
                elif acceptData[2] == "2":
                    num = 2
                else:
                    continue
                for adc in ADC_all[0 : num]:
                    value = hex(adc.read_u16())
                    adc_values += value.split("x")[1] + "/"  
                sendData = Analogs + "/" + adc_values[0 : len(adc_values)-1]
                
            if acceptData[1] == "14":
                sendData = Digital + "/" + keyValue
                
            if sendData != "":
                print(transStart +"/" + sendData + "/" + transEnd)