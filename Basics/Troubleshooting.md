# Troubleshooting: Es geht nicht. Was jetzt?

[← Grundlagen](README.md)

Erst mal: **Das ist normal.** Die meisten Fehler sind ein falsches Kabel oder eine falsche Einstellung. Geht diese Liste von oben nach unten durch.

## Board wird nicht erkannt / kein Port

| Ursache | Lösung |
|---|---|
| Reines Ladekabel ohne Datenleitungen | Anderes USB-Kabel nehmen |
| Treiber fehlt (ESP32 WROOM-32 mit CP2102) | [CP210x-Treiber](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers) installieren |
| Programm auf dem Board blockiert USB (XIAO, DFRobot) | **BOOT gedrückt halten, USB einstecken, loslassen** → Port taucht auf |
| Billiger USB-Hub / Adapter ohne eigenes Netzteil macht Probleme | Direkt am Laptop einstecken oder einen Hub **mit eigenem Netzteil** nehmen |

## Upload schlägt fehl

| Fehlermeldung | Lösung |
|---|---|
| `Failed to connect … No serial data received` / bleibt bei `Connecting…` hängen | Beim Upload **BOOT gedrückt halten**. Falscher Port gewählt? |
| `Port is busy` / `Access denied` | Seriellen Monitor oder ein anderes Programm schließen, das den Port nutzt |
| Kompilierfehler `… was not declared in this scope` | Bibliothek fehlt in `lib_deps`, eigene Funktion steht unterhalb der Stelle, an der sie benutzt wird, oder falsche `platformio.ini` |
| `multiple definition of setup` / `of loop` | Zwei `.cpp`-Dateien in `src/` enthalten `setup()` bzw. `loop()`. Eine davon löschen oder umbenennen (z. B. in `.txt`) |
| `region .* overflowed` / Programm zu groß | Nur bei Boards mit 4 MB Flash (XIAO C6, DFRobot, WROOM-32): in der `platformio.ini` `board_build.partitions = huge_app.csv` eintragen (3 MB statt 1,25 MB fürs Programm). Die XIAO S3 haben schon 3,3 MB |

## Upload klappt, aber nichts passiert

| Symptom | Lösung |
|---|---|
| Serieller Monitor bleibt leer | `monitor_speed` in der `platformio.ini` = Wert aus `Serial.begin()`? Nach dem Upload einmal **RESET** drücken und den Monitor neu öffnen. Beim DFRobot-Board die `platformio.ini` aus den Board-Docs nehmen (schaltet die USB-Ausgabe ein) |
| Board startet ständig neu, Meldung `Brownout detector was triggered` | Zu wenig Strom: anderes Kabel/USB-Port, Verbraucher (Motor, LEDs) extern versorgen |
| `Guru Meditation Error` / Absturz | Programmfehler, oft Zugriff auf nicht existierende Daten. Ausgabe davor lesen |
| Board startet nicht mehr nach dem Anschließen eines Moduls | Modul hängt an einem Strapping-Pin (ESP32: GPIO0, 2, 12, 15) → anderen Pin nehmen |

## Sensor liefert nichts oder Unsinn

1. **I2C-Scanner** laufen lassen (Code in [Bussysteme](Bussysteme.md)). Wird das Modul gefunden?
2. **VCC und GND** richtig? Leuchtet eine LED auf dem Modul?
3. **SDA/SCL** oder **TX/RX** vertauscht? (Bei UART müssen sie über Kreuz.)
4. **Richtige Pins im Code?** D-Nummern und GPIO-Nummern nicht verwechseln, siehe [Board-Docs](../BoardDocs/README.md).
5. **Steckbrett-Kontakt:** Kabel richtig drin? Stromschiene in der Mitte unterbrochen?
6. Analog-Wert immer 0 oder 4095? Pin ist kein ADC-Pin, oder beim ESP32 WROOM-32 ein ADC2-Pin bei aktivem WLAN.
7. **Multimeter** nehmen und messen: Liegt dort Spannung an, wo welche sein soll?

## Rauch, Geruch, heißes Bauteil

**Sofort Strom ab**, nicht anfassen, Bescheid sagen. Siehe [Dos & Don'ts](../DosAndDonts/README.md).

## Immer noch nicht?

- Fehlermeldung kopieren und eine KI fragen, zusammen mit eurem Code und dem Board-Namen.
- Ein anderes Team fragen.
- Zum Orga-Tisch kommen. Dafür sind wir da.
