import bluetooth, time

sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
sock.connect(( "98:DA:60:01:94:CD" , 1))

def sendTestCoords(theData):

    print(theData)
    sock.send(bytes(theData, 'utf-8'))

with open('imageFiles/sonic.gcode', 'r') as j:
    gcode = j.readlines()

maxX = -100000000000000000000000
maxY = -100000000000000000000000
minX = 10000000000000000000000
minY = 10000000000000000000000

commands = []
count = 0
previousX = 'asdf'
previousY = 'adsf'
previous='0'
sleepafter = False

def sendCoords():
    if previous != f'tx{round(currentX):04}y{round(currentY):04}':
        
        print(f'tx{round(currentX):04}y{round(currentY):04}')
        sendTestCoords(f'tx{round(currentX):04}y{round(currentY):04}')
        time.sleep(0.4)
    if sleepafter == True:
        time.sleep(8)
    sleepafter = False
    previous = f'tx{round(currentX):04}y{round(currentY):04}'

    if count == 1:
        time.sleep(8)

sendTestCoords(f'dx0090y0000')
time.sleep(1.2)

for i in gcode:


    i = str(i)
    i = i.strip()
    x = i.split()
    if len(x) > 2:
        if x[0] == 'G1' and x[1][0] == 'X':
            count += 1

            currentX = float(x[1][1:]) + 30
            currentY = float(x[2][1:]) + 300

            if currentX < minX:

                minX = currentX

            if currentX > maxX:
            
                maxX = currentX

            if currentY < minY:

                minY = currentY

            if currentY > maxY:

                maxY = currentY


            if previous != f'tx{round(currentX):04}y{round(currentY):04}':
                sendTestCoords(f'tx{round(currentX):04}y{round(currentY):04}')
                time.sleep(0.4)

            if sleepafter == True:
                time.sleep(5)
                sendTestCoords(f'dx0090y0000')
                time.sleep(3)

            sleepafter = False
            previous = f'tx{round(currentX):04}y{round(currentY):04}'

            if count == 1:
                time.sleep(3)
                sendTestCoords(f'dx0090y0000')
                time.sleep(3)

            previousX = currentX
            previousY = currentY

        if x[0] == ';':
            if x[1] == 'Rapid':
                sleepafter = True
                sendTestCoords(f'dx0090y0000')
                time.sleep(3)

print('maxX: ', maxX)
print('maxY: ', maxY)
print('minX: ', minX)
print('minY: ', minY)