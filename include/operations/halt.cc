#include "halt.h"
#include "../RAM/ram.h"

void Halt::execute(Ram& ram, const Operand* operand) const {
  ram.getControlUnit().setHalt();
}