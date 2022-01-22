import socket
import time
import random


SERVER = socket.gethostbyname(socket.gethostname()) # getting Local IP Address automatically
server_add = (SERVER,12345)

c = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
c.connect(server_add)

# Sending request to Server
def send(message):
    print(f"Sending {message} to Server")
    message =  message.encode('utf-8')
    c.send(message)


if __name__ == '__main__':
    try:
        while True:
            temp = random.randint(0,55)
            humidity = random.randint(30,70)
            msg = f"{temp},{humidity}"
            send(msg)
            time.sleep(1)
    except:
        print("\nRequest stopped")
    finally:
        c.close()

