// Startprojekt ATtiny85: LED an PB4 (Beinchen 3) blinkt im Sekundentakt.
// LED mit 220-Ohm-Widerstand von Beinchen 3 nach GND.
// Blinkt sie etwa 8-mal langsamer, wurden die Fuses noch nicht geschrieben (pio run -t fuses).
#include <Arduino.h>

const int LED_PIN = 4;  // PB4

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
