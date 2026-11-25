# Ressourcen

Gute Seiten, Bücher und Werkzeuge zum Nachschlagen und Weiterlernen. Alles kostenlos.

## Git

Euren Code verwaltet ihr mit Git, das braucht ihr auch für die Abgabe.

| Ressource | Wofür |
|---|---|
| [GitHub Git Cheat Sheet (deutsch)](https://training.github.com/downloads/de/github-git-cheat-sheet/) | Die wichtigsten Befehle auf einer Seite. **Ausdrucken lohnt sich** |
| [Pro Git (Buch, deutsch)](https://git-scm.com/book/de/v2) | Das Standardwerk. Kapitel 1–3 reichen für den Hackathon |
| [Learn Git Branching](https://learngitbranching.js.org/?locale=de_DE) | Interaktives Spiel, erklärt Branches und Merges visuell |
| [Oh Shit, Git!?!](https://ohshitgit.com/de) | „Ich hab was kaputt gemacht, wie mache ich das rückgängig?“ |
| [Git in VS Code](https://code.visualstudio.com/docs/sourcecontrol/overview) | Git per Klick statt im Terminal |
| [.gitignore erklärt](https://docs.github.com/de/get-started/git-basics/ignoring-files) | Welche Dateien nicht ins Repo gehören |

**Minimal-Workflow fürs Team:**

```bash
git clone <url>          # Repo einmal herunterladen
git pull                 # vor dem Arbeiten: Änderungen der anderen holen
git add .                # Änderungen vormerken
git commit -m "OLED zeigt Temperatur an"   # kleiner Schritt, sprechende Nachricht
git push                 # hochladen
```

> [!WARNING]
> **Keine Schlüssel ins Repo!** WLAN-Passwörter und API-Keys (z. B. für Chat AI) gehören in eine eigene Datei wie `include/secrets.h`, die in der `.gitignore` steht. Was einmal auf GitHub war, gilt als öffentlich.

## PlatformIO

| Ressource | Wofür |
|---|---|
| [PlatformIO-Doku](https://docs.platformio.org/en/latest/) | Alle Optionen der `platformio.ini` |
| [PlatformIO Registry](https://registry.platformio.org/) | Bibliotheken suchen, Namen für `lib_deps` |
| [pioarduino](https://github.com/pioarduino/platform-espressif32) | Die ESP32-Plattform, die wir benutzen |

## ESP32 & Arduino programmieren

| Ressource | Wofür |
|---|---|
| [Arduino-ESP32-Doku (Espressif)](https://docs.espressif.com/projects/arduino-esp32/en/latest/) | WLAN, Bluetooth, Deep Sleep, I2S … für ESP32 |
| [Arduino Language Reference](https://docs.arduino.cc/language-reference/) | `digitalWrite`, `analogRead`, `millis` & Co. |
| [Random Nerd Tutorials: ESP32](https://randomnerdtutorials.com/projects-esp32/) | Hunderte Schritt-für-Schritt-Projekte mit Schaltplan und Code. **Erste Anlaufstelle für „Wie schließe ich X an?“** |
| [Seeed Wiki: XIAO ESP32-S3](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/) | Alles zu unseren Hauptboards, inkl. Kamera und Mikrofon |

## Elektronik lernen

| Ressource | Wofür |
|---|---|
| [Elektronik-Kompendium](https://www.elektronik-kompendium.de/) | Deutsches Nachschlagewerk für Grundlagen und Bauteile |
| [SparkFun: Breadboard benutzen](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard) | Steckbrett verstehen |
| [SparkFun: Multimeter benutzen](https://learn.sparkfun.com/tutorials/how-to-use-a-multimeter) | Spannung messen, Durchgang prüfen |
| [SparkFun: Löten](https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering) | Vor dem ersten Löten einmal durchlesen |
| [Adafruit Learn](https://learn.adafruit.com/) | Sehr gute Anleitungen zu fast jedem Sensor (viele Doku-Links der [Materialliste](../MaterialsList/hackathon-stueckliste.csv) führen dorthin) |

## Ohne Hardware ausprobieren

| Ressource | Wofür |
|---|---|
| [Wokwi](https://wokwi.com/) | **ESP32 im Browser simulieren**, inkl. LEDs, Displays und vieler Sensoren. Ideal, um Code zu testen, bevor ihr verkabelt |
| [Wokwi für VS Code](https://docs.wokwi.com/vscode/getting-started) | Dasselbe direkt mit eurem PlatformIO-Projekt |
| [Falstad Circuit Simulator](https://www.falstad.com/circuit/) | Schaltungen simulieren und sehen, wie Strom fließt |

## KI auf dem Mikrocontroller

| Ressource | Wofür |
|---|---|
| [Edge Impulse](https://edgeimpulse.com/) · [Doku](https://docs.edgeimpulse.com/) | Eigenes KI-Modell (Bild, Audio, Bewegung) im Browser trainieren und als Bibliothek für den ESP32 exportieren. **Einfachster Einstieg** |
| [Seeed: Bildklassifizierung mit dem XIAO ESP32-S3 Sense](https://wiki.seeedstudio.com/tinyml_course_Image_classification_project/) | Komplettes TinyML-Projekt mit Kamera, Schritt für Schritt |
| [Seeed: Sprachassistent mit dem XIAO ESP32-S3 Sense](https://wiki.seeedstudio.com/xiao_esp32s3_speech2chatgpt/) | Mikrofon → Cloud-KI → Antwort. Beispiel für „KI in der Cloud“ |
| [ESP-TFLite-Micro](https://github.com/espressif/esp-tflite-micro) · [ESP-DL](https://github.com/espressif/esp-dl) | TensorFlow Lite bzw. Espressifs KI-Bibliothek. Für Fortgeschrittene |
| [Hackathon-FAQ: KI-Assistent einrichten](https://fachschaft-it-hochschule-esslingen.github.io/Events/hackathon/faq.html) | Chat AI der Academic Cloud, Copilot & Co. für euch als Programmierhilfe |

## Doku & Präsentation

| Ressource | Wofür |
|---|---|
| [Markdown Cheat Sheet](https://www.markdownguide.org/cheat-sheet/) | Für die `README.md` eures Projekts (gehört zur Abgabe) |
| [Wokwi](https://wokwi.com/) | Auch gut, um einen sauberen Schaltplan als Bild für die Doku zu erstellen |
