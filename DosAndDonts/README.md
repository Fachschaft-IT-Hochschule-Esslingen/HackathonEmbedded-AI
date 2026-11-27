# Dos & Don'ts

Die Regeln aus der Eröffnungspräsentation zum Nachschlagen. Sie gelten für alle Teams.
Wer die Sicherheitsregeln ignoriert, gibt Lötkolben bzw. Akku zurück.

## Strom & Spannung

| ✅ Do | ❌ Don't |
|---|---|
| Davon ausgehen, dass **alle Boards mit 3,3 V Logik** arbeiten | **5 V an einen GPIO** legen. Das Board ist danach kaputt |
| Module über **3V3** versorgen, 5 V nur, wenn das Modul es verlangt | Die Pins 5V / VIN / VUSB mit einem GPIO verbinden |
| Vorher prüfen: Welche Spannung braucht das Modul, welche gibt es an seinen **Ausgängen** aus? Bei 5-V-Modulen einen **Pegelwandler** (digital) bzw. **Spannungsteiler** (analog) dazwischen, siehe [Bussysteme](../Basics/Bussysteme.md#5-v-module-an-33-v-boards) | 5-V-Module (z. B. MQ-135) mit ihrem Ausgang direkt an einen GPIO |
| **LEDs immer mit Vorwiderstand** (bei 3,3 V: 220–330 Ω) | LEDs direkt an einen GPIO |
| Servos, Motoren, LED-Streifen und Lautsprecher **extern versorgen**, Steuersignal vom GPIO, **GND gemeinsam** | Diese Verbraucher am GPIO oder am 3V3-Pin betreiben |
| Motoren über einen **Treiber** (Transistor / Motortreiber) anschließen | Mehr als ca. 20 mA aus einem Pin ziehen |

**Faustregel:** Alles, was sich bewegt, leuchtet (mehr als eine LED) oder Krach macht, braucht eine eigene Versorgung.

## Laptop & USB

**Empfehlung:** Boards **nicht über den USB-Anschluss des Laptops betreiben**, sondern über ein **externes USB-Netzteil** (Ladegerät) oder eine Powerbank. Ein Kurzschluss oder eine zu große Last in eurer Schaltung geht sonst direkt auf den Laptop. Mit viel Pech ist danach der USB-Port oder das Mainboard des Laptops kaputt.

| ✅ Do | ❌ Don't |
|---|---|
| Laptop-USB nur zum **Hochladen und Debuggen** (serieller Monitor) | Die fertige Schaltung dauerhaft am Laptop laufen lassen |
| Zum Testen und im Betrieb ein **externes USB-Netzteil** oder eine Powerbank nehmen | Motoren, LED-Streifen, Lautsprecher oder Akkus über den Laptop versorgen |
| Vor dem Anstecken an den Laptop: Schaltung auf **Kurzschlüsse** prüfen | Ein Board an den Laptop stecken, das gerade heiß wurde oder komisch riecht |
| Wenn ihr am Laptop arbeiten müsst und Lasten dran sind: **USB-Hub mit eigenem Netzteil** dazwischen | Laptop-Warnungen wie „USB-Gerät überlastet“ wegklicken und weitermachen |

## Verdrahten

| ✅ Do | ❌ Don't |
|---|---|
| **Stromlos stecken**: erst USB und Akku ab, dann verdrahten | An einer Schaltung umstecken, während Strom drauf ist |
| **GND gemeinsam** für alle Teile und alle Netzteile | Getrennte Massen bei mehreren Versorgungen |
| **Polarität prüfen**: rot = +, schwarz = GND, aber Billig-Kabeln nicht blind trauen | Sich nur auf die Kabelfarbe verlassen |
| Vor dem Einschalten **nochmal schauen** oder das Team schauen lassen. Im Zweifel **mit dem Multimeter messen** | Drahtreste, Schrauben oder Werkzeug unter dem Board liegen lassen |
| Zum Hochladen ein **USB-Datenkabel** benutzen | Reine Ladekabel: Das Board wird dann nicht erkannt |

## Wenn etwas heiß wird oder riecht

| ✅ Do | ❌ Don't |
|---|---|
| **Sofort Strom trennen** (USB / Akku ab) | Weitermachen „weil es ja noch läuft“ |
| Abkühlen lassen und **Bescheid sagen** | Heiße Bauteile anfassen |
| Kaputte Teile **bei uns abgeben** | Kaputte Teile zurück in die Kiste legen |

Warnzeichen: Chip oder Regler zu heiß zum Anfassen, Brandgeruch, Rauch, Laptop meldet „USB-Gerät überlastet“.

## Handhabung & ESD

| ✅ Do | ❌ Don't |
|---|---|
| Boards **am Rand anfassen** | Auf Chips und Pins fassen |
| Vorher kurz an **geerdetes Metall** fassen (Heizkörper, Tischgestell) | Boards auf Metall, Alufolie oder in Plastiktüten ablegen |
| Getränke **weit weg** vom Aufbau | Getränke neben dem Aufbau |

## Akkus (18650, LiPo)

| ✅ Do | ❌ Don't |
|---|---|
| Akkus **nur auf Anfrage** bei uns holen | Akkus ohne Rücksprache mit uns benutzen |
| Den **ersten Anschluss** eines Akkus an eure Schaltung **außerhalb des Gebäudes** machen | Den ersten Test drinnen am Tisch |
| Laden **nur** über das Board, an dem der Akku hängt (LoRa-Board bzw. XIAO), per USB-C | Akkus **unbeaufsichtigt** laden |
| **Polarität doppelt prüfen**. Bei JST-Steckern von LiPos ist die Belegung nicht genormt! | Akku an 3V3 oder einen GPIO (voll geladen hat er 4,2 V) |
| Nur an die vorgesehenen Anschlüsse (z. B. BAT-Pads am XIAO) | Akkus lose in der Tasche oder auf Metall (Kurzschluss!) |
| Aufgeblähte, beschädigte oder heiße Akkus **sofort melden** | Solche Akkus weiter benutzen |

### Laden und Ladestand prüfen

**Laden:** Das DFRobot-LoRa-Board (18650 an der Schraubklemme) und die XIAO-Boards (LiPo an BAT+/BAT−) laden den Akku automatisch, sobald sie **per USB-C angeschlossen** sind. Die rote Lade-LED leuchtet beim Laden und geht aus, wenn der Akku voll ist.

**Ladestand messen:** Multimeter auf Gleichspannung (V⎓, 20-V-Bereich) an + und − des Akkus. Vorher USB abziehen und ein paar Minuten warten, denn während des Ladens ist die Spannung höher als die echte. Gilt für 18650 und LiPo gleichermaßen:

| Gemessen | Bedeutung |
|---|---|
| 4,1–4,2 V | Voll |
| 3,7–3,9 V | Etwa halb voll |
| 3,5–3,7 V | Ziemlich leer, bald laden |
| unter 3,5 V | Fast leer, sofort laden |
| 0 V | Meist hat die Schutzschaltung abgeschaltet. Bei uns melden, nicht selbst basteln |
| über 4,25 V oder Akku aufgebläht/warm | Nicht mehr benutzen, sofort melden |

## Löten

| ✅ Do | ❌ Don't |
|---|---|
| Lötkolben **nur auf Anfrage**. Wer noch nie gelötet hat: nur **mit Aufsicht** | Ohne Erfahrung allein löten |
| Kolben **immer in die Ablage**, auf der Spitze **immer Zinn** | Den Kolben auf den Tisch legen (die Spitze hat über 300 °C) |
| **Dritte Hand** benutzen | Bauteile beim Löten mit der Hand halten |
| Fenster auf, Board **stromlos** | In den Rauch atmen |
| Nach Gebrauch **ausschalten und zurückgeben**, danach **Hände waschen** | Den Kolben eingeschaltet liegen lassen |

Die meisten Aufbauten gehen auch ohne Löten: Steckbrett & Dupont-Kabel.

## Material

| ✅ Do | ❌ Don't |
|---|---|
| Boards, Module mit Wert, Akkus und Lötkolben über den [Ausleihschein](../BorrowingPaper/Hackathon_Verleihformular.html) | Ausleihpflichtiges Material ohne Schein mitnehmen |
| Nur nehmen, was ihr braucht: 20 Teams teilen sich den Pool | Material horten |
| Nach dem Event alles Ausgeliehene **vollständig zurückgeben** (Fr, 11.12.2026, 13–14 Uhr, Fachschaftsraum IT) | |
