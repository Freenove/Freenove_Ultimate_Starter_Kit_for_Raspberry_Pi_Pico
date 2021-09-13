import time
import dht11

temperature = 0
humidity = 0

dht = dht11.DHT11(15)
time.sleep(1)

while True:
    if dht.measure() == 0:
        print("DHT11 data error!")
        break
    time.sleep(1)
    temperature = dht.temperature()
    humidity = dht.humidity()
    print("temperature: %0.2f℃  humidity: %0.2f"%(temperature, humidity) + "%")