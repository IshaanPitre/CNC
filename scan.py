import bluetooth
import time


devices = bluetooth.discover_devices(lookup_names = True, lookup_class = True)
for i in devices:
    print(i)