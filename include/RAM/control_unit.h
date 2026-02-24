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

#ifndef CONTROL_UNIT_H_
#define CONTROL_UNIT_H_

#include "../operations/operation.h"
#include "../operands/operand.h"

class Ram;

class ControlUnit {
 public:
  ControlUnit() : pc_(0), halt_(false) {} 

  size_t getPC() const { return pc_; }
  void setPC(const size_t& address) { pc_ = address; }
  void incrementPC() { ++pc_; }

  void setHalt() { halt_ = true; }
  bool isHalt() const { return halt_; }

  bool executeInstruction(Ram& ram);
  
 private:
  /* Program counter es cada índice del vector */
  size_t pc_;
  bool halt_;
};

#endif
