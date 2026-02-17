/**
 * Universidad de La Laguna
 * Degree: Ingeniería Informática
 * Signature: Diseño y Análisis de Algoritmos
 * Practice 02: Simulador de la máquina RAM
 * Authors: 
 *   Cristhian Adoney Cruz Delgado
 *   Michelangelo Da Cruz Bochicchio
 * Emails: 
 *   alu0101648293@ull.edu.es
 *   alu0101651217@ull.edu.es
 */

#ifndef RAM_H_
#define RAM_H_

#include "control_unit.h"
#include "input_unit.h"
#include "output_unit.h"
#include "program_data.h"
#include "program_memory.h"

#include <fstream>

class Ram {
 public:
  Ram() : 
    control_unit_(), 
    input_unit_(), 
    output_unit_(), 
    program_data_(), 
    program_memory_() {}
  void loadInputFile(std::ifstream& input_file) { input_file >> input_unit_; }
  void loadProgramFile(std::ifstream& program_file) { program_file >> program_memory_; }
  void run(std::ofstream& output_file) {
    if (!program_memory_.isProgramLoaded()) throw std::runtime_error("Missing RAM program");
    while (true) {
      bool is_last_instruction = control_unit_.executeInstruction(input_unit_, output_unit_, program_data_, program_memory_);
      if (is_last_instruction) break;
    }
    output_file << output_unit_;
  }
 private:
  ControlUnit control_unit_;
  InputUnit input_unit_;
  OutputUnit output_unit_;
  ProgramData program_data_;
  ProgramMemory program_memory_;
};

#endif