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

#ifndef EXP_H_
#define EXP_H_

#include "operation.h"

#include <cmath>

class Operand;

class Exp : public Operation {
 public:
  void execute(Ram& ram, const Operand* operand) const override;
};

#endif