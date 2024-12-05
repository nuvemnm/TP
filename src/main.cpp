#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/functions.hpp"



int main(int argc, char *argv[]){

    std::ifstream arquivo(argv[1]);
   
    int n = readHeader(arquivo);


    std::string *name = new std::string[n];
    std::string *cpf = new std::string[n];
    std::string *address = new std::string[n];
    std::string *payload = new std::string[n];
    arquivo.seekg(0, std::ios::beg);

    loadArchive(name,cpf, address, payload, arquivo);

    ordenaNome(n, name, cpf, address, payload);
    

}
