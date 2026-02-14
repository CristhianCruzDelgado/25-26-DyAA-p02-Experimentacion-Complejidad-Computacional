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

#ifndef OUTPUT_UNIT_H_
#define OUTPUT_UNIT_H_

#include <iostream>
#include <vector>

class OutputUnit {
 public:
  OutputUnit() : output_head_(0), output_tape_(std::vector<int>()) {}
  void write(std::ostream& os) const { for (const int& i : output_tape_) os << i << ""; }
  void writing(const int& i) { output_tape_.push_back(i); output_head_++; }
  private:
  int output_head_;
  std::vector<int> output_tape_;
};

std::ostream& operator<<(std::ostream& os, const OutputUnit& ou) { ou.write(os); return os; }

#endif
