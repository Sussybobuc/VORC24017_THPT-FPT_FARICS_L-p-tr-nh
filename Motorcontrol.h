#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

void initializeMotors();
void tankMove(int leftSpeed, int rightSpeed);
void setMotorSpeed(int motorIndex, int speed, bool direction);

#endif // MOTOR_CONTROL_H
