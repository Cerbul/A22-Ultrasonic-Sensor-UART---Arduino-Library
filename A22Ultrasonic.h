#ifndef A22_ULTRASONIC_H
#define A22_ULTRASONIC_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class A22Ultrasonic {
public:
  // Constructor pentru SoftwareSerial
  A22Ultrasonic(uint8_t rxPin, uint8_t txPin, long baudRate = 115200);

  // Constructor pentru HardwareSerial
  A22Ultrasonic(HardwareSerial* hwSerial, long baudRate = 115200);

  void begin();
  int readDistance();

private:
  SoftwareSerial* swSerial = nullptr;
  HardwareSerial* hwSerial = nullptr;
  Stream* serialPort = nullptr;

  uint8_t _rxPin, _txPin;
  long _baudRate;
  bool useHardwareSerial = false;
};

#endif
