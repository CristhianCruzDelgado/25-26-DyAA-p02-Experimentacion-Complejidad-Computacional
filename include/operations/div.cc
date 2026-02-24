#include "div.h"
#include "../RAM/ram.h"
#include "../operands/operand.h"

void Div::execute(Ram& ram, const Operand* operand) const {
  int value = operand->getOperand(ram);
  if (value == 0) {
    throw std::runtime_error("Error: division by zero at line " + std::to_string(ram.getControlUnit().getPC()));
  }
  ram.getProgramData()[0] /= value;
  ram.getControlUnit().incrementPC();
}