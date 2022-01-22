import socket 
import base64 
from _thread import * 
import threading 

print_lock = threading.Lock()

SERVER = socket.gethostbyname(socket.gethostname()) # getting Local IP Address automatically
server_add = (SERVER,10009)
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
s.bind(server_add)
print("Connected to:", server_add) 
 

def threaded(connection): 
    while True: 
        data = connection.recv(4096) 
        if not data: 
            print('Connection Ended.')  
            print_lock.release() 
            break 
        print("Encoded_Message:", data) 
        decodedBytes = base64.b64decode(data)  
        decode_data = str(decodedBytes, "utf-8")
        print("Decoded_Message:", decode_data)  
        connection.send(decode_data.encode('ascii'))  
    connection.close()

def Main(): 
    s.listen() 
    print("Server listening.......")
    while True: 
        con, address = s.accept() 
        print_lock.acquire() 
        print("\nConnecting to:", address[0], ":", address[1]) 
        start_new_thread(threaded, (con,)) 


if __name__ == '__main__': 
    try:
        Main()
    except:
        print("\nServer stopped!!!")
    finally:
        s.close()
