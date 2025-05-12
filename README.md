🇬🇧 EN

# A22Ultrasonic Library - Documentation

Sebastian M.

This library provides support for A22 ultrasonic sensors with serial communication (UART controlled version), using both SoftwareSerial and HardwareSerial ports.

## Main Functionality
- Sending a trigger command
- Waiting for synchronization (header 0xFF)
- Reading 2 bytes for distance + checksum
- Verifying checksum
- Detecting interferences (code 65534)

## Returned Codes:
- `>=0` – Valid distance in mm
- `-1` – Header timeout
- `-2` – Data timeout
- `-3` – Invalid checksum
- `-4` – Interferences
- `-10` – Nonexistent serial port

## Examples:
- `BasicRead.ino`: A single sensor on SoftwareSerial
- `Read4Sensors.ino`: Combines 2 sensors on hardware ports and 2 on SoftwareSerial

## Possible Modifications:
- You can change the baud rate through the constructor (default: 115200)
- You can use `Serial1`, `Serial2`, etc., on compatible boards (Mega, ESP32, Pico, Teensy)

## Notes:
- SoftwareSerial only works with one port being listened to at a time
- For better reliability, use hardware ports where possible

🇷🇴 RO

# A22Ultrasonic Library - Documentație

Sebastian M.

Această librărie oferă suport pentru senzorii ultrasonici A22 cu comunicare serială (versiunea UART controlled), folosind atât SoftwareSerial cât și porturi HardwareSerial.

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
- Poți schimba baud rate-ul prin constructor (implicit: 115200)
- Poți folosi `Serial1`, `Serial2` etc. pe plăci compatibile (Mega, ESP32, Pico, Teensy)

## Note:
- SoftwareSerial funcționează doar cu un port ascultat simultan
- Pentru fiabilitate mai bună folosește porturi hardware unde e posibil