from machine import Pin, SoftSPI
from mfrc522 import MFRC522

sck = Pin(2, Pin.OUT)
copi = Pin(3, Pin.OUT) # Controller out, peripheral in
cipo = Pin(4, Pin.OUT) # Controller in, peripheral out
spi = SoftSPI(baudrate=100000, polarity=0, phase=0, sck=sck, mosi=copi, miso=cipo)
sda = Pin(5, Pin.OUT)
reader = MFRC522(spi, sda)

while True:
    try:
        (status, tag_type) = reader.request(reader.CARD_REQIDL)#Read the card type number
        if status == reader.OK:
            print('Find the card!')
            (status, raw_uid) = reader.anticoll()#Reads the card serial number of the selected card
            if status == reader.OK:
                print('New Card Detected')
                print('  - Tag Type: 0x%02x' % tag_type)
                print('  - uid: 0x%02x%02x%02x%02x' % (raw_uid[0], raw_uid[1], raw_uid[2], raw_uid[3]))
                print('')
                if reader.select_tag(raw_uid) == reader.OK:#Read card memory capacity
                    key = [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF]
                    if reader.auth(reader.AUTH, 2, key, raw_uid) == reader.OK:#Verification card password
                        print(bytearray(reader.read(2)))
                        reader.stop_crypto1()
                    else:
                        print("AUTH ERROR")
                else:
                    print("FAILED TO SELECT TAG")
    except KeyboardInterrupt:
        break
    


        
        
        
        
        
        
        
        
