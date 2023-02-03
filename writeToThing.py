import serial, bluetooth, time

sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
sock.connect(( "98:DA:60:01:94:CD" , 1))

def sendTestCoords(theData):

    sock.send(bytes(theData, 'utf-8'))


# sendTestCoords(f"cx{1:04}y{-700:04}" + '~')
# sendTestCoords(f"cx{1:04}y{500:04}" + '~')
# sendTestCoords(f"cx{1:04}y{-600:04}" + '~')
# print("done")
# while True:
#     x = sock.recv(10)
#     print(x)
#     time.sleep(1)
commands = {'1':'c', '2':'u', '3':'d'}

def theTenThing():

        time.sleep(1)
        sendTestCoords(f"ux0000y0000" + '~')
        time.sleep(0.5)
        sendTestCoords(f"tx0000y0000" + '~')
        time.sleep(1)
        sendTestCoords(f"dx0000y0000" + '~')
        time.sleep(0.5)
        sendTestCoords(f"tx0100y0100" + '~')



while True:

    # theTenThing()
    z = input("Enter type: ")
    x = int(input("Number of steps in the x direction: "))
    y = int(input("Number of steps in the y direction: "))
    print(f"{z}x{x:04}y{y:04}")
    sendTestCoords(f"{z}x{x:04}y{y:04}" + '~')
