#include <Ultrasonic.h>
const int pinTrigger = 4;
const int pinEcho = 5;
const int pinRelay = 7;

Ultrasonic ultrasonic(pinTrigger, pinEcho);

void setup() {
  pinMode(pinRelay, OUTPUT);
}

void delayInSeconds(int seconds) {
  delay(seconds * 1000);
}

void activateRelayFor(int seconds) {
  digitalWrite(pinRelay, LOW);
  delayInSeconds(seconds);
  digitalWrite(pinRelay, HIGH); 
}

void loop() {
  float distanceInCentimeters;
  long microsec = ultrasonic.timing();
  
  distanceInCentimeters = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  if (distanceInCentimeters >= 5 && distanceInCentimeters <= 15) {
    activateRelayFor(5);
  } else if (distanceInCentimeters > 15 && distanceInCentimeters <= 20) {
    activateRelayFor(15);
  }
  delay(500);
}
