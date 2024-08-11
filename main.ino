#include <Arduino.h>
#include "MotorControl.h"
#include "ServoControl.h"
#include "ColorSensor.h"
#include "PSPController.h"

void setup() {
    Serial.begin(115200);

    if (!initializeMotorControl()) {
        Serial.println("Motor control initialization failed!");
        while (1);
    }

    if (!initializeServoControl()) {
        Serial.println("Servo control initialization failed!");
        while (1);
    }

    if (!initializeColorSensor()) {
        Serial.println("Color sensor initialization failed!");
        while (1);
    }

    if (!initializePSPController()) {
        Serial.println("PSP controller initialization failed!");
        while (1);
    }
        // Khởi tạo động cơ và servo
    initializeMotors();
    initializeServo180();
    initializeServo360();
    initializeColorSensor();
}

void loop() {
    // Xử lý đầu vào từ PSP controller
    handlePSPInput();

    // Kiểm tra màu từ cảm biến
    if (isBlackBallDetected()) {
        setServoSpeed360(1, 255); // Mở servo phân loại khi có màu đen
    } else {
        setServoSpeed360(1, 0); // Dừng servo khi không phải màu đen
    }
    delay(10)
}
