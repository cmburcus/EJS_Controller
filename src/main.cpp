/**
 * This piece of code is the controller of the EJS
 * system. It will determine when a race starts,
 * when it should be reset, etc.
 */

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <constants.h>
#include <helpers.h>
#include <radio.h>

void setup() {
  Serial.begin(9600);
  
  initializePins();
  initializeRadio();
}

void loop() {  
  handleRadioSignals();
}
