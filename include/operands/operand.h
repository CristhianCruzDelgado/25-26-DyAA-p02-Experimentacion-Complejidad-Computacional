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

#include <stdexcept>

class Ram;

class Operand {
 public:
  virtual ~Operand() = default;
  virtual int getOperand(const Ram& ram) const = 0;
  virtual int getRegister(const Ram& ram) const;
};

#endif
