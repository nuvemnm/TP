#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void initIndice(int n, int indice[]);

void selectionSort(std::string *string, int * index, int tam);

int partition(std::string * array, int * index, int low, int high);

void quickSort(std::string * array, int * index, int low, int high);

void insertionSort(std::string * array,int * index, int tam);

void loadArchive(std::string * names, std::string * cpf, std::string * address, std::string * payload, std::ifstream& archive);

void printOutput(int * index, std::string * header, std::string * names, std::string * cpf, std::string * address, std::string * payload, int n);