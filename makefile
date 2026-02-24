## Universidad de La Laguna
# Degree: Ingeniería Informática
# Signature: Diseño y Análisis de Algoritmos
# Practice 02: Simulador de la máquina RAM
# Authors: 
#   Cristhian Adoney Cruz Delgado
#   Michelangelo Da Cruz Bochicchio
# Emails: 
#   alu0101648293@ull.edu.es
#   alu0101651217@ull.edu.es
# Description: organizer code

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

EXE = simulador-RAM

SRC = $(shell find src include -name "*.cc")
OBJ = $(SRC:.cc=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	find src include -name "*.o" -delete
	rm -f $(EXE)

.PHONY: clean
