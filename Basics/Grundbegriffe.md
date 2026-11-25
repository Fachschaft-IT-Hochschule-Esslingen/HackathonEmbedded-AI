# Grundbegriffe: Elektronik ab null

[← Grundlagen](README.md)

Ihr müsst keine Elektrotechnik studiert haben. Diese Seite reicht für fast alles, was ihr beim Hackathon baut.

## Spannung, Strom, Widerstand

Stellt euch Strom wie **Wasser in einem Schlauch** vor:

| Begriff | Einheit | Wasser-Vergleich | Bei uns typisch |
|---|---|---|---|
| **Spannung** (U) | Volt (V) | Wasserdruck | 3,3 V (Logik), 5 V (USB), 3,7 V (Akku) |
| **Strom** (I) | Ampere (A), mA | wie viel Wasser fließt | LED: 10 mA, ESP32 mit WLAN: 100–350 mA |
| **Widerstand** (R) | Ohm (Ω) | wie eng der Schlauch ist | 220 Ω, 1 kΩ, 10 kΩ |

Zusammenhang (**Ohmsches Gesetz**): **U = R × I**, umgestellt **I = U / R** oder **R = U / I**.

**GND** (Ground, Masse) ist der Bezugspunkt, sozusagen „0 V“. Spannung wird immer *gegen GND* gemessen. Darum muss **GND bei allen Teilen einer Schaltung verbunden** sein, sonst haben die Signale keinen gemeinsamen Bezug.

**Kurzschluss** = Plus direkt mit GND verbunden, ohne Widerstand dazwischen. Dann fließt sehr viel Strom, und Teile werden heiß oder gehen kaputt.

## Rechenbeispiel: Vorwiderstand für eine LED

Eine LED braucht ungefähr 2 V und soll mit etwa 5 mA leuchten. Der GPIO liefert 3,3 V.

- Am Widerstand müssen 3,3 V − 2 V = **1,3 V** abfallen.
- R = U / I = 1,3 V / 0,005 A = **260 Ω** → nehmt **220 Ω oder 330 Ω**.

Ohne Widerstand begrenzt nichts den Strom. Die LED oder der Pin gehen kaputt.

**LED-Polung:** Das **lange Bein** ist **+** (Anode). Das kurze Bein (Kathode, flache Seite am Gehäuse) kommt an GND.

## Digital und analog

- **Digital**: nur zwei Zustände, **HIGH** (3,3 V) oder **LOW** (0 V). Beispiele: Taster, LED an/aus, PIR-Bewegungsmelder.
  `digitalWrite(pin, HIGH)` / `digitalRead(pin)`
- **Analog**: alle Werte dazwischen. Der **ADC** im Chip wandelt eine Spannung in eine Zahl (ESP32: 0–4095 für 0–3,3 V). Beispiele: Poti, Fotowiderstand, Gassensor.
  `analogRead(pin)`. Nur Pins mit „A“ bzw. „ADC“ im Pinout können das.
- **PWM** (Pulsweitenmodulation): Ein digitaler Pin schaltet sehr schnell an und aus. Je länger „an“, desto heller die LED bzw. schneller der Motor. So „faked“ man einen analogen Ausgang.
  `analogWrite(pin, 0…255)`

## Eingang, Pull-up, Pull-down

Ein Pin als **Eingang** (`INPUT`), an dem nichts angeschlossen ist, „**floatet**“: Er liest zufällig HIGH oder LOW. Darum braucht ein Taster einen **Pull-up**- oder **Pull-down-Widerstand**, der den Pin in Ruhe auf einen festen Wert zieht.

Einfachste Lösung: den **internen Pull-up** einschalten und den Taster zwischen Pin und GND anschließen.

```cpp
pinMode(D1, INPUT_PULLUP);           // Pin ist in Ruhe HIGH
if (digitalRead(D1) == LOW) { ... }  // LOW = Taster gedrückt
```

## Das Steckbrett (Breadboard)

```
  + + + + + + + + + +     ← Stromschiene: die ganze Reihe ist verbunden (meist rot = +)
  - - - - - - - - - -     ← Stromschiene: (blau = GND)

  a b c d e   f g h i j
1 ●─●─●─●─●   ●─●─●─●─●   ← je 5 Löcher in einer Zeile sind verbunden
2 ●─●─●─●─●   ●─●─●─●─●
3 ●─●─●─●─●   ●─●─●─●─●
        ↑ Mittelgraben: links und rechts sind NICHT verbunden
```

- Die **5er-Gruppen** einer Zeile sind verbunden, die Spalten nicht.
- Über den **Mittelgraben** setzt man Chips (z. B. ATtiny85) und Boards, damit jedes Beinchen eine eigene Zeile hat.
- Bei den großen Steckbrettern sind die Stromschienen manchmal **in der Mitte unterbrochen**. Im Zweifel mit dem Multimeter prüfen.

## Widerstände ablesen

Die Farbringe kann man lernen, muss man aber nicht: Die Widerstände im Sortiment sind beschriftet, und im Zweifel misst das **Multimeter** (Einstellung Ω) den Wert. Typische Werte, die ihr braucht:

| Wert | Wofür |
|---|---|
| 220–330 Ω | Vorwiderstand für LEDs |
| 1 kΩ | Basiswiderstand für Transistoren |
| 4,7–10 kΩ | Pull-up / Pull-down, I2C-Pull-ups |
| 10 kΩ | Spannungsteiler mit Fotowiderstand |

## Weiter

- Sensoren mit mehreren Datenleitungen anschließen → [Bussysteme](Bussysteme.md)
- Begriffe nachschlagen → [Glossar](Glossar.md)
