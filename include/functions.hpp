#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int readHeader(std::ifstream& arquivo);
void selectionSort(int field, int numLine, std::string * string);
void leArquivo(std::ifstream& arquivo);
void ordenaNome(std::ifstream& arquivo);