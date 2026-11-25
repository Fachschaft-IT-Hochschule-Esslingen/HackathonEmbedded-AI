# Bussysteme: I2C, SPI, UART

[← Grundlagen](README.md)

Die meisten Sensoren und Displays sprechen nicht über einen einzelnen Pin, sondern über einen **Bus**, eine Art Mini-Netzwerk mit festen Leitungen. Welchen Bus ein Modul nutzt, steht auf der Platine oder in der Materialliste („I2C“, „SPI“).

## Überblick

| | **I2C** | **SPI** | **UART** |
|---|---|---|---|
| Leitungen | **SDA** (Daten), **SCL** (Takt) | **MOSI**, **MISO**, **SCK**, **CS** pro Gerät | **TX** (senden), **RX** (empfangen) |
| Geräte am Bus | viele (über Adresse) | viele (jedes mit eigenem CS-Pin) | genau eins |
| Tempo | langsam bis mittel | schnell | langsam bis mittel |
| Typisch bei uns | BME280, MPU-6050, OLED, BH1750, VL53L0X, MAX30102, DS3231, ADS1015 … | E-Paper, RFID RC522, LED-Matrix MAX7219, microSD, LoRa | GPS, zweites Board, Serieller Monitor |

Die passenden Pins eures Boards findet ihr in den [Board-Docs](../BoardDocs/README.md).

## I2C: der Standard für Sensoren

```
Board            Sensor 1        Sensor 2
3V3  ──────────── VCC ─────────── VCC
GND  ──────────── GND ─────────── GND
SDA  ──────────── SDA ─────────── SDA
SCL  ──────────── SCL ─────────── SCL
```

- **4 Kabel**, und beliebig viele Sensoren hängen parallel an denselben zwei Datenleitungen.
- Jedes Gerät hat eine **Adresse** (z. B. OLED `0x3C`, BME280 `0x76`). Zwei Geräte mit **gleicher Adresse** am selben Bus vertragen sich nicht. Dann hilft ein Adress-Jumper auf dem Modul oder der **I2C-Multiplexer TCA9548A**.
- I2C braucht **Pull-up-Widerstände** an SDA und SCL. Fast alle Breakout-Module haben die schon drauf.
- **Erst scannen, dann programmieren:** Der folgende Sketch zeigt, welche Adressen am Bus antworten. Taucht nichts auf, stimmt die Verkabelung nicht.

```cpp
#include <Arduino.h>
#include <Wire.h>
void setup() {
  Serial.begin(115200);
  Wire.begin();                 // nutzt die Standard-SDA/SCL-Pins des Boards
  delay(1000);
  for (byte a = 1; a < 127; a++) {
    Wire.beginTransmission(a);
    if (Wire.endTransmission() == 0) Serial.printf("Gefunden: 0x%02X\n", a);
  }
  Serial.println("Scan fertig");
}
void loop() {}
```

## SPI: schnell, aber mehr Kabel

- **MOSI** (Master Out → Daten zum Modul), **MISO** (Master In ← Daten vom Modul), **SCK** (Takt) sind für alle Geräte gemeinsam.
- Jedes Gerät bekommt einen eigenen **CS**-Pin (Chip Select, manchmal **SS** oder **CE** genannt). Ist CS auf LOW, ist dieses Gerät gemeint.
- Manche Module beschriften anders: **DIN / SDI** = MOSI, **DOUT / SDO** = MISO, **CLK / SCL** = SCK. Auch Displays mit „SCL/SDA“-Beschriftung können SPI sein, wenn zusätzlich **DC**, **RST** oder **CS** dabei sind.

## UART: zwei Geräte unterhalten sich

- **Über Kreuz verbinden:** TX des einen an **RX** des anderen und umgekehrt. Plus GND.
- Beide Seiten brauchen die gleiche **Baudrate** (z. B. 9600 oder 115200).
- Der **Serial Monitor** in PlatformIO (🔌 in der Statusleiste) ist auch UART (über USB). `Serial.println()` ist euer wichtigstes Debug-Werkzeug.

## Einzelne Pins: auch das gibt es

Manche Module nutzen eigene Protokolle über **einen** Datenpin:
- **DHT22**, **DS18B20** (1-Wire): eigene Bibliothek, oft mit 10-kΩ-Pull-up am Datenpin.
- **NeoPixel / WS2812**: ein Datenpin, Bibliothek *Adafruit NeoPixel*. Bei mehreren LEDs eigene 5-V-Versorgung (siehe [Dos & Don'ts](../DosAndDonts/README.md)).
- **TM1637** (7-Segment): zwei Pins (CLK, DIO), sieht aus wie I2C, **ist aber keins**. Eigene Bibliothek nutzen.

## 5-V-Module an 3,3-V-Boards

Einige Module laufen mit 5 V. Dann gibt es zwei Probleme:

- **Modul → Board:** Gibt das Modul ein Signal zurück, kann das bis 5 V haben und den GPIO zerstören.
  - Digitale Signale: **Pegelwandler** (liegt beim Material) dazwischen. LV-Seite an 3,3 V und das Board, HV-Seite an 5 V und das Modul.
  - Analoge Signale (z. B. MQ-135 Ausgang A0): **Spannungsteiler** aus zwei Widerständen, z. B. 10 kΩ vom Sensor-Ausgang zum Pin und 20 kΩ vom Pin nach GND, damit aus max. 5 V höchstens 3,3 V werden. Der Pegelwandler eignet sich dafür nicht.
- **Board → Modul:** Manche 5-V-Chips (z. B. LED-Matrix MAX7219) erkennen 3,3 V nicht zuverlässig als HIGH. Wenn es spinnt, hilft auch hier der Pegelwandler.
