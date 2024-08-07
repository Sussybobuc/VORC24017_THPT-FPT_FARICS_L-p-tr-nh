#include "ServoControl.h"

void ServoControl::setup() {
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);
}

void ServoControl::control(bool circleButton, bool l1Button, bool r1Button, bool r2Button) {
  if (circleButton) {
    setServoAngle(2, 90); // Điều khiển servo chắn banh
  }
  if (l1Button) {
    setServoAngle(3, 90); // Điều khiển servo để đẩy banh
  }
  if (r1Button) {
    setServoAngle(4, 90); // Điều khiển servo cho hệ thống intake
  }
  if (r2Button) {
    setServoAngle(5, 90); // Điều khiển servo cho hệ thống outtake
  }
}

void ServoControl::setServoAngle(int channel, int angle) {
  int pulseLength = map(angle, 0, 180, 150, 600);
  pwm.writeMicroseconds(channel, pulseLength);
}
