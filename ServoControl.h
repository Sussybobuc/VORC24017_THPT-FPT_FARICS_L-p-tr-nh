#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include <Adafruit_PWMServoDriver.h>

class ServoControl {
  public:
    void setup();
    void control(bool circleButton, bool l1Button, bool r1Button, bool r2Button);
  
  private:
    Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
    void setServoAngle(int channel, int angle);
};

#endif
