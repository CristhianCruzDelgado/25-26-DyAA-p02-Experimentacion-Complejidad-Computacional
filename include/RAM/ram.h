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

class RAM {
 public:
 private:
  ControlUnit control_unit_;
  InputUnit input_unit_;
  OutputUnit output_unit_;
  ProgramData program_data_;
  ProgramMemory program_memory_;
};

#endif