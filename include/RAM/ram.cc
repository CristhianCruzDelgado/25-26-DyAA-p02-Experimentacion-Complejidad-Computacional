#include "ram.h"
#include "control_unit.h"

Ram::Ram() : 
  control_unit_(), 
  input_unit_(), 
  output_unit_(), 
  program_data_(), 
  program_memory_() {}

ControlUnit& Ram::getControlUnit() { return control_unit_; }

const ControlUnit& Ram::getControlUnit() const { return control_unit_; }

void Ram::run(std::ofstream& output_file) {
  if (!program_memory_.isProgramLoaded()) throw std::runtime_error("Missing RAM program");
  while (true) {
    bool is_last_instruction = control_unit_.executeInstruction(*this);
    if (is_last_instruction) break;
  }
  output_file << output_unit_;
}