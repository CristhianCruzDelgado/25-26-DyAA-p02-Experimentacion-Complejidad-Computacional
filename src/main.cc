/**
 ** Universidad de La Laguna
 * Degree: Ingeniería Informática
 * Signature: Diseño y Análisis de Algoritmos
 * Practice 02: Simulador de la máquina RAM
 * Authors: 
 *   Cristhian Adoney Cruz Delgado
 *   Michelangelo Da Cruz Bochicchio
 * Emails: 
 *   alu0101648293@ull.edu.es
 *   alu0101651217@ull.edu.es
 * Description: executes a RAM program
 */

#include "../include/RAM/ram.h"

#include <exception>
#include <fstream>
#include <iostream>

const char* HELP_MESSAGE = "Help: This program executes a RAM program. \
                            \nTry: ./simulador-RAM ~ Executable \
                            \ntestx.ram ~ RAM program file \
                            \ntestx.input ~ Input tape file \
                            \ntestx.output ~ Output tape file\n";

int main(int argc, char* argv[]) {
  try {
    if (argc == 2 && std::string(argv[1]) == "--help") {
      std::cout << HELP_MESSAGE; 
      return 0;
    }
    if (argc != 4) throw std::invalid_argument("Missing arguments");

    Ram ram;

    std::ifstream input_file(argv[1]);
    if (!input_file) throw std::runtime_error("Bad input tape file");
    ram.loadInputFile(input_file);

    std::ifstream program_file(argv[2]);
    if (!program_file) throw std::runtime_error("Bad RAM program file");
    ram.loadProgramFile(program_file);

    std::ofstream output_file(argv[3]);
    if (!output_file) throw std::runtime_error("Bad output tape file");
    ram.run(output_file);

  } catch (const std::exception& e) {
    std::cerr << "\nerror: " << e.what() << "\n";
    return -1;
  } catch (...) {
    std::cerr << "\nerror: ...\n";
    return -1;
  }
  return 0;
}