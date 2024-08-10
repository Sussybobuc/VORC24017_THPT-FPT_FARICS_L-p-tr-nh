#ifndef PSP_CONTROLLER_H
#define PSP_CONTROLLER_H

#include <PS2X_lib.h>

// Khai báo đối tượng PS2X
extern PS2X ps2x;

bool initializePSPController();
void handlePSPInput();

#endif // PSP_CONTROLLER_H
