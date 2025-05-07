# A22Ultrasonic Library - Documentație

Sebastian M.

Această librărie oferă suport pentru senzorii ultrasonici A22 cu comunicare serială, folosind atât SoftwareSerial cât și porturi HardwareSerial.

## Funcționalitate principală
- Trimitere comandă trigger
- Așteptare sincronizare (header 0xFF)
- Citire 2 byți distanță + checksum
- Verificare checksum
- Detectare interferențe (cod 65534)

## Coduri returnate:
- `>=0` – Distanță validă în mm
- `-1` – Timeout header
- `-2` – Timeout date
- `-3` – Checksum invalid
- `-4` – Interferențe
- `-10` – Port serial inexistent

## Exemple:
- `BasicRead.ino`: Un singur senzor pe SoftwareSerial
- `Read4Sensors.ino`: Combină 2 senzori pe porturi hardware și 2 pe SoftwareSerial

## Modificări posibile:
- Poți schimba baud rate-ul prin constructor
- Poți folosi `Serial1`, `Serial2` etc. pe plăci compatibile (Mega, ESP32, Pico)

## Note:
- SoftwareSerial funcționează doar cu un port ascultat simultan
- Pentru fiabilitate mai bună folosește porturi hardware unde e posibil