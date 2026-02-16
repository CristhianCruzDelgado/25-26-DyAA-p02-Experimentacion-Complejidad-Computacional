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

/**
 * @class InputUnit
 * @brief Represents the input unit of the RAM machine, simulating an input tape.
 */
class InputUnit {
 public:
  /** @brief Default constructor. */
  InputUnit() : 
    is_input_loaded_(false), 
    input_head_(0), 
    input_tape_() {}
  /**
   * @brief Loads integers from an input stream into the tape.
   * @param is Input stream from which integers are read.
   */
  void read(std::istream& is) { 
    for (int number; is >> number;) input_tape_.push_back(number); 
    is_input_loaded_ = true;
  }
  /**
   * @brief Returns the next integer from the tape and advances the head.
   * @return int The integer read from the tape.
   * @throw std::runtime_error If the tape has not been loaded yet.
   * @throw std::out_of_range If the head goes beyond the end of the tape.
   */
  int reading() { 
    if (!is_input_loaded_) {
      throw std::runtime_error("Missing input");
    }
    if (input_head_ < input_tape_.size()) {
      return input_tape_[input_head_++]; 
    } else {
      throw std::out_of_range("Input head out of range");
    }
  }
 private:
  bool is_input_loaded_;             ///< Indicates whether the tape has been loaded
  int input_head_;                   ///< Index of the next element to read
  std::vector<int> input_tape_;      ///< Vector storing the integers on the tape
};

/** @brief Stream extraction operator to load the tape from an input stream. */
std::istream& operator>>(std::istream& is, InputUnit& iu) { iu.read(is); return is; }

#endif
