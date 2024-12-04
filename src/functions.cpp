#include "functions.hpp"


void leArquivo(std::ifstream& arquivo, std:: string *array){
    // Verificar se o arquivo foi aberto com sucesso
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
        for (int j = 0; j < 6; j++) {
            std::cout << array[j] << "\n";
        }
        std::cout << std::endl;

        // Fechar o arquivo
        arquivo.close();

        return;
}