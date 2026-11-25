// Startprojekt ESP32 WROOM-32: LED an GPIO2 blinkt, Ausgabe im Serial Monitor.
// Das Board hat keine sichere eingebaute User-LED: eigene LED mit 220-Ohm-Widerstand
// von GPIO2 nach GND anschließen.
#include <Arduino.h>

const int LED_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  Serial.println("ESP32 WROOM-32 lebt!");
  delay(500);
}
