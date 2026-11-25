// Startprojekt DFRobot ESP32-S3 LoRaWAN:
// Display zeigt "Fachschaft IT", LED blinkt, Taster Key1 wird angezeigt.
#include <Arduino.h>
#include <DFRobot_LoRaWAN.h>  // bringt auch den Display-Treiber mit

LCD_OnBoard screen;  // 0,96"-Farbdisplay, 160 x 80 Pixel (ST7735)

const int LED_PIN = LED_BUILTIN;  // GPIO21
const int KEY1_PIN = 18;          // Taster Key1

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(KEY1_PIN, INPUT_PULLUP);
  Serial.begin(115200);

  screen.begin();
  screen.fillScreen(COLOR_RGB565_BLACK);
  screen.setFont(&FreeMono9pt7b);
  screen.setTextColor(COLOR_RGB565_WHITE);
  screen.setCursor(4, 30);
  screen.print("Fachschaft IT");
}

void loop() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));

  bool pressed = digitalRead(KEY1_PIN) == LOW;
  Serial.printf("Fachschaft IT | Key1 %s\n", pressed ? "gedrueckt" : "frei");

  // Zweite Zeile: Zustand von Key1 (alte Zeile vorher schwarz übermalen)
  screen.fillRect(0, 45, 160, 35, COLOR_RGB565_BLACK);
  screen.setTextColor(pressed ? COLOR_RGB565_GREEN : COLOR_RGB565_LGRAY);
  screen.setCursor(4, 65);
  screen.print(pressed ? "Key1: an" : "Key1: aus");

  delay(500);
}
