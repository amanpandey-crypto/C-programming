import socket 
import base64 


def Main(): 
   
    SERVER = socket.gethostbyname(socket.gethostname()) # getting Local IP Address automatically
    server_add = (SERVER, 10009)

    c = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
    c.connect(server_add) 
    while True: 
        msg = "Client 1: Aman chandra pandey"
        encodedBytes = base64.b64encode(msg.encode("utf-8"))  
        encoded_data = str(encodedBytes, "utf-8")  
        print ('Encoded_Message:', encoded_data) 
        c.send(encoded_data.encode('ascii'))  
        server_data = c.recv(1024) 
        print('Server_Message:', server_data.decode('ascii')) 
    
        ans = input('\nDo you want to continue(y/n):')  
        if ans == 'y': 
            continue 
        else: 
            break 
    c.close()


if __name__ == '__main__': 
    
    Main() 