// Startprojekt XIAO ESP32-S3: eingebaute LED blinkt, Ausgabe im Serial Monitor
#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // User-LED an GPIO21
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  Serial.println("Fachschaft IT");
  delay(500);
}
