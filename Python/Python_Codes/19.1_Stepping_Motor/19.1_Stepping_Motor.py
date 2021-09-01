from stepmotor import Stepmotor
import time

myStepMotor = Stepmotor(21, 20, 19, 18)

try:
    while True:  
        myStepMotor.moveSteps(1, 32*64, 2000)
        myStepMotor.stop()
        time.sleep(1)
        myStepMotor.moveSteps(0, 32*64, 2000)
        myStepMotor.stop()
        time.sleep(1)
except:
    pass
    
    
    
    
    
    
    
    
    
    
    

    
    