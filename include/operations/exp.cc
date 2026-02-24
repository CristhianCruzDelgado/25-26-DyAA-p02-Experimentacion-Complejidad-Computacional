#include "exp.h"
#include "../RAM/ram.h"
#include "../operands/operand.h"

void Exp::execute(Ram& ram, const Operand* operand) const {
  int value = operand->getOperand(ram);
  ram.getProgramData()[0] = std::pow(ram.getProgramData()[0], value);
  ram.getControlUnit().incrementPC();
}