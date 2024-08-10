#include "PSPController.h"
#include <Arduino.h>
#include "MotorControl.h"
#include "ServoControl.h"

// Khởi tạo đối tượng PS2X
PS2X ps2x;

bool initializePSPController() {
    int error = ps2x.config_gamepad(13, 11, 10, 12, true, true);
    if (error == 0) {
        Serial.println("Found Controller, configured successfully");
        return true;
    } else {
        Serial.println("Controller not found, check wiring");
        return false;
    }
}

void handlePSPInput() {
    ps2x.read_gamepad(false, 0);

    int leftSpeed = ps2x.Analog(PSS_LY);
    int rightSpeed = ps2x.Analog(PSS_RY);

    leftSpeed = map(leftSpeed, 0, 255, -100, 100);
    rightSpeed = map(rightSpeed, 0, 255, -100, 100);

    tankMove(leftSpeed, rightSpeed);

    if (ps2x.Button(PSB_CIRCLE)) {
        setServoAngle(0, 180);
    } else {
        setServoAngle(0, 0);
    }

    if (ps2x.Button(PSB_L1)) {
        setServoAngle(1, 180);
    } else {
        setServoAngle(1, 0);
    }

    if (ps2x.Button(PSB_R1)) {
        setMotorSpeed(4, 100, true); // Motor intake
    } else {
        setMotorSpeed(4, 0, true);
    }

    if (ps2x.Button(PSB_R2)) {
        setMotorSpeed(5, 100, true); // Motor outtake
    } else {
        setMotorSpeed(5, 0, true);
    }
}
