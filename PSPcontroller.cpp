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

    if (ps2x.ButtonPressed(PSB_CIRCLE)) {
        // Điều khiển servo chắn banh
        static bool isPushing = false;
        isPushing = !isPushing;
        setServoSpeed360(2, isPushing ? 255 : 0);
    }

    if (ps2x.ButtonPressed(PSB_L1)) {
        // Điều khiển servo đẩy banh
        setServoSpeed360(3, 255);
    } else {
        setServoSpeed360(3, 0);
    }

    if (ps2x.ButtonPressed(PSB_R1)) {
        // Điều khiển hệ thống intake
        setMotorSpeed(3, 255);
    } else {
        setMotorSpeed(3, 0);
    }

    if (ps2x.ButtonPressed(PSB_R2)) {
        // Điều khiển hệ thống outtake
        setMotorSpeed(4, 255);
    } else {
        setMotorSpeed(4, 0);
    }
}
