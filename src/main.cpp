/**
 * This piece of code is the controller of the EJS
 * system. It will determine when a race starts,
 * when it should be reset, etc.
 */

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Define communication
RF24 radio(7, 8); // CSN, CE
const byte address[6] = "P_EJS"; // Primary EJS


// Define buttons
#define START_BTN 2
#define RESET_BTN 3
#define FAULT_LEFT_BTN 4
#define FAULT_RIGHT_BTN 5

// Comminucation constants
#define START_RACE_SIGNAL "START"
#define RESET_RACE_SIGNAL "RESET"
#define FAULT_LEFT_SIGNAL "FAULT"
#define FAULT_RIGHT_SIGNAL "FAULT"

// Race specific
bool isRaceStarted = false;

void setup() {
  Serial.begin(9600);
  
  // Define pin modes
  pinMode(START_BTN, INPUT_PULLUP);
  pinMode(RESET_BTN, INPUT_PULLUP);
  pinMode(FAULT_LEFT_BTN, INPUT_PULLUP);
  pinMode(FAULT_RIGHT_BTN, INPUT_PULLUP);

  // Communication
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {  
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
