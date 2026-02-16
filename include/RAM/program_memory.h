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

#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<Operation*, Operand*> Instruction;
typedef std::map<std::string, int> CellsMemory;

class ProgramMemory {
 public:
  ProgramMemory() : 
    is_program_loaded_(false), 
    instructions_(0), 
    program_memory_(), 
    cells_memory_() {}
  void read(std::istream&);
  const Operation* operation(const int& i) const { return program_memory_[i].first; }
  const Operand* operand(const int& i) const { return program_memory_[i].second; }
  int translateAddress(const std::string& address) const { return cells_memory_.at(address); }


  // Ignorar, aunque es necesario
  const bool isProgramLoaded() const { return is_program_loaded_; }
  const int instructions() const { return program_memory_.size(); }
  // - - - - -
 private:
  std::vector<Instruction> program_memory_;
  /* Se asocia cada (índice del vector ^^^) dirección de memoria con un nombre "0001", "0002", "ETIQ", ... */
  CellsMemory cells_memory_;


  // Ignorar, aunque es necesario
  bool is_program_loaded_;
  int instructions_;
  // - - - - -
};

std::istream& operator>>(std::istream& is, ProgramMemory& pm) { pm.read(is); return is; }

void ProgramMemory::read(std::istream& is) {
  program_memory_.clear();
  cells_memory_.clear();
  int line_number = 0;
  std::string line;
  const std::regex r_empty(R"(^\s*$)");
  const std::regex r_comments(R"(#.*)");
  const std::regex r_tags(R"(^([a-zA-Z]+):)");
  const std::regex r_operations(R"(\b(add|div|halt|jgtz|jump|jzero|load|mul|read|store|sub|write|ADD|DIV|HALT|JGTZ|JUMP|JZERO|LOAD|MUL|READ|STORE|SUB|WRITE)\b)");
  const std::regex r_operands(R"(=(\d+)|\*(\d+)|(\d+)|([a-zA-Z]+))");
  while (std::getline(is, line)) {
    if (std::regex_match(line, r_empty)) continue;
    if (std::regex_match(line, r_comments)) continue;
    std::smatch matches;
    if (std::regex_search(line, matches, r_tags)) {
      cells_memory_[matches[1]] = line_number;
    }
    Operation* operation = nullptr;
    if (std::regex_search(line, matches, r_operations)) {
      operation = nullptr; /* implementar */
    } else {
      throw std::invalid_argument("Missing operation");
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
        throw std::invalid_argument("Bad operand");
      }
    }
    Instruction instruction {operation, operand};
    program_memory_.push_back(instruction);
    ++line_number;
  }
  is_program_loaded_ = true;
}

#endif
