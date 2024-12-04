#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "functions.hpp"



int main(){
    std::ifstream file1("cad.r1000.p1000.xcsv");
    std::ifstream file2("cad.r1000.p5000.xcsv");
    std::ifstream file3("cad.r5000.p1000.xcsv");
    std::ifstream file4("cad.r5000.p5000.xcsv");


    std::string *fields1 = new std::string[1000];
    std::string *fields2 = new std::string[5000];

    leArquivo(file3, fields2);

}
