#include "ServoControl.h"
#include <Arduino.h>
#include "MotorControl.h"

bool initializeServoControl() {
    // Đã được khởi tạo trong initializeMotorControl()
    return true;
}

bool setServoAngle(uint8_t servo, uint16_t angle) {
    if (servo >= 16 || angle > 180) {
        Serial.println("Invalid servo or angle value!");
        return false;
    }
    uint16_t pwm_value = map(angle, 0, 180, 102, 512);
    pwm.setPWM(servo, 0, pwm_value);
    return true;
}

bool setServoMicroseconds(uint8_t servo, uint16_t microseconds) {
    if (servo >= 16 || microseconds < 500 || microseconds > 2500) {
        Serial.println("Invalid servo or microseconds value!");
        return false;
    }
    uint16_t pwm_value = map(microseconds, 500, 2500, 102, 512);
    pwm.setPWM(servo, 0, pwm_value);
    return true;
}
