# Arduino-Extended-UART
Patch for the official Arduino HardwareSerial adding support for 9 bit address mode and ISR callbacks.

# Overview
Some people already implemented these features like Nick Gammon did for the 9 bit (https://forum.arduino.cc/index.php?topic=91377.0) and SlashDevin (https://github.com/SlashDevin/NeoHWSerial) for the UART ISR, so I'm not reinventing the wheel, but I haven't seen both features together. On the other hand it seems that Arduino team is not willing to add this features to the official releases at the moment (https://github.com/arduino/ArduinoCore-avr/pull/299).

# Usage
Get the following files from the "Driver" folder:
- HardwareSerial.cpp
- HardwareSerial.h
- HardwareSerial_Private.h

Go to ...\Arduino\hardware\arduino\avr\cores\arduino and replace the existing files.

Your previous sketches should not be affected.

# Examples

The repo provides some examples:
- Arduino Master
- Arduino Slave
- Python Master
