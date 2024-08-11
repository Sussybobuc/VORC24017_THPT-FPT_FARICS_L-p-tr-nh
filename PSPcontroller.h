#ifndef PSP_CONTROLLER_H
#define PSP_CONTROLLER_H

#include <PS2X_lib.h>  // Chắc chắn rằng thư viện PS2X_lib được bao gồm đúng cách

// Khai báo đối tượng PS2X
extern PS2X ps2x;
// Khai báo các chân kết nối PS2 controller
const int PS2_DATA = 12;
const int PS2_CMD = 13;
const int PS2_SEL = 14;
const int PS2_CLK = 15;

bool initializePSPController();
void handlePSPInput();

#endif // PSP_CONTROLLER_H
