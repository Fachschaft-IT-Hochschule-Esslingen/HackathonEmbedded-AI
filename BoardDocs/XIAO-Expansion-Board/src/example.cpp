// Startprojekt XIAO Expansion Board: OLED zeigt Text und zählt Tastendrücke,
// der Buzzer piept bei jedem Druck auf den User-Taster.
#include <Arduino.h>
#include <U8x8lib.h>

U8X8_SSD1306_128X64_NONAME_HW_I2C oled(U8X8_PIN_NONE);  // OLED an I2C (0x3C)

const int BUTTON_PIN = D1;  // User-Taster
const int BUZZER_PIN = D3;  // Buzzer (A3)
int presses = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  oled.begin();
  oled.setFont(u8x8_font_chroma48medium8_r);
  oled.drawString(0, 0, "Hallo Hackathon!");
  oled.drawString(0, 2, "Taster druecken");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {  // LOW = gedrückt
    presses++;
    oled.setCursor(0, 4);
    oled.print("Gedrueckt: ");
    oled.print(presses);
    tone(BUZZER_PIN, 1000, 50);
    delay(250);  // einfache Entprellung
  }
}
