import bluetooth

sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
sock.connect(( "98:DA:60:01:94:CD" , 1))

with open(imageFile.text)