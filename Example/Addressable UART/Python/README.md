# 9-bit addressable UART terminal

This is a simple implementation of a terminal that can be used to communicate with different targets in 9-bit mode. Right now it only acts as a master.

The terminal is based in the pySerial module, which unfortunately doesn't have direct support for 9-bit frames. However it allows the selection of different parity modes:
- Odd
- Even
- Mark (always 1)
- Space (always 0)

Using this feature we can emulate the 9-bit frames, selecting which parity we want to use in each case. When an address is transferred the parity is set to MARK and when data is transferred the parity is set to SPACE.

Tested with the following USB-UART converters:
- FTDI
- CH340

# Usage

You can use this script in combination with the Arduino Slave sketch. Remember to indicate the proper COM port before running the script.

1) Provide the destination addr in hex
2) Provide the desired hex string
