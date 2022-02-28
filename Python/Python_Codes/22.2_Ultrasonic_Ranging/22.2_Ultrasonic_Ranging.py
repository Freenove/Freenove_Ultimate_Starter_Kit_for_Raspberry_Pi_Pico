from hcsr04 import HCSR04
import time

SR = HCSR04(19, 18)

time.sleep_ms(2000)
try:
    while True:
        print('Distance: ',SR.distanceCM(),'cm')
        #get Distance function: distanceCM(), distanceMM(), distanceM()
        time.sleep_ms(500)
except:
    pass
