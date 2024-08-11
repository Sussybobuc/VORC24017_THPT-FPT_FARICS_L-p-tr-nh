#include "MotorControl.h"
#include <Adafruit_PWMServoDriver.h>

// Khai báo các chân I2C
#define SDA_PIN 21
#define SCL_PIN 22

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void initializeMotors() {
    Wire.begin(SDA_PIN, SCL_PIN);
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);
    Wire.setClock(400000);
}

void tankMove(int leftSpeed, int rightSpeed) {
    int leftPWM = map(leftSpeed, -100, 100, 0, 4095);
    int rightPWM = map(rightSpeed, -100, 100, 0, 4095);

    pwm.setPWM(8, 0, leftPWM);
    pwm.setPWM(9, 0, rightPWM);
}

void setMotorSpeed(int motorIndex, int speed, bool direction) {
    int pwmValue = map(speed, 0, 100, 0, 4095);

    if (direction) {
        pwm.setPWM(motorIndex * 2, 0, pwmValue);
        pwm.setPWM(motorIndex * 2 + 1, 0, 0);
    } else {
        pwm.setPWM(motorIndex * 2, 0, 0);
        pwm.setPWM(motorIndex * 2 + 1, 0, pwmValue);
    }
}
