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

void swap(int* index1, int* index2) {
    int* temp = index1;
    index1 = index2;
    index2 = temp;
}



void initIndice(int n, int indice[]){
    
    for(int i = 0; i < n; i++){
        indice[i] = i;
    }
}

void selectionSort(int numLines, std::string string[], int index[]){
    for(int i = 0; i < numLines-1; i++){
        int minor = i;
        for(int j = i+1; j < numLines; j++){
            if(string[index[j]] < string[index[i]]){
                minor = j;
            }
        }
        if(minor != i){
            swap(&index[i], &index[minor]);
        }
            
    }
    return;
}

void loadArchive(std::string * names, std::string * cpf, std::string * address, std::string * payload, std::ifstream& archive){
    
    std::string line;
    std::string header;

    for(int i = 0; i < 6; i++){
        getline(archive, header);
    }

    int j = 0;
    int position = 0;
    while(getline(archive, line)){

        position = line.find(',');
        names[j] = line.substr(0, position);
        line = line.substr(position + 1, line.length());

        position = line.find(',');
        cpf[j] = line.substr(0, position);
        line = line.substr(position + 1, line.length());

        position = line.find(',');
        address[j] = line.substr(0, position);
        line = line.substr(position + 1, line.length());

        position = line.find(',');
        payload[j] = line.substr(0, position);
        line = line.substr(position + 1, line.length());

        j++;
    }
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


void ordenaNome(int numLines, std::string * names, std::string * cpf, std::string * address, std::string * payload){
    
    int *index = new int[numLines];
    initIndice(numLines, index);
    selectionSort(numLines, names, index);


    for (int i = 0; i < 4; i++)
    {
        std::cout << names[index[i]] << "," << cpf[index[i]] << "," << address[index[i]] << "," << payload[index[i]] << std::endl;
    }

}





