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
CXXFLAGS = -std=c++17 -Wall

EXE = simulador-RAM
SRC = $(wildcard src/*.cc)
OBJ = $(SRC:.cc=.o)

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(EXE)

.PHONY: clean
