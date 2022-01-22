import socket
import csv


SERVER = socket.gethostbyname(socket.gethostname()) # getting Local IP Address automatically
server_add = (SERVER, 12345)

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s.bind(server_add)
print("Server connected to address:", str(server_add))


# Starts the Server
def run_server():
    s.listen()
    print("Server listening....")
    connection, address = s.accept()
    with open("datalog.csv","w") as f: # creating csv file for storing data 
        writer = csv.writer(f)
        writer.writerow(['Temperature (in C)','Humidity (in %)'])
        while True:
            message = connection.recv(2048).decode('utf-8') # Receives data Upto 2048 Bytes
            if not message:
                break
            data = message.split(',')
            
            print(f"Recieving from client: Temperature={data[0]} C & Humidity={data[1]} %")
            writer.writerow(data) # store the received data to datalog.csv file
    f.close()


if __name__ == '__main__':
    try:
        print("Requesting data...")
        run_server()
    except:
        print("\nServer stopped!!!")
    finally:
        s.close()