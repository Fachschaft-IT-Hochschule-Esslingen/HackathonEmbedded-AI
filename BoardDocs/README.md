# Board-Docs

Pinouts, wichtige Pins und offizielle Dokus zu allen Mikrocontrollern, die ihr beim Hackathon ausleihen könnt.

> **Gilt für alle Boards hier:** Die Logik arbeitet mit **3,3 V**. 5 V an einem GPIO zerstört das Board.
> Mehr dazu in den [Dos & Don'ts](../DosAndDonts/README.md).

## Übersicht

| Board | Chip | Stück | Wofür besonders gut | PlatformIO |
|---|---|---:|---|---|
| [Seeed XIAO ESP32-S3](XIAO-ESP32-S3/README.md) | ESP32-S3 | 10 | Klein, WLAN + BLE, viel Rechenleistung für KI | [platformio.ini](XIAO-ESP32-S3/platformio.ini) |
| [Seeed XIAO ESP32-S3 Sense](XIAO-ESP32-S3-Sense/README.md) | ESP32-S3 | 8 | Kamera + Mikrofon + microSD, Bild-/Audio-KI | [platformio.ini](XIAO-ESP32-S3-Sense/platformio.ini) |
| [Seeed XIAO ESP32-C6](XIAO-ESP32-C6/README.md) | ESP32-C6 (RISC-V) | 4 | Wi-Fi 6, Zigbee, Thread (Smart Home) | [platformio.ini](XIAO-ESP32-C6/platformio.ini) |
| [Seeed XIAO Expansion Board](XIAO-Expansion-Board/README.md) | – (Aufsteckboard) | 1 | OLED, Uhr, Buzzer, Taster, microSD, Grove | [platformio.ini](XIAO-Expansion-Board/platformio.ini) |
| [DFRobot ESP32-S3 LoRaWAN](DFRobot-ESP32-S3-LoRaWAN/README.md) | ESP32-S3 + SX1262 | 3 | Funk über Kilometer (LoRa 868 MHz), Farbdisplay | [platformio.ini](DFRobot-ESP32-S3-LoRaWAN/platformio.ini) |
| [ESP32 WROOM-32 DevBoard](ESP32-WROOM-32/README.md) | ESP32 | 5 | Viele Pins, steckbrettfreundlich | [platformio.ini](ESP32-WROOM-32/platformio.ini) |
| [ATtiny85](ATtiny85/README.md) ⚠️ *Advanced* | ATtiny85 (AVR) | 10 | Winziger 8-Pin-Chip für einfache Aufgaben, braucht ein zweites Board als Programmer | [platformio.ini](ATtiny85/platformio.ini) |

Jedes Board hat einen eigenen Ordner mit Doku, Pinout-Bildern und einer fertigen **`platformio.ini`**. Wie ihr sie benutzt, steht in [Erste Schritte](../GettingStarted/README.md).

## Pinout lesen in 30 Sekunden

- **Dx / Ax**: Arduino-Name des Pins (digital / analog). Den benutzt ihr im Code, z. B. `digitalWrite(D2, HIGH)`.
- **GPIOx**: Name des Pins im Chip. Auf ESP32-Boards funktioniert im Code auch einfach die Nummer, z. B. `pinMode(5, OUTPUT)` für GPIO5.
- **SDA / SCL**: I2C-Bus, **MOSI / MISO / SCK / CS**: SPI-Bus, **TX / RX**: UART (serielle Schnittstelle). Erklärt in [Bussysteme](../Basics/Bussysteme.md).
- **3V3**: 3,3 V **Ausgang** für Sensoren. **5V / VBUS / VIN**: 5 V direkt vom USB. **GND**: Masse.
- **BOOT / RESET**: Taster. Mit BOOT bringt ihr das Board in den Flash-Modus, falls der Upload hängt.

## Bildquellen

Die Pinout-Grafiken stammen von den Herstellern bzw. Projekten und sind hier nur verkleinert abgelegt:
Seeed Studio Wiki (XIAO-Boards, Expansion Board), DFRobot Wiki (LoRaWAN-Board), Espressif (ESP32-DevKitC),
Spence Konde / [ATTinyCore](https://github.com/SpenceKonde/ATTinyCore) (ATtiny85).
