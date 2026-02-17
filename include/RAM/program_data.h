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

#include <exception>
#include <vector>

/**
 * @class ProgramData
 * @brief Represents the register memory of the RAM machine.
 */
class ProgramData {
 public:
  /** @brief Default constructor. */
  ProgramData() : 
    program_data_(std::vector<int>(32, 0)) {}
  /**
   * @brief Access register by index (modifiable).
   * @param i Register index.
   * @return Reference to register value.
   * @throws std::out_of_range If index is outside valid range [0,31].
   */
  int& operator[](const size_t& i) { 
    if (i < 0 || i >= program_data_.size()) throw std::out_of_range("Register out of range");
    return program_data_[i]; 
  }
  /**
   * @brief Access register by index (read-only).
   * @param i Register index.
   * @return Const reference to register value.
   * @throws std::out_of_range If index is outside valid range [0,31].
   */
  const int& operator[](const size_t& i) const {
    if (i < 0 || i >= program_data_.size()) throw std::out_of_range("Register out of range");
    return program_data_[i]; 
  }
 private:
  /* de los índices 0 a 31 suponemos que contenemos todos los registros */
  /* el registro 0 es el acumulador */
  std::vector<int> program_data_; /* Para el apto+ considerar vector de vectores */
};

#endif
