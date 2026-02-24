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

class Ram;
class Operand;

class Operation {
 public:
  virtual ~Operation() = default;
  virtual void execute(Ram& ram, const Operand* operand) const = 0;
 private:
};

#endif