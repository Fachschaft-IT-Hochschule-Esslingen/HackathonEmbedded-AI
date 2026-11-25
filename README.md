# Embedded AI Hackathon

Fachschaft IT, Hochschule Esslingen

| | |
|---|---|
| **Wann** | Freitag, **04.12.2026 ab 18:00 Uhr**, Ende offen (die ganze Nacht) |
| **Wo** | Räume **F1.-208** und **F1.-110** |
| **Aufgabe** | Frei: Baut, was euch Spaß macht. Hauptsache, es steckt ein bisschen Embedded und KI drin |
| **Teams** | 2–3 Personen. Ohne Team anmelden geht auch, wir vermitteln |
| **Competition** | Kick-off-Pitch ca. 19–20 Uhr · Zwischenpitch ca. 23–24 Uhr · eine Woche Werkeln · Abgabe **Fr, 11.12.2026** in der Fachschaft |
| **Mitbringen** | Laptop + Ladekabel, **USB-C-Datenkabel** (kein reines Ladekabel!) |
| **Infos & Anmeldung** | [Hackathon-FAQ](https://fachschaft-it-hochschule-esslingen.github.io/Events/hackathon/faq.html) · [Hardware-Liste](https://fachschaft-it-hochschule-esslingen.github.io/Events/hackathon/hardware.html) · fachschaft.it@hs-esslingen.de |

> **Vor dem Event:** VS Code + PlatformIO installieren und einmal ein Projekt bauen ([Erste Schritte](GettingStarted/README.md)), außerdem einen KI-Assistenten beantragen. Die kostenlosen Studierenden-Zugänge brauchen **bis zu einer Woche** (siehe [FAQ](https://fachschaft-it-hochschule-esslingen.github.io/Events/hackathon/faq.html)).

## 1. Board-Docs

Pinouts, wichtige Pins, offizielle Dokus und eine fertige `platformio.ini` für jedes Board.
→ **[BoardDocs](BoardDocs/README.md)**

| Board | Stück |
|---|---:|
| [Seeed XIAO ESP32-S3](BoardDocs/XIAO-ESP32-S3/README.md) | 10 |
| [Seeed XIAO ESP32-S3 Sense](BoardDocs/XIAO-ESP32-S3-Sense/README.md) (Kamera + Mikrofon) | 8 |
| [Seeed XIAO ESP32-C6](BoardDocs/XIAO-ESP32-C6/README.md) | 4 |
| [Seeed XIAO Expansion Board](BoardDocs/XIAO-Expansion-Board/README.md) | 1 |
| [DFRobot ESP32-S3 LoRaWAN](BoardDocs/DFRobot-ESP32-S3-LoRaWAN/README.md) | 3 |
| [ESP32 WROOM-32](BoardDocs/ESP32-WROOM-32/README.md) | 5 |
| [ATtiny85](BoardDocs/ATtiny85/README.md) ⚠️ *Advanced* | 10 |

## 2. Dos & Don'ts

Sicherheitsregeln zu Spannung, Laptop & USB, Verdrahtung, Akkus und Löten als Tabelle.
→ **[DosAndDonts](DosAndDonts/README.md)**

> **Die wichtigsten Regeln:** Alle Boards arbeiten mit **3,3 V**, 5 V an einem GPIO = Board kaputt.
> Boards im Betrieb über ein **externes USB-Netzteil** versorgen, nicht über den Laptop.

## 3. Erste Schritte

VS Code + PlatformIO installieren, Projekt anlegen, erste LED blinken lassen.
→ **[GettingStarted](GettingStarted/README.md)**

## 4. Grundlagen

Für alle, die mit null Elektronik-Wissen starten.
→ **[Basics](Basics/README.md)**: [Grundbegriffe](Basics/Grundbegriffe.md) · [Bussysteme](Basics/Bussysteme.md) · [Troubleshooting](Basics/Troubleshooting.md) · [Glossar](Basics/Glossar.md)

## 5. Ressourcen

Git-Cheatsheet und -Buch, PlatformIO, ESP32-Tutorials, Elektronik lernen, Simulator, KI auf dem Mikrocontroller.
→ **[Resources](Resources/README.md)**

## 6. Material & Ausleihe

- [Materialliste](MaterialsList/hackathon-stueckliste.csv): alle Bauteile mit Shop- und Doku-Links
- [Ausleihschein](BorrowingPaper/Hackathon_Verleihformular.html): im Browser öffnen, Teile anhaken, als PDF drucken
- [Eröffnungspräsentation](OpeningPresentation/main.tex): LaTeX-Quelle der Folien
