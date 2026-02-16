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

#ifndef OPERAND_H_
#define OPERAND_H_

#include "../RAM/program_data.h"
#include "../RAM/program_memory.h"

class Operand {
 public:
  virtual ~Operand() = 0;
  virtual const int& get_operand(const ProgramData&, const ProgramMemory&) const = 0;
 private:
};

#endif
