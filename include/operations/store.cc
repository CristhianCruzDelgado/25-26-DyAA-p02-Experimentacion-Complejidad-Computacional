#include "store.h"
#include "../RAM/ram.h"
#include "../operands/operand.h"

void Store::execute(Ram& ram, const Operand* operand) const {
  int register_ = operand->getRegister(ram);
  ram.getProgramData()[register_] = ram.getProgramData()[0];
  ram.getControlUnit().incrementPC();
}