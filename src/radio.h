#ifndef RADIO_H
#define RADIO_H

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <constants.h>

// Define communication
RF24 radio(7, 8); // CSN, CE
const byte address[6] = "P_EJS"; // Primary EJS

/**
 * Initializes the radio to be able to listen
 */
void initializeRadio() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

/**
 * Sends the approprivate radio signal based on input
 */
void handleRadioSignals() {
  // Start the race
  if (digitalRead(START_BTN) == LOW) {
    radio.write(&START_RACE_SIGNAL, sizeof(START_RACE_SIGNAL));
  }

  // Reset the race
  if (digitalRead(RESET_BTN) == LOW) {
    radio.write(&RESET_RACE_SIGNAL, sizeof(RESET_RACE_SIGNAL));
  }

  // Trigger fault LEFT lane
  if (digitalRead(FAULT_LEFT_BTN) == LOW) {
    radio.write(&FAULT_LEFT_SIGNAL, sizeof(FAULT_LEFT_SIGNAL));
  }

  // Trigger fault RIGHT lane
  if (digitalRead(FAULT_RIGHT_BTN) == LOW) {
    radio.write(&FAULT_RIGHT_SIGNAL, sizeof(FAULT_RIGHT_SIGNAL));
  }
}

#endif