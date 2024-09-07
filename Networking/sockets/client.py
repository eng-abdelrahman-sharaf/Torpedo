import socket
from time import sleep
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

while True:
    count = 0
    try:
        s.connect(("localhost", 1234))
        break

    except ConnectionRefusedError:
        sleep(1)
        print("Server is not running! trying again...")
        count += 1
        if(count == 5):
            print("Server is not running! exiting...")
            exit(1)
        
current_packet_no = 0

while True:
    s.sendall(bytes(str(current_packet_no) + "," , 'utf-8'))
    recv = s.recv(1024).decode("utf-8")
    for i in recv.split(","):
        if(i != ""):
            packet , data = i.split(":")
            if(int(packet) == current_packet_no):
                print(current_packet_no ,":" ,data )
                current_packet_no+=1
            else:
                print("reasking for packet: ", current_packet_no)
                break

    if(current_packet_no == 1000):
        s.sendall(bytes("e", 'utf-8'))
        break
s.close()