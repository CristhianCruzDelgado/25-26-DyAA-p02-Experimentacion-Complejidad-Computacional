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

#ifndef PROGRAM_MEMORY_H_
#define PROGRAM_MEMORY_H_

#include "../operations/operation.h"
#include "../operations/add.h"
#include "../operations/sub.h"
#include "../operations/mul.h"
#include "../operations/div.h"
#include "../operations/read.h"
#include "../operations/write.h"
#include "../operations/store.h"
#include "../operations/load.h"
#include "../operations/jump.h"
#include "../operations/jzero.h"
#include "../operations/jgtz.h"
#include "../operations/halt.h"
#include "../operands/operand.h"
#include "../operands/direct.h"
#include "../operands/indirect.h"
#include "../operands/tag.h"
#include "../operands/value.h"

#include <exception>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <utility> // <pair>
#include <vector>

class Operation;
class Operand;

typedef std::pair<Operation*, Operand*> Instruction;
typedef std::map<std::string, size_t> CellsMemory;

class ProgramMemory {
 public:
  /** @brief Default constructor. Initializes an empty program memory. */
  ProgramMemory() : 
    is_program_loaded_(false), 
    program_memory_(), 
    cells_memory_() {}
  /** declared in program_memory.cc */
  void read(std::istream&);
  /**
   * @brief Checks if a program has been loaded.
   * @return true if the program is loaded, false otherwise.
   */
  const bool& isProgramLoaded() const { return is_program_loaded_; }
  /**
   * @brief Returns the number of instructions loaded.
   * @return Number of instructions in program memory.
   */
  size_t numberOfInstructions() const { return program_memory_.size(); }
  /**
   * @brief Returns a pointer to the operation of the i-th instruction.
   * @param i Index of the instruction.
   * @return Pointer to the Operation object.
   */
  const Operation* operation(const int& i) const { return program_memory_[i].first; }
  /**
   * @brief Returns a pointer to the operand of the i-th instruction.
   * @param i Index of the instruction.
   * @return Pointer to the Operand object.
   */
  const Operand* operand(const int& i) const { return program_memory_[i].second; }
  /**
   * @brief Translates a label string to its integer address.
   * @param address Label.
   * @return Integer corresponding to the memory cell.
   */
  const size_t& translateAddress(const std::string& address) const { return cells_memory_.at(address); }
 private:
  bool is_program_loaded_;                      ///< Flag indicating if the program is loaded
  std::vector<Instruction> program_memory_;     ///< Vector storing all instructions
  CellsMemory cells_memory_;                    ///< Maps memory labels to instruction indexs
};

/**
 * @brief Overload of the extraction operator for ProgramMemory.
 * @param is Input stream.
 * @param pm ProgramMemory object to fill.
 * @return Reference to the input stream.
 */
inline std::istream& operator>>(std::istream& is, ProgramMemory& pm) { pm.read(is); return is; }

#endif
