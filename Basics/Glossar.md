# Glossar

[← Grundlagen](README.md)

| Begriff | Bedeutung |
|---|---|
| **ADC** | Analog-Digital-Wandler. Macht aus einer Spannung eine Zahl (`analogRead`). |
| **Aktor** | Etwas, das der Mikrocontroller bewegt oder schaltet: LED, Servo, Lautsprecher, Relais. |
| **Baudrate** | Übertragungsgeschwindigkeit bei UART, z. B. 115200. Beide Seiten müssen gleich eingestellt sein. |
| **Bibliothek (Library)** | Fertiger Code, um einen Sensor oder ein Display anzusprechen. |
| **BOOT-Taste** | Bringt ESP32-Boards beim Einschalten in den Flash-Modus, z. B. wenn der Upload hängt. |
| **Breakout(-Board)** | Kleine Platine, auf der ein winziger Chip mit gut steckbaren Pins herausgeführt ist. |
| **Brownout** | Spannung bricht kurz ein → das Board startet neu. Meist zu viel Last oder ein schlechtes Kabel. |
| **DAC** | Digital-Analog-Wandler. Gibt eine echte Spannung zwischen 0 und 3,3 V aus. |
| **Datenblatt** | Offizielles Dokument des Herstellers mit allen Werten eines Bauteils. Im Zweifel: lesen. |
| **DIP** | Bauform mit zwei Reihen Beinchen, passt ins Steckbrett (z. B. ATtiny85, LM358). |
| **Dupont-Kabel** | Steckkabel mit Stift (Male) oder Buchse (Female) an den Enden. |
| **ESD** | Elektrostatische Entladung. Ein kleiner Funke vom Finger kann Chips zerstören. |
| **Flashen** | Programm auf den Mikrocontroller übertragen (= Hochladen). |
| **Floating** | Ein Eingang hängt „in der Luft“ und liest Zufallswerte. Abhilfe: Pull-up / Pull-down. |
| **GND** | Masse, der 0-V-Bezugspunkt. Muss bei allen Teilen verbunden sein. |
| **GPIO** | General Purpose Input/Output, ein frei programmierbarer Pin. |
| **Grove** | Stecksystem von Seeed mit 4-poligen Kabeln, z. B. am XIAO Expansion Board. |
| **Header / Stiftleiste** | Reihe von Metallstiften (RM 2,54 mm), die man an ein Board lötet, damit es ins Steckbrett passt. |
| **I2C** | Bus mit 2 Datenleitungen (SDA, SCL) für viele Geräte mit Adressen. → [Bussysteme](Bussysteme.md) |
| **JST(-PH)** | Kleiner Steckverbinder, z. B. für LiPo-Akkus. Polarität ist nicht genormt! |
| **LiPo / Li-Ion** | Lithium-Akku, 3,7 V nominal, voll 4,2 V. Kurzschluss = Brandgefahr. |
| **LoRa** | Funktechnik für kleine Datenmengen über große Distanzen (km). In Europa auf 868 MHz. |
| **Logikpegel** | Spannung, die HIGH bedeutet. Bei unseren Boards 3,3 V. |
| **Mikrocontroller (MCU)** | Kleiner Computer auf einem Chip: Prozessor, Speicher, Pins. ESP32, ATtiny85 … |
| **Multimeter** | Messgerät für Spannung (V), Strom (A), Widerstand (Ω) und Durchgang (Piepser). |
| **Pegelwandler** | Übersetzt Signale zwischen 3,3 V und 5 V in beide Richtungen. |
| **Pinout** | Grafik, welcher Pin eines Boards was kann. → [Board-Docs](../BoardDocs/README.md) |
| **PSRAM** | Zusätzlicher Arbeitsspeicher, z. B. für Kamerabilder oder KI-Modelle. |
| **Pull-up / Pull-down** | Widerstand, der einen Eingang in Ruhe auf HIGH bzw. LOW zieht. |
| **PWM** | Pin schaltet schnell an/aus, um z. B. eine LED zu dimmen (`analogWrite`). |
| **RM 2,54** | Rastermaß 2,54 mm (0,1 Zoll), der Standardabstand von Pins im Steckbrett. |
| **RTC** | Echtzeituhr, die die Uhrzeit auch ohne WLAN weiß (z. B. DS3231). |
| **Sensor** | Misst etwas: Temperatur, Licht, Bewegung, Abstand … |
| **Serieller Monitor** | Fenster in PlatformIO (🔌 in der Statusleiste), das Ausgaben von `Serial.print` anzeigt. |
| **Sketch** | Arduino-Begriff für ein Programm mit `setup()` und `loop()`. In PlatformIO steht es als `.cpp`-Datei im Ordner `src/` (bei unseren Startprojekten `src/example.cpp`). |
| **SPI** | Schneller Bus mit MOSI, MISO, SCK und CS pro Gerät. → [Bussysteme](Bussysteme.md) |
| **Strapping-Pin** | Pin, dessen Zustand beim Start bestimmt, wie der ESP32 bootet. Möglichst nicht belegen. |
| **UART** | Serielle Verbindung zwischen genau zwei Geräten (TX ↔ RX). |
| **U.FL / IPEX** | Winziger Antennenstecker. Gerade aufdrücken, nicht schräg ziehen. |
| **Vorwiderstand** | Widerstand vor einer LED, der den Strom begrenzt. |
