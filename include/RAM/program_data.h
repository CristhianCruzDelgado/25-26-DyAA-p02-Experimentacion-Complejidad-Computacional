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

#ifndef PROGRAM_DATA_H_
#define PROGRAM_DATA_H_

#include <vector>

class ProgramData {
 public:
  ProgramData() : program_data_(std::vector<int>(32, 0)) {}
  const int acc() const { return program_data_[0]; }
  int& operator[](const int& i) { return program_data_[i]; }
  const int& operator[](const int& i) const { return program_data_[i]; }
 private:
  /* de los índices 0 a 31 suponemos que contenemos todos los registros */
  /* el registro 0 es el acumulador */
  std::vector<int> program_data_;
};

#endif
