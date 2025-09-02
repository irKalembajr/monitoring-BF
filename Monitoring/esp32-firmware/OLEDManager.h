#ifndef OLED_MANAGER_H
#define OLED_MANAGER_H

#include <Arduino.h>

void initOLED() {
  // Initialisation fictive
}

void displayMessage(const String& title, const String& msg) {
  Serial.println(title + ": " + msg);
}

#endif