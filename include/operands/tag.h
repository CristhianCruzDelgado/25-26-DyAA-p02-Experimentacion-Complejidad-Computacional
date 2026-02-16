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

#ifndef TAG_H_
#define TAG_H_

#include "operand.h"

class Tag : public Operand {
 public:
  Tag(const std::string s) : tag_(s) {}
  ~Tag() {}
  const int& get_operand(const ProgramData& pd, const ProgramMemory& pm) const override { return pm.translateAddress(tag_); }
 private:
  std::string tag_;
};

#endif
