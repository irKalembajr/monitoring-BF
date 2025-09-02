#include "WiFiManager.h"
#include "OLEDManager.h"
#include "GlobalVariables.h"
#include "HTTPManager.h"

bool relay1State = false;
bool relay2State = false;

static bool lastSwitchLevel = HIGH;   // INPUT_PULLUP, HIGH=repos
static unsigned long lastToggleMs = 0;
static const unsigned long DEBOUNCE_MS = 250;

void setup() {
  Serial.begin(115200);

  // Écran OLED
  initOLED();
  displayMessage("Systeme", "Demarrage...");

  // Relais
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);

  // Interrupteur local
  pinMode(SWITCH1, INPUT_PULLUP);

  // WiFi
  setupWiFiManager();

  // Envoi initial au dashboard
  delay(500);
  sendRelayState(relay1State, relay2State, (digitalRead(SWITCH1) == LOW), "boot");
}

void loop() {
  wifiManagerLoop();

  // Lecture interrupteur + anti-rebond
  bool sw = (digitalRead(SWITCH1) == LOW);
  unsigned long now = millis();
  if (sw != (lastSwitchLevel == LOW) && (now - lastToggleMs > DEBOUNCE_MS)) {
    lastToggleMs = now;
    lastSwitchLevel = sw ? LOW : HIGH;

    if (sw) {
      relay1State = !relay1State;
      digitalWrite(RELAY1, relay1State ? HIGH : LOW);
      displayMessage("Relais1", relay1State ? "ON" : "OFF");

      sendRelayState(relay1State, relay2State, true, "switch_toggle");
    }
  }

  httpManagerLoop(relay1State, relay2State, (digitalRead(SWITCH1) == LOW));
}