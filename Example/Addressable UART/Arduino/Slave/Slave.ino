/*
 * Wiring diagram 
 * 
 * | Master |     | Slave |
 * |  GND   | <-> |  GND  |
 * |   RX   | <-> |  TX   |
 * |   TX   | <-> |  RX   |
 */

#include "Arduino.h"

const uint8_t addr = 0x05;
uint8_t buffer[10];

bool active = false;

const uint8_t cmd = 0x35;
const uint8_t ack = 0xAA;

void rx_callback(){
  if(!active){
    if(Serial.peek() == addr){
      active = true;
      Serial.wake();
    }
    else{
      Serial.read();
      Serial.mute();
    }
  } 
}

void setup ()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin (4800, SERIAL_8N1, true);
  Serial.wake();
  Serial.attachInterrupt(rx_callback);

}  // end of setup

void loop ()
{
  if(Serial.available()){

    delay(100);

    active = false;
    Serial.mute();

    int i = 0;
    while(Serial.available()){
      buffer[i++] = Serial.read();
    }

    // Read the second element because the first one is the address
    if(buffer[1] == cmd){
      Serial.write(ack);
      //Serial.print("Ack");
  
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  
}  // end of loop
