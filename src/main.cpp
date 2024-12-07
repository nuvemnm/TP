#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/functions.hpp"



int main(int argc, char *argv[]){

    std::ifstream arquivo(argv[1]);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return 0;
    }

    std::string lines = "";
    std::string header[6];
    for(int i = 0; i < 6; i++){
        getline(arquivo, lines);
        header[i] = lines;
    }
    
    int n = std::stoi(lines);

    int *index = new int[n];


    std::string *names = new std::string[n];
    std::string *cpf = new std::string[n];
    std::string *address = new std::string[n];
    std::string *payload = new std::string[n];
    
    loadArchive(names,cpf, address, payload, arquivo);

    
    //============================================================= SELECTION SORT =============================================================
    
    //Ordenação por nome
    initIndice(n, index);
    selectionSort(names, index, n);
     
    printOutput(index, header, names, cpf, address, payload, n);

    //Ordenação por CPF
    initIndice(n, index);
    selectionSort(cpf, index, n);

    printOutput(index, header, names, cpf, address, payload, n);

    //Ordenação por endereço
    initIndice(n, index);
    selectionSort(address, index, n);

    printOutput(index, header, names, cpf, address, payload, n);

    //=============================================================== QUICKSORT ===============================================================
    
    //Ordenação por nome
    initIndice(n, index);
    quickSort(names, index, 0, n - 1);

    printOutput(index, header, names, cpf, address, payload, n);
    
    //Ordenação por CPF
    initIndice(n, index);
    quickSort(cpf, index, 0, n - 1);

    printOutput(index, header, names, cpf, address, payload, n);

    //Ordenação por endereço
    initIndice(n, index);
    quickSort(address, index, 0, n - 1);

    printOutput(index, header, names, cpf, address, payload, n);

    //=============================================================== INSERTION SORT ===============================================================

    //Ordenação por nome
    initIndice(n, index);
    insertionSort(names, index, n);

    printOutput(index, header, names, cpf, address, payload, n);

   //Ordenação por CPF
    initIndice(n, index);
    insertionSort(cpf, index, n);

    printOutput(index, header, names, cpf, address, payload, n);
    
    //Ordenação por endereço
    initIndice(n, index);
    insertionSort(address, index, n);

    printOutput(index, header, names, cpf, address, payload, n);
    
    delete[] names;
    delete[] cpf;
    delete[] address;
    delete[] payload;
    delete[] index;

    return 0;

}
