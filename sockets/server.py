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
    packet_checked = False
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
                    # sending false package for package number 990 
                    if(int(i) == 990 and not packet_checked):
                        i = str(int(i)+10)
                        packet_checked = True
                    print(f"Sending packet {i} to client")
                    clientsocket.sendall((i+":"+str(packets[int(i)])+",").encode("utf-8"))
    clientsocket.close()
                    
    

