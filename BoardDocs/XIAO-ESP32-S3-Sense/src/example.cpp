// Startprojekt XIAO ESP32-S3 Sense: LED blinkt, Serial Monitor zeigt den PSRAM
// (der PSRAM wird für die Kamera gebraucht und muss hier 8 MB anzeigen)
#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // User-LED an GPIO21
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  Serial.printf("Fachschaft IT | PSRAM: %u Bytes\n", ESP.getPsramSize());
  delay(1000);
}
