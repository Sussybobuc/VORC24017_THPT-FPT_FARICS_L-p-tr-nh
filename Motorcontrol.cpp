#include "MotorControl.h"
#include <Arduino.h>

// Khởi tạo đối tượng PWM
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

bool initializeMotorControl() {
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);
    return true;
}

bool setMotorSpeed(uint8_t motor, uint16_t speed, bool direction) {
    if (motor >= 16 || speed > 100) {
        Serial.println("Invalid motor or speed value!");
        return false;
    }
    uint16_t pwm_value = map(speed, 0, 100, 0, 4095); // Chuyển đổi tốc độ từ % sang giá trị PWM
    if (direction) {
        pwm.setPWM(motor, 0, pwm_value);
        pwm.setPWM(motor + 1, 0, 0);
    } else {
        pwm.setPWM(motor, 0, 0);
        pwm.setPWM(motor + 1, 0, pwm_value);
    }
    return true;
}

void stopAllMotors() {
    for (uint8_t i = 0; i < 16; i++) {
        pwm.setPWM(i, 0, 0);
    }
}
