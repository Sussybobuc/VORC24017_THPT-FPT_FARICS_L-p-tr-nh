#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

#include <Adafruit_PWMServoDriver.h>

bool initializeServoControl();
bool setServoAngle(uint8_t servo, uint16_t angle);
bool setServoMicroseconds(uint8_t servo, uint16_t microseconds);

#endif // SERVO_CONTROL_H
