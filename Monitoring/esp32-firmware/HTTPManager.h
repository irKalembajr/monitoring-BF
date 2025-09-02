#ifndef HTTP_MANAGER_H
#define HTTP_MANAGER_H

#include <Arduino.h>

void sendRelayState(bool relay1, bool relay2, bool localSwitch, const String& reason) {
  Serial.println("Sending state: relay1=" + String(relay1) + " relay2=" + String(relay2) + " switch=" + String(localSwitch) + " reason=" + reason);
}

void httpManagerLoop(bool relay1, bool relay2, bool localSwitch) {
  // Stub loop
}

#endif