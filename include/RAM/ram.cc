#include "ram.h"
#include "control_unit.h"

void Ram::run(std::ofstream& output_file) {
  if (!program_memory_.isProgramLoaded()) throw std::runtime_error("Missing RAM program");
  while (true) {
    bool is_last_instruction = control_unit_.executeInstruction(*this);
    if (is_last_instruction) break;
  }
  output_file << output_unit_;
}