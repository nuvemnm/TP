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

void selectionNameSort(int tam, std::string * names, int * index);

void selectionCpfSort(int nunLines, std::string * cpf, int * index);

void selectionAddressSort(int tam, std::string * address, int * index);

void quickNameSort(int tam, std::string * names, int * index);

void quickCpfSort(int tam, std::string * cpf, int * index);

void quickAddressSort(int tam, std::string * address, int * index);

void insetionNameSort(std::string * names, int * index, int tam);

void insetionCpfSort(std::string * cpf, int * index, int tam);

void insetionAddressSort(std::string * address, int * index, int tam);