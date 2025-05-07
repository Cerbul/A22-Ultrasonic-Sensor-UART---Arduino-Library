#include <A22Ultrasonic.h>

A22Ultrasonic s1(&Serial1);			// 	HardwareSerial --- &Serial1 / &Serial2 / &Serial3, *baudRate=115200
A22Ultrasonic s2(&Serial2, 115200);	// 	HardwareSerial --- &Serial1 / &Serial2 / &Serial3, *baudRate=115200
A22Ultrasonic s3(7, 6); 			//	SoftwareSerial --- RX, TX, *baudRate=115200
A22Ultrasonic s4(5, 4, 115200); 	//	SoftwareSerial --- RX, TX, *baudRate=115200

void setup() {
  Serial.begin(9600);
  s1.begin();
  s2.begin();
  s3.begin();
  s4.begin();
}

void loop() {
  Serial.print("  S1: "); printDist(s1.readDistance());
  Serial.print("  S2: "); printDist(s2.readDistance());
  Serial.print("  S3: "); printDist(s3.readDistance());
  Serial.print("  S4: "); printDist(s4.readDistance());
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