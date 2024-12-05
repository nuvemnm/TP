#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/functions.hpp"



int main(int argc, char *argv[]){

    std::ifstream arquivo(argv[1]);
   
    ordenaNome(arquivo);

}
