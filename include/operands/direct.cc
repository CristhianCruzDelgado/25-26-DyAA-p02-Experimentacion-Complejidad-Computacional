#include "direct.h"
#include "../RAM/ram.h"

int Direct::getOperand(const Ram& ram) const { return ram.getProgramData()[register_]; }
int Direct::getRegister(const Ram& ram) const { return register_; }