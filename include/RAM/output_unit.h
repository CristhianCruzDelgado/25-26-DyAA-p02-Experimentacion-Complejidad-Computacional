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

/**
 * @class OutputUnit
 * @brief Simulates an output tape for a RAM machine, simulating an output tape.
 */
class OutputUnit {
 public:
  /** @brief Default constructor. */
  OutputUnit() : 
    output_head_(0), 
    output_tape_() {}
  /**
   * @brief Writes the integers of the tape to an output stream.
   * @param os Output stream where integers are write.
   */
  void write(std::ostream& os) const { 
    for (const int& number : output_tape_) os << number << ""; 
  }
  /**
   * @brief Appends a integer to the output tape and advances the head.
   * @param value The integer write to the tape.
   */
  void writing(const int& i) { 
    output_tape_.push_back(i); 
    ++output_head_; 
  }
 private:
  size_t output_head_;                ///< Index of the next element to write
  std::vector<int> output_tape_;      ///< Vector storing the integers on the tape
};

/** @brief Stream insertion operator for OutputUnit. */
std::ostream& operator<<(std::ostream& os, const OutputUnit& ou) { ou.write(os); return os; }

#endif
