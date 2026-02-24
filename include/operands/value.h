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

#ifndef VALUE_H_
#define VALUE_H_

#include "operand.h"

class Value : public Operand {
 public:
  Value(const int& i) : value_(i) {}
  int getOperand(const Ram& ram) const override { return value_; }
 private:
  int value_;
};

#endif
