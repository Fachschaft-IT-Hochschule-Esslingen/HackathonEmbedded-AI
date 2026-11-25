// Startprojekt XIAO ESP32-C6: eingebaute LED blinkt, Ausgabe im Serial Monitor
#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // User-LED an GPIO15
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  Serial.println("XIAO ESP32-C6 lebt!");
  delay(500);
}
