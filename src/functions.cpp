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

std::string extractValue(int field, std::string line){
    std::string nome;
    std::string cpf;
    std::string address;
    std::stringstream ss(line);
    switch (field){

        case 0:
        std::getline(ss, nome, ',');
        std::cout<<nome;
        return nome;
        break;

        case 1:
        std::getline(ss, nome, ',');
        std::getline(ss, cpf, ',');
        return cpf;
        break;

        case 2:
        std::getline(ss, nome, ',');
        std::getline(ss, cpf, ',');
        std::getline(ss, address, ',');
        return address;
        break;
    }
    return "error";
}



void selectionSort(int field, int numLines, std::string * string){
    for(int i = 0; i < numLines-1; i++){
        int menor = i;
        for(int j = i+1; j < numLines; j++){
            if(extractValue(field, string[j]) < extractValue(field, string[i])){
                menor = j;
            }
        }
        /*
        std::string aux = string[i];
        string[i] = string[menor];
        string[menor]  = aux; 
        */
        if(menor != i){
            std::swap(string[i], string[menor]);
        }
            
    }
    return;
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


void ordenaNome(std::ifstream& arquivo){
    // Verificar se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return;
    }

    //número de linhas
    int numLines = readHeader(arquivo);
    //vetor de strings com tamanho igual ao número de linhas
    std::string *array = new std::string[numLines];

    int count = 0;
    std::string line;
    // Ler linha por linha do arquivo
    while (std::getline(arquivo, line) && count < numLines) {   
        // Separar os campos por vírgula
        array[count++] = line;  
    }


    selectionSort(0, numLines, array);
    // Exibir os campos lidos
    /*
    for (int j = 0; j < (numLines - 996); j++) {
        std::cout << array[j] << "\n";
    }
    */

    delete[] array;
    // Fechar o arquivo
    arquivo.close();

    return;
  
}



void initIndice(int n, int indice[]){
    
    for(int i = 0; i < n; i++){
        indice[i] = i;
    }
}


