#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Adafruit_PWMServoDriver.h>

class MotorControl {
  public:
    void setup();
    void control(int lx, int ly, int rx, int ry);
  
  private:
    Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
    void setMotorSpeed(int channel, int speed);
};

#endif
