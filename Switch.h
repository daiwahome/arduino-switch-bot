#ifndef _SWITCH_H
#define _SWITCH_H

#include <Servo.h>

class Switch {
  int pinNumber;
  int switchAngle;
  Servo servo;

  void write(int angle);
  void writeAndReturn(int angle);

public:
  Switch(int pinNumber, int switchAngle);
  ~Switch();
  
  void init();
  void on();
  void off();
};

#endif /* _SWITCH_H */
