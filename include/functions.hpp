#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void initIndice(int n, int indice[]);

void selectionSort(int numLines, std::string *string, int * index);

void loadArchive(std::string * names, std::string * cpf, std::string * address, std::string * payload, std::ifstream& archive);

void ordenaNome(int numLines, std::string * names, int * index);