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

#ifndef OPERATION_H_
#define OPERATION_H_

#include "../operands/operand.h"

class Operation {
 public:
  virtual ~Operation() = 0;
  virtual void execute(const Operand*, const Operand*) const = 0;
 private:
};

#endif