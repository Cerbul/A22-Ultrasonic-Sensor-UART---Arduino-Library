#include <A22Ultrasonic.h>

A22Ultrasonic sensor(3, 2);               // SoftwareSerial --- RX, TX, *baudRate=115200
//A22Ultrasonic sensor(3, 2, 115200);     // SoftwareSerial --- RX, TX, *baudRate=115200
//A22Ultrasonic sensor(&Serial2);         // HardwareSerial --- &Serial1 / &Serial2 / &Serial3, *baudRate=115200
//A22Ultrasonic sensor(&Serial2, 115200); // HardwareSerial --- &Serial1 / &Serial2 / &Serial3, *baudRate=115200

void setup() {
  Serial.begin(9600);
  sensor.begin();
}

void loop() {
  int dist = sensor.readDistance();
  Serial.print("Senzor: ");
  printDist(dist);
  Serial.println();
  delay(150);
}

void printDist(int d) {
  switch (d) {
    case -1: Serial.print("Timeout header"); break;
    case -2: Serial.print("Timeout data"); break;
    case -3: Serial.print("Checksum error"); break;
    case -4: Serial.print("Interferente"); break;
    default: Serial.print(d); Serial.print(" mm"); break;
  }
}