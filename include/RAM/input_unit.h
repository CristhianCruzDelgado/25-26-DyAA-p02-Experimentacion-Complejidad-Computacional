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

#ifndef INPUT_UNIT_H_
#define INPUT_UNIT_H_

#include <iostream>
#include <vector>

class InputUnit {
 public:
  InputUnit() : input_head_(0), input_tape_() {}
  void read(std::istream& is) { for (int i; is >> i;) input_tape_.push_back(i); }
  const int& reading() { return input_tape_[input_head_++]; }
 private:
  int input_head_;
  std::vector<int> input_tape_;
};

std::istream& operator>>(std::istream& is, InputUnit& iu) { iu.read(is); return is; }

#endif
