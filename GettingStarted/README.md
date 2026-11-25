# Erste Schritte: vom leeren Laptop bis zur blinkenden LED

Wir arbeiten mit **VS Code + PlatformIO**. Diese Anleitung bringt euch bis zum ersten eigenen Programm auf dem Board.

> [!TIP]
> Schritt 1 und 2 **zu Hause im WLAN** erledigen. Beim ersten Bauen lädt PlatformIO mehrere hundert MB herunter.

## 1. VS Code und PlatformIO installieren

1. [Visual Studio Code](https://code.visualstudio.com/) installieren.
2. In VS Code die Erweiterungen öffnen (`Strg+Shift+X`, macOS `Cmd+Shift+X`), nach **PlatformIO IDE** suchen und installieren.
3. Warten, bis unten rechts „PlatformIO installed“ erscheint, dann VS Code neu starten. Links gibt es jetzt ein **Ameisenkopf-Symbol**, das ist PlatformIO.

## 2. Projekt anlegen

Jedes Board hat in den [Board-Docs](../BoardDocs/README.md) einen Ordner, der schon ein **fertiges Startprojekt** ist: `platformio.ini` + `src/example.cpp` mit einem kleinen Testprogramm.

1. Den Ordner eures Boards an einen eigenen Ort kopieren (z. B. `Dokumente\hackathon\mein-projekt`) und umbenennen. Nötig sind nur `platformio.ini` und `src/`, README und Bilder könnt ihr weglassen.
2. In VS Code *Datei → Ordner öffnen* und den kopierten Ordner wählen. PlatformIO erkennt das Projekt automatisch.

| Euer Board | Startprojekt | Was das Testprogramm macht |
|---|---|---|
| XIAO ESP32-S3 | [XIAO-ESP32-S3](../BoardDocs/XIAO-ESP32-S3/) | User-LED blinkt, „Fachschaft IT“ im Serial Monitor |
| XIAO ESP32-S3 Sense | [XIAO-ESP32-S3-Sense](../BoardDocs/XIAO-ESP32-S3-Sense/) | LED blinkt, Serial Monitor zeigt den PSRAM (muss 8 MB sein) |
| XIAO ESP32-C6 | [XIAO-ESP32-C6](../BoardDocs/XIAO-ESP32-C6/) | User-LED blinkt, „Fachschaft IT“ im Serial Monitor |
| XIAO + Expansion Board | [XIAO-Expansion-Board](../BoardDocs/XIAO-Expansion-Board/) | OLED zeigt „Fachschaft IT“, Taster zählt hoch, Buzzer piept |
| DFRobot ESP32-S3 LoRaWAN | [DFRobot-ESP32-S3-LoRaWAN](../BoardDocs/DFRobot-ESP32-S3-LoRaWAN/) | Display zeigt „Fachschaft IT“, LED blinkt, Display und Serial Monitor zeigen Taster Key1 |
| ESP32 WROOM-32 | [ESP32-WROOM-32](../BoardDocs/ESP32-WROOM-32/) | eigene LED an GPIO2 blinkt (mit 220 Ω nach GND) |
| ATtiny85 ⚠️ Advanced | eigener Ablauf, siehe [ATtiny85](../BoardDocs/ATtiny85/README.md) | |

> **Lieber ein neues Projekt über den Assistenten?** Geht auch: *PIO Home → New Project*, beliebiges Board, Framework Arduino. Danach die `platformio.ini` **komplett durch die Datei eures Boards ersetzen**. Die vom Assistenten nutzt eine ältere ESP32-Plattform, die z. B. den XIAO ESP32-C6 nicht kennt. Mit unserer Datei haben alle Teams dieselbe Version (pioarduino, Arduino-Kern 3.3).

Beim ersten Öffnen lädt PlatformIO die Plattform und die Compiler herunter. Das dauert ein paar Minuten (unten rechts läuft ein Fortschritt). **Beim allerersten Mal nur ein ESP32-Projekt gleichzeitig bauen**, sonst kommen sich die Downloads in die Quere.

### Was liegt wo?

```
mein-projekt/
├── platformio.ini   ← Board, Einstellungen, Bibliotheken
├── src/
│   └── example.cpp  ← euer Code (Startprogramm, einfach weiterbearbeiten)
├── include/         ← eigene Header-Dateien (.h)
└── lib/             ← eigene Bibliotheken (selten nötig)
```

## 3. Das erste Programm

Das Testprogramm in `src/example.cpp` ist euer Startpunkt. So sieht es z. B. beim XIAO ESP32-S3 aus:

```cpp
#include <Arduino.h>   // in PlatformIO immer als erste Zeile

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // eingebaute LED
  Serial.begin(115200);          // muss zu monitor_speed in der platformio.ini passen
}

void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));  // LED umschalten
  Serial.println("Fachschaft IT");
  delay(500);
}
```

`setup()` läuft einmal beim Start, `loop()` danach immer wieder. Ändert ihr z. B. `delay(500)` auf `delay(100)`, blinkt die LED schneller.

> Unterschied zur Arduino IDE: In einer `.cpp`-Datei muss eine eigene Funktion **oberhalb** der Stelle stehen, an der ihr sie benutzt (oder vorher deklariert werden). Sonst meldet der Compiler `was not declared in this scope`.

> **Nur ein `setup()` und ein `loop()` pro Projekt.** PlatformIO kompiliert jede `.cpp`-Datei in `src/`. Wollt ihr neu anfangen, ersetzt den Inhalt von `example.cpp` (oder löscht die Datei), statt eine zweite Datei mit `setup()` daneben zu legen. Sonst meldet der Linker `multiple definition of setup`.

## 4. Bauen, hochladen, Ausgabe ansehen

Unten in der blauen Statusleiste:

| Symbol | Funktion |
|---|---|
| ✓ | **Build**: kompilieren, ohne hochzuladen. Gut, um Fehler zu finden |
| → | **Upload**: kompilieren und aufs Board schreiben |
| 🔌 | **Serial Monitor**: Ausgaben von `Serial.println()` ansehen |
| 🗑 | **Clean**: Build-Dateien löschen, wenn sich etwas „komisch“ verhält |

1. Board mit einem **USB-Datenkabel** anschließen (reine Ladekabel funktionieren nicht).
2. **→ Upload** drücken. PlatformIO findet den Port meistens selbst. Am Ende steht `SUCCESS`.
3. **🔌 Serial Monitor** öffnen. Dort sollte die Ausgabe des Testprogramms erscheinen, also „Fachschaft IT“.

**Mehrere Boards angeschlossen?** In der `platformio.ini` den Port festlegen, z. B. `upload_port = COM5` und `monitor_port = COM5`. Welche Ports es gibt, zeigt *PIO Home → Devices*.

**Kein Port / Upload hängt bei `Connecting...`?**
- XIAO / DFRobot: **BOOT-Taste gedrückt halten, USB einstecken, loslassen**, nochmal Upload.
- ESP32 WROOM-32: [CP210x-Treiber](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers) installieren, beim Upload BOOT gedrückt halten.
- Anderes Kabel probieren. Mehr in [Troubleshooting](../Basics/Troubleshooting.md).

> [!IMPORTANT]
> Der Laptop ist zum **Hochladen und Debuggen** da. Sobald Motoren, LED-Streifen, Lautsprecher oder ein Akku an der Schaltung hängen, versorgt sie über ein **externes USB-Netzteil** bzw. eine Powerbank, nicht über den Laptop. Ein Fehler in der Schaltung kann sonst den USB-Port eures Laptops beschädigen. Siehe [Dos & Don'ts](../DosAndDonts/README.md#laptop--usb).

## 5. Bibliotheken einbinden

Für fast jeden Sensor gibt es eine fertige Bibliothek. Zwei Wege:

- **Direkt in die `platformio.ini`** (empfohlen, dann hat das ganze Team dieselben):
  ```ini
  lib_deps =
      adafruit/Adafruit BME280 Library
      adafruit/Adafruit SSD1306
  ```
- Oder: *PIO Home → Libraries* → suchen → **Add to Project**. Das trägt die Zeile automatisch ein.

Die meisten Bibliotheken bringen Beispiele mit (im Ordner `.pio/libdeps/<env>/<Bibliothek>/examples`). **Mit dem Beispiel anfangen, dann umbauen.** Die Doku-Links in der [Materialliste](../MaterialsList/hackathon-stueckliste.csv) führen meistens zu einer Anleitung mit Schaltplan und Code.

## 6. Projekt mit Git teilen

PlatformIO legt automatisch eine `.gitignore` an, die den Build-Ordner `.pio/` ausschließt. Den Code bitte als Git-Repository verwalten, das braucht ihr auch für die Abgabe. Einstieg in Git: [Ressourcen](../Resources/README.md#git).

## 7. Wie geht's weiter?

- Pinout eures Boards: [Board-Docs](../BoardDocs/README.md)
- Was ist eigentlich Spannung, Strom, ein Pull-up? → [Grundbegriffe](../Basics/Grundbegriffe.md)
- Sensor anschließen per I2C / SPI / UART → [Bussysteme](../Basics/Bussysteme.md)
- Es geht nicht → [Troubleshooting](../Basics/Troubleshooting.md)
