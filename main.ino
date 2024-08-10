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
}

void loop() {
    handlePSPInput();
    checkColorSensor();
    delay(10); // Thêm một độ trễ nhỏ để giảm tải cho vi điều khiển
}

