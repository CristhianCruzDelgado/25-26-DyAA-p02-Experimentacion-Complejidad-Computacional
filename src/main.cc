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

#include "../include/RAM/control_unit.h"
#include "../include/RAM/input_unit.h"
#include "../include/RAM/output_unit.h"
#include "../include/RAM/program_data.h"
#include "../include/RAM/program_memory.h"
#include "../include/RAM/ram.h"

#include <exception>
#include <iostream>

const char* HELP_MESSAGE = "Help: This program executes a RAM program. \
                            \nTry: \
                            ./simulador-RAM ~ Executable \
                            xxx.ram ~ RAM Program \
                            xxx.input ~ Input tape \
                            xxx.output ~ Output tape \
                            \n";

int main(int argc, char* argv[]) {
  try {
    if (argc == 2) if (argv[1] == "--help") std::cout << HELP_MESSAGE;
    if (argc != 4) throw std::invalid_argument("Bad args");

// La ejecución comienza en la primera instrucción del programa, con todos los registros de la memoria vacíos y con los datos de entrada cargados en la cinta de entrada.
// Se ejecuta una instrucción, se modifican los registros de memoria necesarios o la cinta de salida y, acto seguido, se pasa a la ejecución de la siguiente instrucción.
// Las instrucciones READ y WRITE leen y escriben en las cintas correspondientes, y en ambos casos se avanza una posición en la cinta.
// El programa termina cuando no hay más instrucciones a ejecutar, por un error o cuando se encuentra la instrucción HALT.


  } catch (const std::exception& e) {
    std::cerr << "\nerror: " << e.what() << "\n";
    return -1;
  } catch (...) {
    std::cerr << "\nerror: ...\n";
    return -1;
  }
  return 0;
}