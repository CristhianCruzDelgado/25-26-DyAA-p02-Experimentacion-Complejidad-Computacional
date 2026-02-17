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

#include "input_unit.h"
#include "output_unit.h"
#include "program_data.h"
#include "program_memory.h"
#include "../operations/operation.h"
#include "../operands/operand.h"

#include <fstream>

class ControlUnit {
 public:
  ControlUnit() : pc_(0) {} 
  /* 1. get_operation() */
  /* 2. get_operand() */
  /* 3. ejecutar operation sobre operand */
  /* 4.1. manejar resultado 4.2. actualizar contador */                       //
  /* 5.1. incrementar contador */                                             // Implementar
  // 4.1: leer o escribir si procede, dar por finalizado el resultado, ...    //
  bool executeInstruction(const InputUnit& iu, const OutputUnit& ou, const ProgramData& pd, const ProgramMemory& pm) {
    if (pc_ > pm.numberOfInstructions()) return true;
    const Operation* operation = pm.operation(pc_);
    const Operand* acc = new Direct(0);
    const Operand* operand = pm.operand(pc_);
    operation->execute(acc, operand); // la operación puede necesitará leer o escribir y habrá que pasarle el parámetro ya sea de lista de entrada o de los registros 
    /* Implementar */
    return false;
  }
 private:
  /* Program counter es cada índice del vector */
  size_t pc_;
};

#endif
