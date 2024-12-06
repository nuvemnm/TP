#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void initIndice(int n, int indice[]);

void selectionSort(int numLines, std::string *string, int * index);

void loadArchive(std::string * names, std::string * cpf, std::string * address, std::string * payload, std::ifstream& archive);

void selectionNameSort(int numLines, std::string * names, int * index);

void selectionCpfSort(int nunLines, std::string * cpf, int * index);

void selectionAddressSort(int numLines, std::string * address, int * index);

void quickNameSort(int numLines, std::string * names, int * index);

void quickCpfSort(int numLines, std::string * cpf, int * index);

void quickAddressSort(int numLines, std::string * address, int * index);