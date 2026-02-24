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

#ifndef DIRECT_H_
#define DIRECT_H_

#include "operand.h"

class Operand;

class Direct : public Operand {
 public:
  Direct(const int& i) : register_(i) {}
  int getOperand(const Ram& ram) const override;
  int getRegister(const Ram& ram) const override;
 private:
  int register_;
};

#endif
