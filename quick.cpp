#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "../include/carregaArquivo.hpp"
#include "../include/quicksort.hpp"
#include "../include/insertion.hpp"
#include "../include/selection.hpp"
#include "../include/swap.hpp"

void inicializaIndices(int n, int indices[])
{
    for (int i = 0; i < n; i++)
    {
        indices[i] = i;
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Uso: " << argv[0] << " <nome_do_arquivo>" << std::endl;
        return 1;
    }

    std::ifstream arquivo(argv[1]);
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo " << argv[1] << std::endl;
        return 1;
    }
    std::string linha = "", nlinhas = "", cabecalho[6];

    for (int j = 0; j < 6; j++)
    {
        getline(arquivo, nlinhas);
        cabecalho[j] = nlinhas;
    }

    int n = std::stoi(nlinhas);

    std::string *nomes = new std::string[n];
    std::string *ids = new std::string[n];
    std::string *enderecos = new std::string[n];
    std::string *payloads = new std::string[n];

    arquivo.clear();                 // Limpar flags de erro
    arquivo.seekg(0, std::ios::beg); // Mover o ponteiro de leitura para o início do arquivo

    carregaArquivo(nomes, ids, enderecos, payloads, arquivo);

    // auto comecoGeral = std::chrono::high_resolution_clock::now();
    // auto comecoSS = std::chrono::high_resolution_clock::now();

    int *indices = new int[n];

    // std::cout << "SELECTION SORT" << std::endl << std::endl;

    // Selection sort
    // Ordenado por nome
    inicializaIndices(n, indices);
    selectionsort(0, n - 1, nomes, indices);

    for (int i = 0; i < 6; i++)
    {
        std::cout << cabecalho[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << nomes[indices[i]] << "," << ids[indices[i]] << "," << enderecos[indices[i]] << "," << payloads[indices[i]] << std::endl;
    }

    // Ordenado por id
    inicializaIndices(n, indices);
    selectionsort(0, n - 1, ids, indices);

    for (int i = 0; i < 6; i++)
    {
        std::cout << cabecalho[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << nomes[indices[i]] << "," << ids[indices[i]] << "," << enderecos[indices[i]] << "," << payloads[indices[i]] << std::endl;
    }

    // Ordenado por endereço
    inicializaIndices(n, indices);
    selectionsort(0, n - 1, enderecos, indices);

    for (int i = 0; i < 6; i++)
    {
        std::cout << cabecalho[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << nomes[indices[i]] << "," << ids[indices[i]] << "," << enderecos[indices[i]] << "," << payloads[indices[i]] << std::endl;
    }

    // std::cout << std::endl << "INSERTION SORT" << std::endl << std::endl;

    // auto fimSS = std::chrono::high_resolution_clock::now();
    // auto comecoIS = std::chrono::high_resolution_clock::now();

    // Insertion sort
    // Ordenado por nome
    inicializaIndices(n, indices);
    insertionsort(0, n - 1, nomes, indices);

    for (int i = 0; i < 6; i++)
    {
        std::cout << cabecalho[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << nomes[indices[i]] << "," << ids[indices[i]] << "," << enderecos[indices[i]] << "," << payloads[indices[i]] << std::endl;
    }

    // Ordenado por id
    inicializaIndices(n, indices);
    insertionsort(0, n - 1, ids, indices);

    for (int i = 0; i < 6; i++)
    {
        std::cout << cabecalho[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << nomes[indices[i]] << "," << ids[indices[i]] << "," << enderecos[indices[i]] << "," << payloads[indices[i]] << std::endl;
    }

    // Ordenado por endereço
    inicializaIndices(n, indices);
    insertionsort(0, n - 1, enderecos, indices);

    for (int i = 0; i < 6; i++)
    {
        std::cout << cabecalho[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << nomes[indices[i]] << "," << ids[indices[i]] << "," << enderecos[indices[i]] << "," << payloads[indices[i]] << std::endl;
    }

    // std::cout << std::endl << "QUICK SORT" << std::endl << std::endl;

    // auto fimIS = std::chrono::high_resolution_clock::now();
    // auto comecoQS = std::chrono::high_resolution_clock::now();

    // Quick sort
    // Ordenado por nome
    inicializaIndices(n, indices);
    quicksort(0, n - 1, nomes, indices);

    for (int i = 0; i < 6; i++)
    {
        std::cout << cabecalho[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << nomes[indices[i]] << "," << ids[indices[i]] << "," << enderecos[indices[i]] << "," << payloads[indices[i]] << std::endl;
    }

    // //Ordenado por id
    inicializaIndices(n, indices);
    quicksort(0, n - 1, ids, indices);

    for (int i = 0; i < 6; i++)
    {
        std::cout << cabecalho[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << nomes[indices[i]] << "," << ids[indices[i]] << "," << enderecos[indices[i]] << "," << payloads[indices[i]] << std::endl;
    }

    // Ordenado por endereço
    inicializaIndices(n, indices);
    quicksort(0, n - 1, enderecos, indices);

    for (int i = 0; i < 6; i++)
    {
        std::cout << cabecalho[i] << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << nomes[indices[i]] << "," << ids[indices[i]] << "," << enderecos[indices[i]] << "," << payloads[indices[i]] << std::endl;
    }

    // auto fimQS = std::chrono::high_resolution_clock::now();
    // auto fimGeral = std::chrono::high_resolution_clock::now();

    // std::cout << std::endl << "TEMPOS" << std::endl << std::endl;

    // std::cout << "Selection Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(fimSS - comecoSS).count() << "ns" << std::endl;

    // std::cout << "Insertion Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(fimIS - comecoIS).count() << "ns" << std::endl;

    // std::cout << "Quick Sort: " << std::chrono::duration_cast<std::chrono::nanoseconds>(fimQS - comecoQS).count() << "ns" << std::endl;

    // std::cout << "Tempo total: " << std::chrono::duration_cast<std::chrono::nanoseconds>(fimGeral - comecoGeral).count() << "ns" << std::endl;

    delete[] nomes;
    delete[] ids;
    delete[] enderecos;
    delete[] payloads;

    return 0;
}