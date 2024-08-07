#ifndef COLOR_SENSOR_CONTROL_H
#define COLOR_SENSOR_CONTROL_H

#include <Adafruit_TCS34725.h>

class ColorSensorControl {
  public:
    void setup();
    void control();
  
  private:
    Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
    void processColor();
};

#endif
