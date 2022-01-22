import requests,random,time

try:
    while True:
        temperature = random.randint(30,35)
        humidity = random.randint(10,30)
        light = random.randint(1,10)
        pressure = random.randint(1,5)

        response = requests.get(
            "https://api.thingspeak.com/update?api_key=0J6B9SZ9H45ZON3B&field1=0",
            params={'field1':humidity,'field2':temperature,'field3':light,'field4':pressure}
        )

        print(f"Status {response.status_code}")
        time.sleep(1)
except:
    print("\nExiting due to Error...")