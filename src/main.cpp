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
    //arquivo.seekg(0, std::ios::beg);
    loadArchive(names,cpf, address, payload, arquivo);

    
    //============================================================= SELECTION SORT =============================================================
    //Ordenação por nome
    selectionNameSort(n, names, index);
     
    for (int i = 0; i < 6; i++)
    {
        std::cout << header[i] << std::endl;
    }
   
    for (int i = 0; i < n; i++)
    {
        std::cout << names[index[i]] << "," << cpf[index[i]] << "," << address[index[i]] << "," << payload[index[i]] << std::endl;
    }
    
    //Ordenação por CPF
    selectionCpfSort(n, cpf, index);

    for (int i = 0; i < 6; i++)
    {
        std::cout << header[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << names[index[i]] << "," << cpf[index[i]] << "," << address[index[i]] << "," << payload[index[i]] << std::endl;
    }

    //Ordenação por endereço
    selectionAddressSort(n, address, index);

    for (int i = 0; i < 6; i++)
    {
        std::cout << header[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << names[index[i]] << "," << cpf[index[i]] << "," << address[index[i]] << "," << payload[index[i]] << std::endl;
    }

    //=============================================================== QUICKSORT ===============================================================
    //Ordenação por nome
    quickNameSort(n, names, index);

    for (int i = 0; i < 6; i++)
    {
        std::cout << header[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << names[index[i]] << "," << cpf[index[i]] << "," << address[index[i]] << "," << payload[index[i]] << std::endl;
    }
    
    //Ordenação por CPF
    quickCpfSort(n, cpf, index);

    for (int i = 0; i < 6; i++)
    {
        std::cout << header[i] << std::endl;
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cout << names[index[i]] << "," << cpf[index[i]] << "," << address[index[i]] << "," << payload[index[i]] << std::endl;
    }

    //Ordenação por endereço
    quickAddressSort(n, address, index);

    for (int i = 0; i < 6; i++)
    {
        std::cout << header[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << names[index[i]] << "," << cpf[index[i]] << "," << address[index[i]] << "," << payload[index[i]] << std::endl;
    }
    //=============================================================== INSERTION SORT ===============================================================

    //Ordenação por nome
    insetionNameSort(names, index, n);

    for (int i = 0; i < 6; i++)
    {
        std::cout << header[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << names[index[i]] << "," << cpf[index[i]] << "," << address[index[i]] << "," << payload[index[i]] << std::endl;
    }
   //Ordenação por CPF
    insetionCpfSort(cpf, index, n);

    for (int i = 0; i < 6; i++)
    {
        std::cout << header[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << names[index[i]] << "," << cpf[index[i]] << "," << address[index[i]] << "," << payload[index[i]] << std::endl;
    }
    
    //Ordenação por endereço
    insetionAddressSort(address, index, n);

    for (int i = 0; i < 6; i++)
    {
        std::cout << header[i] << std::endl;
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cout << names[index[i]] << "," << cpf[index[i]] << "," << address[index[i]] << "," << payload[index[i]] << std::endl;
    }
    
    delete[] names;
    delete[] cpf;
    delete[] address;
    delete[] payload;
    delete[] index;

    return 0;

}
