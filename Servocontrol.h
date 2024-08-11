#ifndef SERVO_CONTROL_H
#define SERVO_CONTROL_H

void initializeServo180();
void initializeServo360();
void setServoAngle180(int servoIndex, int angle);
void setServoSpeed360(int servoIndex, int speed);

#endif // SERVO_CONTROL_H
