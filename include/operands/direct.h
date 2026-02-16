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

class Direct : public Operand {
 public:
  Direct(const int& i) : register_(i) {}
  ~Direct() {}
  const int& get_operand(const ProgramData& pd, const ProgramMemory& pm) const override { return pd[register_]; }
 private:
  int register_;
};

#endif
