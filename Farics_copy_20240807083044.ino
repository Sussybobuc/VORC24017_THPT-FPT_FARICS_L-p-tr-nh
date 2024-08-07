#include "motors.h"
#include "PS2_control.h"

void setup()
{
  Serial.begin(115200);
  initMotors();         // Khởi tạo motor
  setupPS2controller(); // Thiết lập PS2 controller
  setupColorSensor();   // Thiết lập cảm biến màu
  Serial.println("Done setup!");
}

void loop()
{
  PS2control(); // Điều khiển dựa trên PS2 controller
  delay(50);    // Độ trễ giữa các lần đọc và điều khiển
}
