#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Adafruit_PWMServoDriver.h>

// Khai báo đối tượng PWM
extern Adafruit_PWMServoDriver pwm;

bool initializeMotorControl();
bool setMotorSpeed(uint8_t motor, uint16_t speed, bool direction);
void stopAllMotors();

#endif // MOTOR_CONTROL_H
