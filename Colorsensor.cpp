#include "ColorSensor.h"
#include <Arduino.h>
#include "ServoControl.h"

// Khởi tạo đối tượng TCS34725
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

bool initializeColorSensor() {
    if (tcs.begin()) {
        Serial.println("Found color sensor");
        return true;
    } else {
        Serial.println("No TCS34725 found ... check your connections");
        return false;
    }
}

void checkColorSensor() {
    uint16_t r, g, b, c;
    tcs.getRawData(&r, &g, &b, &c);

    uint16_t colorTemp = tcs.calculateColorTemperature(r, g, b);
    uint16_t lux = tcs.calculateLux(r, g, b);

    if (colorTemp < 3000) {
        setServoAngle(5, 180); // Mở servo phân loại
    } else {
        setServoAngle(5, 0); // Đóng servo phân loại
    }
}
