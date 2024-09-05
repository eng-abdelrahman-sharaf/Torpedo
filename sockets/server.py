import socket
import random
from time import sleep

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.bind(("localhost", 1234))
serversocket.listen(5)

packets = [random.randint(1,1000) for i in range(10000)]

while True:
    clientsocket, address = serversocket.accept()
    print(f"Connection from {address} has been established!")
    connected = True
    while connected:
        recv = clientsocket.recv(1024)
        if (recv!=b""):
            recv = recv.decode("utf-8")
            for i in recv.split(","):                
                if i == "e":
                    connected = False
                    print("Connection closed by client!")
                    break

                if i != "":
                    clientsocket.sendall((str(packets[int(i)])+",").encode("utf-8"))
    clientsocket.close()
                    
    

