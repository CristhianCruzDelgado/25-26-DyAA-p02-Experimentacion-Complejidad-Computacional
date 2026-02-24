#include "indirect.h"
#include "../RAM/ram.h"

int Indirect::getOperand(const Ram& ram) const { return ram.getProgramData()[ram.getProgramData()[register_]]; }
int Indirect::getRegister(const Ram& ram) const { return ram.getProgramData()[register_]; }




