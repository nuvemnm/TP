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

void saveToCSV(std::string filename, 
                double* selectionTimes_name, 
                double* selectionTimes_cpf,
                double* selectionTimes_address,
                double* quickTimes_name,
                double* quickTimes_cpf,
                double* quickTimes_address, 
                double* insertionTimes_name,
                double* insertionTimes_cpf,
                double* insertionTimes_address, 
               int length);