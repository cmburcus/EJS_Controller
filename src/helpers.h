#ifndef HELPERS_H
#define HELPERS_H

#include <Arduino.h>

#include <constants.h>

/**
 * Initializes the Arduino pins
 */
void initializePins() {
  pinMode(START_BTN, INPUT_PULLUP);
  pinMode(RESET_BTN, INPUT_PULLUP);
  pinMode(FAULT_LEFT_BTN, INPUT_PULLUP);
  pinMode(FAULT_RIGHT_BTN, INPUT_PULLUP);
}

#endif