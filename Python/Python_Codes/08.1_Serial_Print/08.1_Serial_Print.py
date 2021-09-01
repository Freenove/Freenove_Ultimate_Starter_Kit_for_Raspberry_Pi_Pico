import time

print("Raspberry Pi Pico initialization completed !")

while True:
    print("Running time : ", time.time()%60,"s")
    time.sleep(1)
