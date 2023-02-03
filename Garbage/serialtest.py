import socket
import time

s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
s.connect(( "98:DA:60:02:AD:09" , 1 ))

while True:
    x = s.recv(10)
    print(x)
    time.sleep(1)