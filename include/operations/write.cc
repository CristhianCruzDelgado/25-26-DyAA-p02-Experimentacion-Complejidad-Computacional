#include "write.h"
#include "../RAM/ram.h"
#include "../operands/operand.h"

void Write::execute(Ram& ram, const Operand* operand) const {
  if (dynamic_cast<Direct*>(const_cast<Operand*>(operand))) {
    int register_ = operand->getRegister(ram);
    if (register_ == 0) {
      throw std::invalid_argument("Error: R0 cannot be used as an operand for the WRITE instruction.");
    }
  }
  int value = operand->getOperand(ram);
  ram.getOutputUnit().writing(value);
  ram.getControlUnit().incrementPC();
}