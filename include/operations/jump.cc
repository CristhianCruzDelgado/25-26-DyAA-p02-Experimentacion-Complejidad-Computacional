#include "jump.h"
#include "../RAM/ram.h"
#include "../operands/operand.h"

void Jump::execute(Ram& ram, const Operand* operand) const {
  int address = operand->getOperand(ram);
  ram.getControlUnit().setPC(static_cast<size_t>(address));
}