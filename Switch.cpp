#include "Switch.h"

#include <Arduino.h>

#define ANGLE_DEFAULT 90
#define DELAY_MS      1000

Switch::Switch(int pinNumber, int switchAngle)
  : pinNumber(pinNumber), switchAngle(switchAngle), servo() {
}

Switch::~Switch() {
  if (servo.attached()) {
    servo.detach();
  }
}

inline void Switch::write(int angle) {
  servo.attach(pinNumber);
  servo.write(angle);
  delay(DELAY_MS);
  servo.detach();
}

inline void Switch::writeAndReturn(int angle) {
  servo.attach(pinNumber);
  servo.write(angle);
  delay(DELAY_MS);
  servo.write(ANGLE_DEFAULT);
  delay(DELAY_MS);
  servo.detach();
}

void Switch::init() {
  write(ANGLE_DEFAULT);
}

void Switch::on() {
  writeAndReturn(ANGLE_DEFAULT + switchAngle);
}

void Switch::off() {
  writeAndReturn(ANGLE_DEFAULT - switchAngle);
}
