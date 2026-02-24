#include "operand.h"
#include "../RAM/ram.h"

int Operand::getRegister(const Ram& ram) const {
  throw std::invalid_argument("Error: not valid operand for operation at line " + std::to_string(ram.getControlUnit().getPC()));
}
