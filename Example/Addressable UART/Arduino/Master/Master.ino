/*
 * Wiring diagram 
 * 
 * | Master |     | Slave |
 * |  GND   | <-> |  GND  |
 * |   RX   | <-> |  TX   |
 * |   TX   | <-> |  RX   |
 */

#include "Arduino.h"

const uint8_t slave_addr = 0x05;
uint8_t buffer[10];

const uint8_t cmd = 0x35;
const uint8_t ack = 0xAA;

void setup ()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin (4800, SERIAL_8N1, true);
}  // end of setup

void loop ()
{
  Serial.write9bit(0x0100 | slave_addr);
  Serial.write(cmd);

  delay(200);

  if(Serial.available()){

    delay(100);

    int i = 0;
    while(Serial.available()){
      buffer[i++] = Serial.read();
    }

    // Read the first element because no address was sent
    if(buffer[0] == ack){  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
    }
  }

  delay(5000);
  
}  // end of loop
