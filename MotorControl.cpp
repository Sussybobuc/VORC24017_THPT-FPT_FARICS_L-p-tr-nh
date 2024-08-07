#include "MotorControl.h"

void MotorControl::setup() {
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);
  Wire.setClock(400000);
}

void MotorControl::control(int lx, int ly, int rx, int ry) {
  // Điều khiển motor bên trái
  setMotorSpeed(0, ly);
  setMotorSpeed(1, ry);
}

void MotorControl::setMotorSpeed(int channel, int speed) {
  int pwmValue = map(speed, 0, 255, 0, 4095);
  pwm.setPWM(channel, 0, pwmValue);
}
