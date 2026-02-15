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

#ifndef PROGRAM_MEMORY_H_
#define PROGRAM_MEMORY_H_

#include "../operands/operand.h"
#include "../operations/operation.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

typedef std::string Address;
typedef std::pair<Operation*, Operand*> Instruction;
typedef std::pair<Address, Instruction> CellMemory;

class ProgramMemory {
 public:
  ProgramMemory() : program_memory_() {}
  void read(std::istream& is) {}
  Operation* operation(const int& i) const { return program_memory_[i].second.first; }
  Operand* operand(const int& i) const { return program_memory_[i].second.second; }
 private:
  /* La dirección de memoria almacena "0001", "0002", hasta encontrar una etiqueta, en ese caso será "ETIQ" */
  /* Una instrucción es una operación y un operando */
  std::vector<CellMemory> program_memory_;
};

std::istream& operator>>(std::istream& is, ProgramMemory& pm) { pm.read(is); return is; }

#endif
