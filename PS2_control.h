#ifndef PS2_CONTROL_H
#define PS2_CONTROL_H

#include <PS2X_lib.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "motors.h"

// Khởi tạo đối tượng PS2 và cảm biến màu
PS2X ps2x;
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

// Định nghĩa các chân kết nối của PS2
#define PS2_DAT 12 // MISO
#define PS2_CMD 13 // MOSI
#define PS2_SEL 15 // SS
#define PS2_CLK 14 // SLK

// Biến trạng thái cho các servo và motor
bool blockServoOpen = false;
bool pushServoOpen = false;
bool intakeMotorOn = false;
bool shootMotorOn = false;

// Hàm thiết lập PS2 controller
void setupPS2controller()
{
  int err = -1;
  while (err != 0)
  {
    err = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, true, true);
    if (err != 0)
    {
      Serial.print("Error connecting to PS2 controller, error code: ");
      Serial.println(err);
      delay(1000);
    }
  }
  Serial.println("PS2 controller connected.");
}

// Hàm thiết lập cảm biến màu
void setupColorSensor()
{
  if (tcs.begin())
  {
    Serial.println("Found color sensor");
  }
  else
  {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}

// Hàm điều khiển dựa trên PS2 controller
void PS2control()
{
  int error = ps2x.read_gamepad(false, 0);
  if (error != 0)
  {
    Serial.print("Error reading PS2 controller, error code: ");
    Serial.println(error);
    return;
  }

  // Đọc giá trị joystick
  int leftY = ps2x.Analog(PSS_LY) - 128;
  int rightY = ps2x.Analog(PSS_RY) - 128;

  // Chuyển đổi giá trị joystick thành tốc độ motor
  int leftSpeed = map(leftY, -128, 127, -MAX_PWM, MAX_PWM);
  int rightSpeed = map(rightY, -128, 127, -MAX_PWM, MAX_PWM);

  setMotorSpeed(leftSpeed, rightSpeed);

  // Điều khiển servo chặn bằng nút PS2
  if (ps2x.ButtonPressed(PSB_CIRCLE))
  {
    blockServoOpen = !blockServoOpen;
    setBlockServo(blockServoOpen);
  }

  // Điều khiển servo ép bằng nút PS2
  if (ps2x.ButtonPressed(PSB_L1))
  {
    pushServoOpen = !pushServoOpen;
    setPushServo(pushServoOpen);
  }

  // Điều khiển motor intake bằng nút PS2
  if (ps2x.ButtonPressed(PSB_R1))
  {
    intakeMotorOn = !intakeMotorOn;
    setMotorIntake(intakeMotorOn ? MAX_PWM : 0);
  }

  // Điều khiển motor bắn bằng nút PS2
  if (ps2x.ButtonPressed(PSB_SQUARE))
  {
    shootMotorOn = !shootMotorOn;
    setMotorShoot(shootMotorOn ? MAX_PWM : 0);
  }

  // Đọc giá trị từ cảm biến màu
  uint16_t clear, red, green, blue;
  tcs.getRawData(&red, &green, &blue, &clear);

  // Tính toán nhiệt độ màu và lux
  float colorTemp = tcs.calculateColorTemperature_dn40(red, green, blue, clear);
  float lux = tcs.calculateLux(red, green, blue);

  Serial.print("C: "); Serial.print(clear); 
  Serial.print(" R: "); Serial.print(red); 
  Serial.print(" G: "); Serial.print(green); 
  Serial.print(" B: "); Serial.print(blue); 
  Serial.print(" Lux: "); Serial.print(lux);
  Serial.print(" Color Temp: "); Serial.println(colorTemp);

  // Phát hiện màu đen và màu trắng để điều khiển servo phân loại
  if (red < 50 && green < 50 && blue < 50)
  {
    setSortServo(true); // Mở servo phân loại khi phát hiện màu đen
    Serial.println("Detected black ball, opening sort servo.");
  }
  else
  {
    setSortServo(false); // Đóng servo phân loại khi không phát hiện màu đen
    Serial.println("Detected non-black ball, closing sort servo.");
  }
}

#endif
