#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "../include/functions.hpp"



int main(int argc, char *argv[]){

    using namespace std::chrono;
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

    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(names, index, n);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Selection Sort por Nome: " << duration<double>(end - start).count() << "ms\n" << std::endl;
     
    //printOutput(index, header, names, cpf, address, payload, n);

    //Ordenação por CPF
    initIndice(n, index);

    start = std::chrono::high_resolution_clock::now();
    selectionSort(cpf, index, n);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Selection Sort por CPF: " << duration<double>(end - start).count() << "ms\n" << std::endl;
    
    //printOutput(index, header, names, cpf, address, payload, n);

    //Ordenação por endereço
    initIndice(n, index);
    
    start = std::chrono::high_resolution_clock::now();
    selectionSort(address, index, n);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Selection Sort por Endereço: " << duration<double>(end - start).count() << "ms\n" << std::endl;
    
    //printOutput(index, header, names, cpf, address, payload, n);

    //=============================================================== QUICKSORT ===============================================================
    
    //Ordenação por nome
    initIndice(n, index);

    start = std::chrono::high_resolution_clock::now();
    quickSort(names, index, 0, n - 1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Quick Sort por Nome: " << duration<double>(end - start).count() << "ms\n" << std::endl;
    

    //printOutput(index, header, names, cpf, address, payload, n);
    
    //Ordenação por CPF
    initIndice(n, index);
    start = std::chrono::high_resolution_clock::now();
    quickSort(cpf, index, 0, n - 1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Quick Sort por CPF: " << duration<double>(end - start).count() << "ms\n" << std::endl;
    

    //printOutput(index, header, names, cpf, address, payload, n);

    //Ordenação por endereço
    initIndice(n, index);
    start = std::chrono::high_resolution_clock::now();
    quickSort(address, index, 0, n - 1);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Quick Sort por Endereço: " << duration<double>(end - start).count() << "ms\n" << std::endl;
    

    //printOutput(index, header, names, cpf, address, payload, n);

    //=============================================================== INSERTION SORT ===============================================================

    //Ordenação por nome
    initIndice(n, index);
    start = std::chrono::high_resolution_clock::now();
    insertionSort(names, index, n);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Insertion Sort por Nome: " << duration<double>(end - start).count() << "ms\n" << std::endl;
    

    //printOutput(index, header, names, cpf, address, payload, n);

   //Ordenação por CPF
    initIndice(n, index);
    start = std::chrono::high_resolution_clock::now();
    insertionSort(cpf, index, n);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Insertion Sort por CPF: " << duration<double>(end - start).count() << "ms\n" << std::endl;
    
    //printOutput(index, header, names, cpf, address, payload, n);
    
    //Ordenação por endereço
    initIndice(n, index);
    start = std::chrono::high_resolution_clock::now();
    insertionSort(address, index, n);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Insertion Sort por Endereço: " << duration<double>(end - start).count() << "ms\n" << std::endl;

    //printOutput(index, header, names, cpf, address, payload, n);
    
    delete[] names;
    delete[] cpf;
    delete[] address;
    delete[] payload;
    delete[] index;

    return 0;

}
