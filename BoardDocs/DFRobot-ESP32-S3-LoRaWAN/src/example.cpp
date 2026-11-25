// Startprojekt DFRobot ESP32-S3 LoRaWAN: LED blinkt, Taster Key1 wird gelesen
#include <Arduino.h>

const int LED_PIN = 21;   // Onboard-LED
const int KEY1_PIN = 18;  // Taster Key1

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(KEY1_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  Serial.printf("DFRobot ESP32-S3 lebt! Key1 %s\n", digitalRead(KEY1_PIN) == LOW ? "gedrueckt" : "frei");
  delay(500);
}
