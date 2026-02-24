#include "read.h"
#include "../RAM/ram.h"
#include "../operands/operand.h"

void Read::execute(Ram& ram, const Operand* operand) const {
  int register_ = operand->getRegister(ram);
  if (register_ == 0) {
    throw std::invalid_argument("Error: R0 cannot be used as an operand for the READ instruction.");
  }
  ram.getProgramData()[register_] = ram.getInputUnit().reading();
  ram.getControlUnit().incrementPC();
}