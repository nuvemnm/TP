#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void initIndice(int n, int indice[]);

void merge(std::string * array, int * index, int left, int mid, int right);

void mergeSort(std::string * array, int * index, int left, int right);

int partition(std::string * array, int * index, int low, int high);

void quickSort(std::string * array, int * index, int low, int high);

void shellSort(std::string * array, int * index, int n);

void loadArchive(std::string * names, std::string * cpf, std::string * address, std::string * payload, std::ifstream& archive);

void printOutput(int * index, std::string * header, std::string * names, std::string * cpf, std::string * address, std::string * payload, int n);

void saveToCSV( std::string filename, std::string charges[], double * selectionTimes, double * quickTimes, double * insertionTimes);

