#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int readHeader(std::ifstream& arquivo);

void initIndice(int n, int indice[]);

void selectionSort(int numLines, std::string * string, int *index);

void loadArchive(std::string * names, std::string * cpf, std::string * address, std::string * payload, std::ifstream& archive);

void leArquivo(std::ifstream& arquivo);

void ordenaNome(int numLines, std::string * names, std::string * cpf, std::string * address, std::string * payload);