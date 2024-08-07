#include "ColorSensorControl.h"

void ColorSensorControl::setup() {
  if (tcs.begin()) {
    Serial.println("Found color sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}

void ColorSensorControl::control() {
  processColor();
}

void ColorSensorControl::processColor() {
  uint16_t r, g, b, c;
  tcs.getRawData(&r, &g, &b, &c);
  uint32_t sum = c;
  float red = r; red /= sum;
  float green = g; green /= sum;
  float blue = b; blue /= sum;

  if (red < 0.2 && green < 0.2 && blue < 0.2) {
    // Phát hiện màu đen
    // Mở servo phân loại
    pwm.setPWM(6, 0, 2048);
  } else if (red > 0.8 && green > 0.8 && blue > 0.8) {
    // Phát hiện màu trắng
    // Đóng servo phân loại
    pwm.setPWM(6, 0, 0);
  }
}
