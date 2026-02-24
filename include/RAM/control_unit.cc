#include "control_unit.h"
#include "ram.h"

bool ControlUnit::executeInstruction(Ram& ram) {
  if (halt_ || pc_ >= ram.getProgramMemory().numberOfInstructions() ) return true;
  const Operation* operation = ram.getProgramMemory().operation(pc_);
  const Operand* operand = ram.getProgramMemory().operand(pc_);
  operation->execute(ram, operand); 
  
  return halt_;
  }