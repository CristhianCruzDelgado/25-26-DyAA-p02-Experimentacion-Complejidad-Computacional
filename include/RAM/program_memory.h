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

typedef std::pair<Operation*, Operand*> Instruction;
typedef std::map<std::string, size_t> CellsMemory;

class ProgramMemory {
 public:
  /** @brief Default constructor. Initializes an empty program memory. */
  ProgramMemory() : 
    is_program_loaded_(false), 
    program_memory_(), 
    cells_memory_() {}
  /** declared below */
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
std::istream& operator>>(std::istream& is, ProgramMemory& pm) { pm.read(is); return is; }

/**
 * @brief Reads the program from an input stream line by line.
 * The method performs the following steps for each line of the input:
 *   1. Ignores empty lines and comment lines.
 *   2. Detects labels (e.g., "0001", "ETIQ", "LOOP") and maps them to the current instruction index.
 *   3. Identifies the operation, creating the corresponding Operation object (e.g., ADD, DIV, HALT).
 *   4. Identifies the operand, creating the corresponding Operand object (e.g., Value, Direct, Indirect).
 *   5. Combines the operation and operand into an Instruction and appends it
 *      to the program memory vector, maintaining the instruction index.
 * After processing all lines, the program is marked as loaded.
 * @param is Input stream containing the program.
 * @throws std::invalid_argument if an operation or operand is missing or invalid.
 */
void ProgramMemory::read(std::istream& is) {
  program_memory_.clear();
  cells_memory_.clear();
  int program_memory_line = 0;
  int program_file_line = 0;
  std::string line;
  const std::regex r_empty(R"(^\s*$)");
  const std::regex r_comments(R"(#.*)");
  const std::regex r_tags(R"(^([a-zA-Z]+):)");
  const std::regex r_operations(R"(\b(add|div|halt|jgtz|jump|jzero|load|mul|read|store|sub|write|ADD|DIV|HALT|JGTZ|JUMP|JZERO|LOAD|MUL|READ|STORE|SUB|WRITE)\b)");
  const std::regex r_operands(R"(=(\d+)|\*(\d+)|(\d+)|([a-zA-Z]+))");
  while (std::getline(is, line)) {
    ++program_file_line;
    if (std::regex_match(line, r_empty)) continue;
    if (std::regex_match(line, r_comments)) continue;
    std::smatch matches;
    if (std::regex_search(line, matches, r_tags)) cells_memory_[matches[1]] = program_memory_line;

    Operation* operation = nullptr;
    if (std::regex_search(line, matches, r_operations)) {
      operation = nullptr; /* implementar */
    } else {
      throw std::invalid_argument("Missing operation: " + std::to_string(program_file_line));
    }

    Operand* operand = nullptr;
    if (std::regex_search(line, matches, r_operands)) {
      if (matches[1] != "") {
        operand = new Value(std::stoi(matches[1]));
      } else if (matches[2] != "") {
        operand = new Indirect(std::stoi(matches[2]));
      } else if (matches[3] != "") {
        operand = new Direct(std::stoi(matches[3]));
      } else if (matches[4] != "") {
        operand = new Tag(matches[4].str());
      } else {
        throw std::invalid_argument("Bad operand: " + std::to_string(program_file_line));
      }
    }

    Instruction instruction {operation, operand};
    program_memory_.push_back(instruction);
    ++program_memory_line;
  }
  is_program_loaded_ = true;
}

#endif
