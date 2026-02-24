#include "program_memory.h"

// Función que elimina espacios laterales de un string
static std::string trim(const std::string& s) {
  size_t start = s.find_first_not_of(" \t\n\r\f\v");
  if (start == std::string::npos) return "";
  size_t end = s.find_last_not_of(" \t\n\r\f\v");
  return s.substr(start, end - start + 1);
}

// Función que valida una instrucción
static void validateInstruction(Operation* operation, Operand* operand, const int& lineNumber) {
  bool isHalt  = dynamic_cast<Halt*>(operation);
  bool isRead  = dynamic_cast<Read*>(operation);
  bool isWrite = dynamic_cast<Write*>(operation);
  bool isStore = dynamic_cast<Store*>(operation);
  bool isJump  = dynamic_cast<Jump*>(operation);
  bool isJzero = dynamic_cast<Jzero*>(operation);
  bool isJgtz  = dynamic_cast<Jgtz*>(operation);

  bool isValue    = dynamic_cast<Value*>(operand);
  bool isDirect   = dynamic_cast<Direct*>(operand);
  bool isIndirect = dynamic_cast<Indirect*>(operand);
  bool isTag      = dynamic_cast<Tag*>(operand);

  // Comprobar que HALT no tiene operando
  if (isHalt && operand != nullptr) {
    throw std::runtime_error("HALT cannot have operand at line " + std::to_string(lineNumber));
  }

  // READ y STORE deben tener operando directo o indirecto
  if (!operand || isValue || isTag) {
    if (isRead) throw std::runtime_error("READ requires direct or indirect operand at line " + std::to_string(lineNumber));
    if (isStore) throw std::runtime_error("STORE requires direct or indirect operand at line " + std::to_string(lineNumber));
  }

  // WRITE debe tener operando directo o indirecto o valor constante
  if ((isWrite && !operand) || (isWrite && isTag)) throw std::runtime_error("WRITE requires direct or indirect operand or value at line " + std::to_string(lineNumber));
  
  // Operaciones aritméticas deben tener operando direto o indirecto o valor constante
  if (!isRead && !isWrite && !isStore && !isJump && !isJzero && !isJgtz && !isHalt) {
    if (!operand) throw std::runtime_error("Missing operand at line " + std::to_string(lineNumber));
    if (isTag) throw std::runtime_error("Arithmetic instructions cannot use label operand at line " + std::to_string(lineNumber));
  }

  //  Operaciones de control deben tener etiqueta como operando
  if (isJump || isJzero || isJgtz) {
    if (!operand) throw std::runtime_error("Jump instructions requires operand at line " + std::to_string(lineNumber));
    if (isDirect || isIndirect || isValue) throw std::runtime_error("Jump needs tag operand at line " + std::to_string(lineNumber));
  }
}

void ProgramMemory::read(std::istream& is) {
  program_memory_.clear();
  cells_memory_.clear();
  int program_memory_line = 0;
  int program_file_line = 0;

  std::string line;
  const std::regex r_tags(R"(^([a-zA-Z0-9_]+):)");
  const std::regex r_operations(R"(^\b(add|div|exp|halt|jgtz|jump|jzero|load|mul|read|store|sub|write|ADD|DIV|EXP|HALT|JGTZ|JUMP|JZERO|LOAD|MUL|READ|STORE|SUB|WRITE)\b)");
  const std::regex r_operands(R"(=(\d+)|\*(\d+)|(\d+)|([a-zA-Z0-9_]+))");

  while (std::getline(is, line)) {
    ++program_file_line;

    // Eliminar comentarios
    size_t comment_pos = line.find('#');
    if (comment_pos != std::string::npos) {
      line = line.substr(0, comment_pos);
    }

    // Saltar líneas vacías
    line = trim(line);
    if (line.empty()) continue;

    std::smatch matches;

    // Extraer etiqueta si la hay
    if (std::regex_search(line, matches, r_tags)) {
      cells_memory_[matches[1]] = program_memory_line;
      line = line.substr(matches[0].length());
      line = trim(line);
    }

    // Extraer operación
    Operation* operation = nullptr;
    if (std::regex_search(line, matches, r_operations)) {
      std::string op = matches[1].str();

      if (op == "add" || op == "ADD")          operation = new Add();
      else if (op == "sub" || op == "SUB")     operation = new Sub();
      else if (op == "mul" || op == "MUL")     operation = new Mul();
      else if (op == "div" || op == "DIV")     operation = new Div();
      else if (op == "exp" || op == "EXP")     operation = new Exp();
      else if (op == "load" || op == "LOAD")   operation = new Load();
      else if (op == "store" || op == "STORE") operation = new Store();
      else if (op == "read" || op == "READ")   operation = new Read();
      else if (op == "write" || op == "WRITE") operation = new Write();
      else if (op == "jump" || op == "JUMP")   operation = new Jump();
      else if (op == "jzero" || op == "JZERO") operation = new Jzero();
      else if (op == "jgtz" || op == "JGTZ")   operation = new Jgtz();
      else if (op == "halt" || op == "HALT")   operation = new Halt();
      else {
        throw std::runtime_error("Unknown operation at line " + std::to_string(program_file_line));
      }

      line = line.substr(matches[0].length());
      line = trim(line);

    } else {
      throw std::runtime_error("Missing operation at line " + std::to_string(program_file_line));
    }

    // Extraer operando si hay
    Operand* operand = nullptr;
    if (!line.empty()) {
      if (std::regex_search(line, matches, r_operands)) {
        if (matches[1] != "")      operand = new Value(std::stoi(matches[1]));
        else if (matches[2] != "") operand = new Indirect(std::stoi(matches[2]));
        else if (matches[3] != "") operand = new Direct(std::stoi(matches[3]));
        else if (matches[4] != "") operand = new Tag(matches[4].str());
        else {
          throw std::runtime_error("Bad operand at line " + std::to_string(program_file_line));
        }

        line = line.substr(matches[0].length());
        line = trim(line);
      }
    }
    
    if (!line.empty()) {
      throw std::runtime_error("Unexpected text at end of line " + std::to_string(program_file_line));
    }

    validateInstruction(operation, operand, program_file_line);
    Instruction instruction{operation, operand};
    program_memory_.push_back(instruction);
    ++program_memory_line;
  }
  is_program_loaded_ = true;
}