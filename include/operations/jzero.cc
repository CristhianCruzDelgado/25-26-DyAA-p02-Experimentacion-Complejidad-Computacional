#include "jzero.h"
#include "../RAM/ram.h"
#include "../operands/operand.h"

void Jzero::execute(Ram& ram, const Operand* operand) const {
  if (ram.getProgramData()[0] == 0) {
    int address = operand->getOperand(ram);
    ram.getControlUnit().setPC(static_cast<size_t>(address));
  } else {
    ram.getControlUnit().incrementPC();
  }
}