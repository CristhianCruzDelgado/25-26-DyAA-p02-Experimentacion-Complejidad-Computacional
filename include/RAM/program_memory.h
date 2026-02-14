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

#include <string>
#include <utility>
#include <vector>

typedef std::string Address;
typedef std::pair<Operation*, Operand*> Instruction;

class ProgramMemory {
 public:
  ProgramMemory(int& number_of_instructions)
    : program_memory_(std::vector<std::pair<Address, Instruction>>(number_of_instructions, std::pair("0000", std::pair(nullptr, nullptr)))) {}
  Operation* operation(const int& i) const { return program_memory_[i].second.first; }
  Operand* operand(const int& i) const { return program_memory_[i].second.second; }
 private:
  /* La dirección de memoria almacena "0001", "0002", hasta encontrar una etiqueta, en ese caso será "ETIQ" */
  /* Una instrucción es una operación y un operando */
  std::vector<std::pair<Address, Instruction>> program_memory_;
};

#endif
