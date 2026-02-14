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

#ifndef CONTROL_UNIT_H_
#define CONTROL_UNIT_H_

class ControlUnit {
 public:
  ControlUnit() : pc_(0) {} 
  /* No sé si esto se hace aquí */
  /* Ejecuta instrucciones */
  /* 1. get_operation() */
  /* 2. get_operand() */
  /* 3. ejecutar operation sobre operand */
  /* 4.1. leer o escribir si procede 4.2. actualizar contador */
  /* 5.2. incrementar contador */
 private:
  /* Program counter es el índice del programa de memoria */
  int pc_;
};

#endif
