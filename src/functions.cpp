#include "../include/functions.hpp"

//Le o arquivo e retorna o seu número de linhas úteis
int readHeader(std::ifstream& arquivo){
    std::string lines;
    std::string header[6];
    
    for(int i = 0; i < 6; i++){
        std::getline(arquivo, lines);
        header[i] = lines;
    }

    int n = std::stoi(lines);
    return n;
}

//Le o arquivo e printa as linhas indicadas na função
void leArquivo(std::ifstream& arquivo){
    // Verificar se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    std::string line;
    //número de linhas
    int numLines = readHeader(arquivo);
    //vetor de strings com tamanho igual ao número de linhas
    std::string *array = new std::string[numLines];

    int count = 0;
    // Ler linha por linha do arquivo
    while (std::getline(arquivo, line)) {
        //std::stringstream ss(line);    
        // Separar os campos por vírgula
        if(count < numLines){
            array[count++] = line;
        }else{
            break;
        }
        
    }

    // Exibir os campos lidos
    for (int j = 0; j < (numLines - 999); j++) {
        std::cout << array[j] << "\n";
    }
    std::cout << std::endl;

    // Fechar o arquivo
    arquivo.close();

    return;
}
/*
void ordenaNome(std::ifstream& arquivo, std::string *array){
 
    if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo!" << std::endl;
            return;
        }

        std::string line;

        int count = 0;
        // Ler linha por linha do arquivo
        while (std::getline(arquivo, line)) {
            //std::stringstream ss(line);    
            // Separar os campos por vírgula
            if(count < 1000){
                array[count++] = line;
            }else{
                break;
            }
            
        }

        // Exibir os campos lidos
        for (int j = 6; j < 10; j++) {
            std::cout << array[j] << "\n";
        }
        std::cout << std::endl;

        // Fechar o arquivo
        arquivo.close();

        return;
}

*/


void initIndice(int n, int indice[]){
    
    for(int i = 0; i < n; i++){
        indice[i] = i;
    }
}
