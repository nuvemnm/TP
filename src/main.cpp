#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <vector>
#include "../include/functions.hpp"


int main(int argc, char *argv[]){

    using namespace std::chrono;
    
    std::string archives[4] = {"cad.r1000.p1000.xcsv", "cad.r1000.p5000.xcsv", "cad.r5000.p1000.xcsv", "cad.r5000.p5000.xcsv"};
    std::string ordenados[4] = {"11ordenado.xcsv", "15ordenado.xcsv", "51ordenado.xcsv", "55ordenado.xcsv"};
    std::string inversos[4] = {"11inverso.xcsv", "15inverso.xcsv", "51inverso.xcsv", "55inverso.xcsv"};

    double * mergeTimes = new double[4];
    double * quickTimes = new double[4];
    double * shellTimes = new double[4];
    
    for(int i = 0; i < 4; i++){

        std::ifstream arquivo(archives[i]);

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

        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(names, index, 0, n - 1);
        auto end = std::chrono::high_resolution_clock::now();
        mergeTimes[i] = std::chrono::duration<double>(end - start).count();
        //std::cout << "Selection Sort por Nome: " << duration<double>(end - start).count() << "ms\n" << std::endl;
        //printOutput(index, header, names, cpf, address, payload, n);
        /*

        //Ordenação por CPF
        //initIndice(n, index);
        start = std::chrono::high_resolution_clock::now();
        mergeSort(cpf, index, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        //std::cout << "Selection Sort por CPF: " << duration<double>(end - start).count() << "ms\n" << std::endl;
        
        //printOutput(index, header, names, cpf, address, payload, n);

        //Ordenação por endereço
        initIndice(n, index);
        
        start = std::chrono::high_resolution_clock::now();
        mergeSort(address, index, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        */
        //std::cout << "Selection Sort por Endereço: " << duration<double>(end - start).count() << "ms\n" << std::endl;
        
        //printOutput(index, header, names, cpf, address, payload, n);

        //=============================================================== QUICKSORT ===============================================================
        
        //Ordenação por nome
        initIndice(n, index);

        start = std::chrono::high_resolution_clock::now();
        quickSort(names, index, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        quickTimes[i] = std::chrono::duration<double>(end - start).count();
        //std::cout << "Quick Sort por Nome: " << duration<double>(end - start).count() << "ms\n" << std::endl;
        /*
        

        //printOutput(index, header, names, cpf, address, payload, n);
        //Ordenação por CPF
        initIndice(n, index);
        start = std::chrono::high_resolution_clock::now();
        quickSort(cpf, index, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        //std::cout << "Quick Sort por CPF: " << duration<double>(end - start).count() << "ms\n" << std::endl;
        

        //printOutput(index, header, names, cpf, address, payload, n);

        //Ordenação por endereço
        initIndice(n, index);
        start = std::chrono::high_resolution_clock::now();
        quickSort(address, index, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();
        //std::cout << "Quick Sort por Endereço: " << duration<double>(end - start).count() << "ms\n" << std::endl;
        */
        

        //printOutput(index, header, names, cpf, address, payload, n);

        
        //=============================================================== SHELL SORT ===============================================================

        //Ordenação por nome
        initIndice(n, index);
        start = std::chrono::high_resolution_clock::now();
        shellSort(names, index, n);
        end = std::chrono::high_resolution_clock::now();
        shellTimes[i] = std::chrono::duration<double>(end - start).count();
        //std::cout << "Insertion Sort por Nome: " << duration<double>(end - start).count() << "ms\n" << std::endl;
        /*

        printOutput(index, header, names, cpf, address, payload, n);
        //Ordenação por CPF
        initIndice(n, index);
        start = std::chrono::high_resolution_clock::now();
        shellSort(cpf, index, n);
        end = std::chrono::high_resolution_clock::now();
        //std::cout << "Insertion Sort por CPF: " << duration<double>(end - start).count() << "ms\n" << std::endl;
        
        printOutput(index, header, names, cpf, address, payload, n);
        
        //Ordenação por endereço
        initIndice(n, index);
        start = std::chrono::high_resolution_clock::now();
        shellSort(address, index, n);
        end = std::chrono::high_resolution_clock::now();
        //std::cout << "Insertion Sort por Endereço: " << duration<double>(end - start).count() << "ms\n" << std::endl;

        printOutput(index, header, names, cpf, address, payload, n);
        */

        delete[] names;
        delete[] cpf;
        delete[] address;
        delete[] payload;
        delete[] index;
    }
    
    saveToCSV("tempos.csv", archives, mergeTimes, quickTimes, shellTimes);
    
    delete[] mergeTimes;
    delete[] quickTimes;
    delete[] shellTimes;


    return 0;

}
