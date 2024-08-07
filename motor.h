#ifndef MOTORS_H
#define MOTORS_H

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Định nghĩa giá trị PWM tối thiểu và tối đa
#define MIN_PWM 0
#define MAX_PWM 4095

// Định nghĩa các kênh PWM cho các motor và servo
#define PWM_CHANNEL_LEFT_FORWARD 8
#define PWM_CHANNEL_LEFT_BACKWARD 9
#define PWM_CHANNEL_RIGHT_FORWARD 10
#define PWM_CHANNEL_RIGHT_BACKWARD 11
#define PWM_CHANNEL_SHOOT 12
#define PWM_CHANNEL_INTAKE 13
#define PWM_CHANNEL_BLOCK_SERVO 0
#define PWM_CHANNEL_PUSH_SERVO 1
#define PWM_CHANNEL_SORT_SERVO 2

// Định nghĩa góc mở và đóng của các servo
#define BLOCK_SERVO_OPEN 204  // Góc mở của servo chặn
#define BLOCK_SERVO_CLOSE 410 // Góc đóng của servo chặn
#define PUSH_SERVO_OPEN 204   // Góc mở của servo ép
#define PUSH_SERVO_CLOSE 410  // Góc đóng của servo ép
#define SORT_SERVO_NORMAL 204 // Góc bình thường của servo phân loại
#define SORT_SERVO_PUSH 410   // Góc đẩy của servo phân loại

// Khởi tạo driver PWM
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Hàm cài đặt giá trị PWM cho hai kênh
void setPWM(int chan1, int chan2, uint16_t val1, uint16_t val2)
{
  pwm.setPWM(chan1, 0, val1);
  pwm.setPWM(chan2, 0, val2);
}

// Hàm cài đặt tốc độ motor
void setMotorSpeed(int leftSpeed, int rightSpeed)
{
  // Điều khiển motor bên trái
  if (leftSpeed > 0)
  {
    setPWM(PWM_CHANNEL_LEFT_FORWARD, PWM_CHANNEL_LEFT_BACKWARD, leftSpeed, 0);
  }
  else
  {
    setPWM(PWM_CHANNEL_LEFT_FORWARD, PWM_CHANNEL_LEFT_BACKWARD, 0, -leftSpeed);
  }

  // Điều khiển motor bên phải
  if (rightSpeed > 0)
  {
    setPWM(PWM_CHANNEL_RIGHT_FORWARD, PWM_CHANNEL_RIGHT_BACKWARD, rightSpeed, 0);
  }
  else
  {
    setPWM(PWM_CHANNEL_RIGHT_FORWARD, PWM_CHANNEL_RIGHT_BACKWARD, 0, -rightSpeed);
  }
}

// Hàm khởi tạo motor
void initMotors()
{
  Wire.begin();
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);
  Wire.setClock(400000);
  setMotorSpeed(0, 0);
}

// Hàm cài đặt tốc độ motor bắn
void setMotorShoot(int speed)
{
  setPWM(PWM_CHANNEL_SHOOT, PWM_CHANNEL_SHOOT, speed, 0);
}

// Hàm cài đặt tốc độ motor intake
void setMotorIntake(int speed)
{
  setPWM(PWM_CHANNEL_INTAKE, PWM_CHANNEL_INTAKE, speed, 0);
}

// Hàm cài đặt trạng thái mở/đóng của servo chặn
void setBlockServo(bool open)
{
  pwm.setPWM(PWM_CHANNEL_BLOCK_SERVO, 0, open ? BLOCK_SERVO_OPEN : BLOCK_SERVO_CLOSE);
}

// Hàm cài đặt trạng thái mở/đóng của servo ép
void setPushServo(bool open)
{
  pwm.setPWM(PWM_CHANNEL_PUSH_SERVO, 0, open ? PUSH_SERVO_OPEN : PUSH_SERVO_CLOSE);
}

// Hàm cài đặt trạng thái phân loại của servo phân loại
void setSortServo(bool push)
{
  pwm.setPWM(PWM_CHANNEL_SORT_SERVO, 0, push ? SORT_SERVO_PUSH : SORT_SERVO_NORMAL);
}

#endif

