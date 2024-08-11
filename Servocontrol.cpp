#include "ServoControl.h"
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void initializeServo180() {
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);
    Wire.setClock(400000);
}

void initializeServo360() {
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);
    Wire.setClock(400000);
}

void setServoAngle180(int servoIndex, int angle) {
    int pwmValue = map(angle, 0, 180, 102, 512);
    pwm.setPWM(servoIndex, 0, pwmValue);
}

void setServoSpeed360(int servoIndex, int speed) {
    int pwmValue = map(speed, -255, 255, 102, 512);
    pwm.setPWM(servoIndex, 0, pwmValue);
}
