#include "A22Ultrasonic.h"

// SoftwareSerial constructor
A22Ultrasonic::A22Ultrasonic(uint8_t rxPin, uint8_t txPin, long baudRate)
  : _rxPin(rxPin), _txPin(txPin), _baudRate(baudRate) {
  swSerial = new SoftwareSerial(rxPin, txPin);
  serialPort = swSerial;
  useHardwareSerial = false;
}

// HardwareSerial constructor
A22Ultrasonic::A22Ultrasonic(HardwareSerial* hw, long baudRate)
  : hwSerial(hw), _baudRate(baudRate) {
  serialPort = hwSerial;
  useHardwareSerial = true;
}

void A22Ultrasonic::begin() {
  if (useHardwareSerial) {
    hwSerial->begin(_baudRate);
  } else {
    swSerial->begin(_baudRate);
  }
}

int A22Ultrasonic::readDistance() {
  if (!serialPort) return -10;  // fallback fail-safe

  serialPort->write((uint8_t)0x00);

  uint32_t t0 = millis();
  int header = -1;

  while (millis() - t0 < 50) {
    if (serialPort->available()) {
      header = serialPort->read();
      if (header == 0xFF) break;
    }
  }
  if (header != 0xFF) return -1;

  while (serialPort->available() < 3) {
    if (millis() - t0 > 100) return -2;
  }

  uint8_t dataH = serialPort->read();
  uint8_t dataL = serialPort->read();
  uint8_t sum   = serialPort->read();

  uint8_t chk = (0xFF + dataH + dataL) & 0xFF;
  if (chk != sum) return -3;

  uint16_t dist = (dataH << 8) | dataL;
  if (dist == 0xFFFE) return -4;

  return dist;
}
