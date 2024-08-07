#include "PS2X_lib.h"
#include "MotorControl.h"
#include "ServoControl.h"
#include "ColorSensorControl.h"

MotorControl motorControl;
ServoControl servoControl;
ColorSensorControl colorSensorControl;

PS2X ps2x;

#define PS2_DAT 12
#define PS2_CMD 11
#define PS2_SEL 10
#define PS2_CLK 13

void setup() {
  Serial.begin(9600);

  if(ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false) == 0) {
    Serial.println("Found Controller, configured successful");
  } else {
    Serial.println("Controller not found, check wiring");
    while(1);
  }

  motorControl.setup();
  servoControl.setup();
  colorSensorControl.setup();
}

void loop() {
  ps2x.read_gamepad(false, 0);

  motorControl.control(ps2x.Analog(PSS_LX), ps2x.Analog(PSS_LY), ps2x.Analog(PSS_RX), ps2x.Analog(PSS_RY));
  servoControl.control(ps2x.Button(PSB_CIRCLE), ps2x.Button(PSB_L1), ps2x.Button(PSB_R1), ps2x.Button(PSB_R2));
  colorSensorControl.control();

  delay(50);
}
