import serial
from time import sleep

ser = serial.Serial()
ser.baudrate = 4800
ser.port = 'XXX' # Port
ser.open() # This restarts the USB-UART converter

while True:
    addr = input("Destination address: ")
    data = input("Data: ")

    ser.parity = serial.PARITY_MARK
    sleep(0.02)
    ser.write(bytes.fromhex(addr))

    ser.parity = serial.PARITY_SPACE
    sleep(0.02)
    ser.write(bytes.fromhex(data))

    sleep(0.2)

    bs = ser.in_waiting
    if bs > 0:
        reply = ser.read(bs)
        print("Raw: " + reply.hex())
        print("ASCII: " + str(reply))

    if input("Repeat? (y/n): ") != 'y':
        break

print("Thank you, bye!")
ser.close()
