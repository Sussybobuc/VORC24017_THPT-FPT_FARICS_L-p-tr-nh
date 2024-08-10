#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <Adafruit_TCS34725.h>

// Khai báo đối tượng TCS34725
extern Adafruit_TCS34725 tcs;

bool initializeColorSensor();
void checkColorSensor();

#endif // COLOR_SENSOR_H
